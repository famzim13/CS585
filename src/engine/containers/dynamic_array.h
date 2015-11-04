// dynamic_array.h
#ifndef INCLUDED_DYNAMIC_ARRAY
#define INCLDUED_DYNAMIC_ARRAY
#pragma once

#include "../memory/default_allocator.h"
#include <iostream>
#include <stdexcept>
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

    unsigned int d_length;
      // Number of elements in the array.
    
    // MEMBER FUNCTIONS
    void grow();
      // Increase the capacity of the array when a threshold is met.

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

    unsigned int getLength() const;
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
    return stream << "{ length : " << array.getLength() <<
       ", capacity : " << array.getCapacity() << " }";
}

// CONSTRUCTORS
template <class T>
DynamicArray<T>::DynamicArray()
{
    sgdm::DefaultAllocator<T> defaultAlloc = sgdm::DefaultAllocator<T>();
    d_alloc = &defaultAlloc;
    d_array = d_alloc->get( DEFAULT_CAPACITY );
    d_capacity = DEFAULT_CAPACITY;
    d_length = 0;  
}

template <class T>
DynamicArray<T>::DynamicArray( sgdm::IAllocator<T>* alloc )
{
    d_alloc = alloc;
    d_array = d_alloc->get( DEFAULT_CAPACITY );
    d_capacity = DEFAULT_CAPACITY;
    d_length = 0;  
}

template <class T>
DynamicArray<T>::DynamicArray( DynamicArray<T>& copy )
{
    d_alloc( new sgdm::IAllocator<T>( *copy.d_alloc ) );
    d_array = d_alloc->get( copy.d_capacity );
    *d_array = *copy.d_array;
    d_capacity = copy.d_capacity;
    d_length = copy.d_length;
}

template <class T>
DynamicArray<T>::DynamicArray( DynamicArray<T>&& move )
{
    d_alloc = std::move( move.d_alloc );
    d_array = std::move( move.d_array );
    d_capacity = move.d_capacity;
    d_length = move.d_length;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=( const DynamicArray<T>& rhs )
{
    if( this != &rhs )
    {
      d_alloc->deallocate( d_array, d_capacity );
      d_alloc( new sgdm::IAllocator<T>( *rhs.d_alloc ) );
      d_array = d_alloc->get( rhs.d_capacity );
      *d_array = *rhs.d_array;
      d_capacity = rhs.d_capacity;
      d_length = rhs.d_length;
    }
    return *this;
}

// DESTRUCTORS
template <class T>
DynamicArray<T>::~DynamicArray<T>()
{
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
    if( index < 0 || index >= d_length )
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
unsigned int DynamicArray<T>::getLength() const
{
    return d_length;
}

// MUTATORS
template <class T>
T& DynamicArray<T>::operator[]( int i )
{
    return d_array[i];
}

template <class T>
void DynamicArray<T>::insertAt( unsigned int index, const T& element )
{
    if( index < 0 || index >= d_capacity )
    {
      throw std::out_of_range( "Index out of range" );
    }

    if( d_length == d_capacity )
    {
      grow();
    }

    memmove( &d_array[index + 1], &d_array[index], (d_length-index)*sizeof(T) );
    d_array[index] = element;
    d_length++;
}

template <class T>
T DynamicArray<T>::pop()
{
    T popElement = d_array[d_length-1];
    d_array[d_length-1] = 0;
    d_length--;

    if( d_length < d_capacity * SHRINK_THRESHOLD && d_capacity > MINIMUM_CAPACITY)
    {
      shrink();
    }

    return popElement;
}

template <class T>
T DynamicArray<T>::popFront()
{
    T popElement = d_array[0];
    memmove( &d_array[0], &d_array[1], d_length*sizeof(T) );
    d_length--;

    if( d_length < d_capacity * SHRINK_THRESHOLD && d_capacity > MINIMUM_CAPACITY)
    {
      shrink();
    }

    return popElement;
}

template <class T>
void DynamicArray<T>::push( const T& element )
{
    if( d_length == d_capacity )
    {
      grow();
    }

    d_array[d_length] = element;
    d_length++;
}

template <class T>
void DynamicArray<T>::pushFront( const T& element )
{
    if( d_length == d_capacity )
    {
      grow();
    }

    memmove( &d_array[1], &d_array[0], d_length*sizeof(T) );
    d_array[0] = element;
    d_length++;
}

template <class T>
T DynamicArray<T>::removeAt( unsigned int index )
{
    if( index < 0 || index >= d_length )
    {
      throw std::out_of_range( "Index out of range" );
    }

    memmove( &d_array[index], &d_array[index+1], (d_length-index)*sizeof(T) );
    d_length--;

    if( d_length < d_capacity * SHRINK_THRESHOLD && d_capacity > MINIMUM_CAPACITY)
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
    std::copy( d_array, &d_array[d_length], growArray );
    d_alloc->release( d_array, d_capacity );
    d_array = growArray;
    d_capacity = growCapacity;
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
    std::copy( d_array, &d_array[d_length], shrinkArray );
    d_alloc->release( d_array, d_capacity );
    d_array = shrinkArray;
    d_capacity = shrinkCapacity;
}

} // end namespace sgdc

} // end namespace StevensDev

#endif
