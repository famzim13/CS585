// dynamic_array.h
#ifndef INCLUDED_DYNAMIC_ARRAY
#define INCLUDED_DYNAMIC_ARRAY

#include <iostream>
#include "../memory/default_allocator.h"
#include <stdexcept>
#include "string.h"

#define DEFAULT_CAPACITY 3
#define GOLDEN_RATIO 1.618
#define MINIMUM_CAPACITY 3
#define SHRINK_RATIO .5
#define SHRINK_THRESHOLD .33

namespace StevensDev
{

namespace sgdc
{

template <class T>
class DynamicArray
{
  private:
    sgdm::IAllocator<T>* d_alloc;
      // Memory allocator.
    T* d_array;
      // Internal array.
    unsigned int d_capacity;
      // Current capacity of the array.
    unsigned int d_length;
      // Current length of the array.
    void grow();
      // Grows array.
    void shrink();
      // Shrinks array.

  public:
    //CONSTRUCTORS
    DynamicArray();
      // Default constructor.
    DynamicArray( sgdm::IAllocator<T>* alloc );
      // Constructor with pointer to allocator.

    // DESTRUCTORS
    ~DynamicArray();
      // Default destructor.

    // ACCESSORS
    T at( unsigned int index ) const;
      // Get element at index, throws if out of bounds.
    unsigned int getCapacity() const;
      // Get capacity of array.
    unsigned int getLength() const;
      // Get length of array.
    T operator[]( int i ) const;
      // Get element at index i, undefined behavior if out of bounds.

    // MUTATORS
    void push( const T& element );
      // Add element to end of array, grow array if needed.
    void pushFront( T element );
      // Add element to front of array, shift elements, grow array if needed.
    T pop();
      // Retrieve and remove the last element, shifts array.
    T popFront();
      // Retrieve and remove the first element, shifts array.
    T& operator[]( int i );
      // Sets element at index i, undefined behavior if out of bounds.
    void removeAt( unsigned int index );
      // Removes the element at the specified index, throws if invalid, array may shrink.
    void insertAt( unsigned int index, const T& element );
      // Inserts element at specified index, array may grow, shifts array.
};

// FREE OPERATORS
template <class T> inline
std::ostream& operator<<( std::ostream& stream, const DynamicArray<T>& array )
{
    return stream << "{ length : " << array.getLength() <<
       ", capacity : " << array.getCapacity() << " }";
}

// CONSTRUCTORS
template <class T> inline
DynamicArray<T>::DynamicArray()
{
}

template <class T> inline
DynamicArray<T>::DynamicArray( sgdm::IAllocator<T>* alloc )
{
    d_alloc = alloc;
    d_capacity = DEFAULT_CAPACITY;
    d_array = d_alloc->get( d_capacity );
    d_length = 0;
}

// DESTRUCTORS
template <class T> inline
DynamicArray<T>::~DynamicArray()
{
    d_alloc->release( d_array, d_capacity );
}

// ACCESSORS
template <class T> inline
T DynamicArray<T>::at( unsigned int index ) const
{
    if( index < 0 || index >= d_length )
      throw std::out_of_range( "Index out of range" );
    
    return d_array[index];
}

template <class T> inline
unsigned int DynamicArray<T>::getCapacity() const
{
    return d_capacity;
}

template <class T> inline
unsigned int DynamicArray<T>::getLength() const
{
    return d_length;
}

template <class T> inline
T DynamicArray<T>::operator[]( int i ) const
{
    return d_array[i];
}

// MUTATORS
template <class T> inline
void DynamicArray<T>::push( const T& element )
{
    if( d_length == d_capacity )
      grow();

    d_array[d_length] = element;
    d_length++;
}

template <class T> inline
void DynamicArray<T>::pushFront( T element )
{
    if( d_length == d_capacity )
      grow();

    memmove( &d_array[1], &d_array[0], d_length*sizeof(T) );
    d_array[0] = element;
    d_length++;
}

template <class T> inline
T DynamicArray<T>::pop()
{
    T popElement = d_array[d_length-1];
    d_array[d_length-1] = 0;
    d_length--;
    
    return popElement;
}

template <class T> inline
T DynamicArray<T>::popFront()
{
    T popElement = d_array[0];
    memmove( &d_array[0], &d_array[1], d_length*sizeof(T) );
    d_length--;

    return popElement;
}

template <class T> inline
T& DynamicArray<T>::operator[]( int i )
{
    return d_array[i];
}

template <class T> inline
void DynamicArray<T>::removeAt( unsigned int index )
{
    if( index < 0 || index >= d_length )
      throw std::out_of_range( "Index out of range" );

    memmove( &d_array[index], &d_array[index+1], (d_length-index)*sizeof(T) );
    d_length--;

    if( d_length < d_capacity * SHRINK_THRESHOLD && d_capacity > MINIMUM_CAPACITY)
      shrink();
}

template <class T> inline
void DynamicArray<T>::insertAt( unsigned int index, const T& element )
{
    if( index < 0 || index >= d_capacity )
      throw std::out_of_range( "Index out of range" );
    if( d_length == d_capacity )
      grow();

    memmove( &d_array[index + 1], &d_array[index], (d_length-index)*sizeof(T) );
    d_array[index] = element;
    d_length++;
}

// MEMBER FUNCTIONS
template <class T> inline
void DynamicArray<T>::grow()
{
    unsigned int growCapacity = (unsigned int)d_capacity * GOLDEN_RATIO;
    T* growArray = d_alloc->get( growCapacity );
    std::copy( d_array, &d_array[d_length], growArray );
    d_alloc->release( d_array, d_capacity );
    d_array = growArray;
    d_capacity = growCapacity;
}

template <class T> inline
void DynamicArray<T>::shrink()
{
    unsigned int shrinkCapacity = (unsigned int)d_capacity * SHRINK_RATIO;
    if( shrinkCapacity < MINIMUM_CAPACITY )
      shrinkCapacity = MINIMUM_CAPACITY;
    T* shrinkArray = d_alloc->get( shrinkCapacity );
    std::copy( d_array, &d_array[d_length], shrinkArray );
    d_alloc->release( d_array, d_capacity );
    d_array = shrinkArray;
    d_capacity = shrinkCapacity;
}

} // End sgdc namespace

} // End StevensDev namespace

#endif
