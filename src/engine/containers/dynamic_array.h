// dynamic_array.h
#ifndef INCLUDED_DYNAMIC_ARRAY
#define INCLDUED_DYNAMIC_ARRAY
#pragma once

#include "../memory/default_allocator.h"
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string.h>
#include <utility>

namespace StevensDev
{

namespace sgdc
{

#define DEFAULT_CAPACITY 3
#define GOLDEN_RATIO 1.618
#define MINIMUM_CAPACITY 3

template <class T>
class DynamicArray
{
  private:
    sgdm::IAllocator<T>* d_alloc;
      // Allocator that the array uses.

    sgdm::IAllocator<bool>* d_initAlloc;
      // Allocator for the initialized array.

    T* d_array;
      // Internal array of the dynamic array.

    bool* d_init;
      // Array which tracks whether or not a construction needs to occur.

    unsigned int d_capacity;
      // Maximum number of elements possible in the array.

    unsigned int d_last_index;
      // The furthest set index in the array.

    // MEMBER FUNCTIONS
    void grow();
      // Increase the capacity of the array when a threshold is met.

    void moveLastIndex( int i );
      // Checks if the last index needs to be moved, moves it if so.

  public:
    // CONSTRUCTORS
    DynamicArray();
      // Default constructor using default allocator.

    DynamicArray( sgdm::IAllocator<T>* alloc );
      // Constructor using an allocator.

    DynamicArray( unsigned int capacity );
      // Constructor with an initiale capacity.

    DynamicArray( const DynamicArray<T>& copy );
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
    d_initAlloc = new sgdm::DefaultAllocator<bool>();
    d_init = d_initAlloc->get( DEFAULT_CAPACITY );
    d_capacity = DEFAULT_CAPACITY;
    d_last_index = 0;
}

template <class T>
DynamicArray<T>::DynamicArray( sgdm::IAllocator<T>* alloc )
{
    d_alloc = alloc;
    d_array = d_alloc->get( DEFAULT_CAPACITY );
    d_initAlloc = new sgdm::DefaultAllocator<bool>();
    d_init = d_initAlloc->get( DEFAULT_CAPACITY );
    d_capacity = DEFAULT_CAPACITY;
    d_last_index = 0;
}

template <class T>
DynamicArray<T>::DynamicArray( unsigned int capacity)
{
    d_alloc = new sgdm::DefaultAllocator<T>();
    d_array = d_alloc->get( capacity );
    d_initAlloc = new sgdm::DefaultAllocator<bool>();
    d_init = d_initAlloc->get( DEFAULT_CAPACITY );
    d_capacity = capacity;
    d_last_index = 0;
}

template <class T>
DynamicArray<T>::DynamicArray( const DynamicArray<T>& copy )
{
    d_alloc = new sgdm::DefaultAllocator<T>();
    *d_alloc = *copy.d_alloc;
    d_array = d_alloc->get( copy.d_capacity );
    *d_array = *copy.d_array;
    d_initAlloc = new sgdm::DefaultAllocator<bool>();
    *d_initAlloc = *copy.d_initAlloc;
    d_init = d_initAlloc->get( copy.d_capacity );
    *d_init = *copy.d_init;
    d_capacity = copy.d_capacity;
    d_last_index = copy.d_last_index;
}

template <class T>
DynamicArray<T>::DynamicArray( DynamicArray<T>&& move )
{
    d_alloc = std::move( move.d_alloc );
    d_array = std::move( move.d_array );
    d_initAlloc = std::move( move.d_initAlloc );
    d_init = std::move( move.d_init );
    d_capacity = move.d_capacity;
    d_last_index = move.d_last_index;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=( const DynamicArray<T>& rhs )
{
    if( this != &rhs )
    {
      d_alloc->release( d_array, rhs.d_capacity );
      d_alloc = rhs.d_alloc;
      d_array = d_alloc->get( rhs.d_capacity );
      *d_array = *rhs.d_array;
      d_initAlloc = rhs.d_initAlloc;
      d_init = d_initAlloc->get( rhs.d_capacity );
      *d_init = *rhs.d_init;
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
      if( d_init[i] )
      {
        d_alloc->destruct( &d_array[i] );
        d_initAlloc->destruct( &d_init[i] );
      }
    }
    d_alloc->release( d_array, d_capacity );
    d_initAlloc->release( d_init, d_capacity );
    delete d_alloc;
    delete d_initAlloc;
}

// ACCESSORS
template <class T>
const T& DynamicArray<T>::operator[]( int i ) const
{
    if( !d_init[i] )
    {
      d_init[i] = true;
      d_alloc->construct( &d_array[index], T() );
    }

    return d_array[i];
}

template <class T>
T DynamicArray<T>::at( unsigned int index ) const
{
    if( index < 0 || index >= d_capacity )
    {
      throw std::out_of_range( "Index out of range" );
    }

    if( !d_init[index] )
    {
      d_init[index] = true;
      d_alloc->construct( &d_array[index], T() );
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
    if( !d_init[i] )
    {
      d_init[i] = true;
      d_alloc->construct( &d_array[i], T() );
    }
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
    memmove( &d_init[index + 1], &d_init[index], (d_last_index-index)*sizeof(bool) );
    d_alloc->construct( &d_array[index], element );
    d_init[index] = true;
}

template <class T>
T DynamicArray<T>::pop()
{
    T popElement;
    if( d_init[d_last_index-1] )
    {
      popElement = d_array[d_last_index-1];
      d_alloc->destruct( &d_array[d_last_index-1] );
      d_init[d_last_index-1] = false;
      d_last_index--;
    }

    return popElement;
}

template <class T>
T DynamicArray<T>::popFront()
{
    T popElement;
    if( d_init[0] )
    {
      popElement = d_array[0];
      d_alloc->destruct( &d_array[0] );
      memmove( &d_array[0], &d_array[1], d_last_index*sizeof(T) );
      memmove( &d_init[0], &d_init[1], d_last_index*sizeof(bool) );
      d_last_index--;
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

    d_alloc->construct( &d_array[d_last_index], element );
    d_init[d_last_index] = true;
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
    d_alloc->construct( &d_array[0], element );
    memmove( &d_init[1], &d_init[0], d_last_index*sizeof(bool) );
    d_init[0] = true;
    d_last_index++;
}

template <class T>
T DynamicArray<T>::removeAt( unsigned int index )
{
    if( index < 0 || index >= d_last_index )
    {
      throw std::out_of_range( "Index out of range" );
    }

    if( d_init[index] )
    {
      d_alloc->destruct( &d_array[index] );
      memmove( &d_array[index], &d_array[index+1], (d_last_index-index)*sizeof(T) );
      memmove( &d_init[index], &d_init[index+1], (d_last_index-index)*sizeof(bool) );
      d_last_index--;
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
    bool* growInit = d_initAlloc->get( growCapacity );
    memmove( &growInit[0], &d_init[0], d_last_index*sizeof(bool) );
    d_initAlloc->release( d_init, d_capacity );
    d_init = growInit;
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

} // end namespace sgdc

} // end namespace StevensDev

#endif
