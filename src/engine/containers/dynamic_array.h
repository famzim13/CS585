// dynamic_array.h
#ifndef INCLUDED_DYNAMIC_ARRAY
#define INCLDUED_DYNAMIC_ARRAY
#pragma once

#include "../memory/default_allocator.h"
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <utility>

namespace StevensDev
{

namespace sgdc
{

#define DEFAULT_CAPACITY 3
#define GOLDEN_RATIO 1.618
#define MINIMUM_CAPACITY 3
#define SHRINK_RATIO .5
#define SHRINK_THRESHOLD .33

template <class T>
class DynamicArray
{
  private:
    sgdm::IAllocator<T>* d_alloc;
      // Allocator that the array uses.

    T* d_array;
      // Internal array of the dynamic array.

    unsigned int d_capacity;
      // Maximum number of elements possible in the array.

    unsigned int d_last_index;
      // The furthest set index in the array.

    // MEMBER FUNCTIONS
    void grow();
      // Increase the capacity of the array when a threshold is met.

    void moveLastIndex( int i );
      // Checks if the last index needs to be moved, moves it if so.

    void shrink();
      // Decrease the capacity of the array when a threshold is met.

  public:
    // CONSTRUCTORS
    DynamicArray();
      // Default constructor using default allocator.

    DynamicArray( sgdm::IAllocator<T>* alloc );
      // Constructor using an allocator.

    DynamicArray( DynamicArray<T>& copy );
      // Copy constructor.

    DynamicArray( DynamicArray<T>&& move );
      // Move constructor.

    DynamicArray<T>& operator=( const DynamicArray<T>& rhs );
      // Copy assignment operator.

    // DESTRUCTORS
    ~DynamicArray();
      // Default destructor.

    // ACCESSORS
    const T& operator[]( int i ) const;
      // Gets an element, undefined if out of bounds.

    T at( unsigned int index ) const;
      // Gets an element, throws if out of bounds.

    unsigned int getCapacity() const;
      // Returns capacity of the array.

    unsigned int getLastIndex() const;
      // Returns number of elements contained.

    // MUTATORS
    T& operator[]( int i );
      // Sets an element, undefined if out of bounds.

    void insertAt( unsigned int index, const T& element );
      // Insert an element, throws error if out of bounds, may grow and shift.

    T pop();
      // Pops the last element and may shrink the array.

    T popFront();
      // Pops the first element, shifts and may shrink the array.

    void push( const T& element );
      // Adds element to back and may grow the array.

    void pushFront( const T& element );
      // Adds element to front, shifts and may grow the array.

    T removeAt( unsigned int index );
      // Removes element, throws error if out of bounds, may shring and shift.
};

// FREE OPERATORS
template <class T>
std::ostream& operator<<( std::ostream& stream, const DynamicArray<T>& array )
{
    return stream << "{ last_index : " << array.getLastIndex() <<
       ", capacity : " << array.getCapacity() << " }";
}

// CONSTRUCTORS
template <class T>
DynamicArray<T>::DynamicArray()
{
    d_alloc = new sgdm::DefaultAllocator<T>();
    d_array = d_alloc->get( DEFAULT_CAPACITY );
    d_capacity = DEFAULT_CAPACITY;
    d_last_index = 0;
}

template <class T>
DynamicArray<T>::DynamicArray( sgdm::IAllocator<T>* alloc )
{
    d_alloc = alloc;
    d_array = d_alloc->get( DEFAULT_CAPACITY );
    d_capacity = DEFAULT_CAPACITY;
    d_last_index = 0;
}

template <class T>
DynamicArray<T>::DynamicArray( DynamicArray<T>& copy )
{
    d_alloc = new sgdm::DefaultAllocator<T>();
    *d_alloc = *copy.d_alloc;
    d_array = d_alloc->get( copy.d_capacity );
    *d_array = *copy.d_array;
    d_capacity = copy.d_capacity;
    d_last_index = copy.d_last_index;
}

template <class T>
DynamicArray<T>::DynamicArray( DynamicArray<T>&& move )
{
    d_alloc = std::move( move.d_alloc );
    d_array = std::move( move.d_array );
    d_capacity = move.d_capacity;
    d_last_index = move.d_last_index;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=( const DynamicArray<T>& rhs )
{
    if( this != &rhs )
    {
      d_alloc->deallocate( d_array, d_capacity );
      d_alloc( sgdm::IAllocator<T>( *rhs.d_alloc ) );
      d_array = d_alloc->get( rhs.d_capacity );
      *d_array = *rhs.d_array;
      d_capacity = rhs.d_capacity;
      d_last_index = rhs.d_last_index;
    }
    return *this;
}

// DESTRUCTORS
template <class T>
DynamicArray<T>::~DynamicArray<T>()
{
    for( int i=0; i < d_capacity; i++ )
    {
      d_alloc->destruct( &d_array[i] );
    }
    d_alloc->release( d_array, d_capacity );
}

// ACCESSORS
template <class T>
const T& DynamicArray<T>::operator[]( int i ) const
{
    return d_array[i];
}

template <class T>
T DynamicArray<T>::at( unsigned int index ) const
{
    if( index < 0 || index >= d_capacity )
    {
      throw std::out_of_range( "Index out of range" );
    }

    return d_array[index];
}

template <class T>
unsigned int DynamicArray<T>::getCapacity() const
{
    return d_capacity;
}

template <class T>
unsigned int DynamicArray<T>::getLastIndex() const
{
    return d_last_index;
}

// MUTATORS
template <class T>
T& DynamicArray<T>::operator[]( int i )
{
    moveLastIndex( i );
    return d_array[i];
}

template <class T>
void DynamicArray<T>::insertAt( unsigned int index, const T& element )
{
    if( index < 0 || index >= d_capacity )
    {
      throw std::out_of_range( "Index out of range" );
    }

    moveLastIndex( index );
    if( d_last_index-index == d_capacity )
    {
      grow();
    }

    memmove( &d_array[index + 1], &d_array[index], (d_last_index-index)*sizeof(T) );
    d_array[index] = element;
}

template <class T>
T DynamicArray<T>::pop()
{
    T popElement = d_array[d_last_index-1];
    d_alloc->destruct( d_array[d_last_index-1] );
    d_last_index--;

    if( d_last_index < d_capacity * SHRINK_THRESHOLD
        && d_capacity > MINIMUM_CAPACITY)
    {
      shrink();
    }

    return popElement;
}

template <class T>
T DynamicArray<T>::popFront()
{
    T popElement = d_array[0];
    d_alloc->destruct( d_array[0] );
    memmove( &d_array[0], &d_array[1], d_last_index*sizeof(T) );
    d_last_index--;

    if( d_last_index < d_capacity * SHRINK_THRESHOLD
        && d_capacity > MINIMUM_CAPACITY)
    {
      shrink();
    }

    return popElement;
}

template <class T>
void DynamicArray<T>::push( const T& element )
{
    if( d_last_index == d_capacity )
    {
      grow();
    }

    d_array[d_last_index] = element;
    d_last_index++;
}

template <class T>
void DynamicArray<T>::pushFront( const T& element )
{
    if( d_last_index == d_capacity )
    {
      grow();
    }

    memmove( &d_array[1], &d_array[0], d_last_index*sizeof(T) );
    d_array[0] = element;
    d_last_index++;
}

template <class T>
T DynamicArray<T>::removeAt( unsigned int index )
{
    if( index < 0 || index >= d_last_index )
    {
      throw std::out_of_range( "Index out of range" );
    }

    d_alloc->destruct( d_array[index] );
    memmove( &d_array[index], &d_array[index+1], (d_last_index-index)*sizeof(T) );
    d_last_index--;

    if( d_last_index < d_capacity * SHRINK_THRESHOLD
        && d_capacity > MINIMUM_CAPACITY)
    {
      shrink();
    }
}

// MEMBER FUNCTIONS
template <class T>
void DynamicArray<T>::grow()
{
    unsigned int growCapacity = (unsigned int)d_capacity * GOLDEN_RATIO;
    T* growArray = d_alloc->get( growCapacity );
    memmove( &growArray[0], &d_array[0], d_last_index*sizeof(T) );
    d_alloc->release( d_array, d_capacity );
    d_array = growArray;
    d_capacity = growCapacity;
}

template <class T>
void DynamicArray<T>::moveLastIndex( int i )
{
    if( i > d_last_index && i < d_capacity && i >= 0 )
    {
      d_last_index = i;
    }
}

template <class T>
void DynamicArray<T>::shrink()
{
    unsigned int shrinkCapacity = (unsigned int)d_capacity * SHRINK_RATIO;
    if( shrinkCapacity < MINIMUM_CAPACITY )
    {
      shrinkCapacity = MINIMUM_CAPACITY;
    }

    T* shrinkArray = d_alloc->get( shrinkCapacity );
    std::copy( d_array, &d_array[d_last_index], shrinkArray );
    d_alloc->release( d_array, d_capacity );
    d_array = shrinkArray;
    d_capacity = shrinkCapacity;
}

} // end namespace sgdc

} // end namespace StevensDev

#endif
