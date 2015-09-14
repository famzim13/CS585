// dynamic_array.h
#ifndef INCLUDED_DYNAMIC_ARRAY
#define INCLUDED_DYNAMIC_ARRAY

#include <iostream>

#define DEFAULT_CAPACITY = 10
#define GOLDEN_RATIO = 1.618
#define SHRINK_RATIO = .5
#define SHRINK_THRESHOLD = .33

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
    unsigned int d_length;
      // Current length of the array.
    unsigned int d_capacity;
      // Current capacity of the array.
    void grow();
      // Grows array.
    void shift();
      // Shifts array.
    void shrink();
      // Shrinks array.

  public:
    //CONSTRUCTORS
    DynamicArray();
      // Default constructor.
    DynamicArray( IAllocator* alloc );
      // Constructor with pointer to allocator.

    // DESTRUCTORS
    ~DynamicArray();
      // Default destructor.

    // ACCESSORS
    unsigned int getLength() const;
      // Get length of array.
    T at( unsigned int index ) const;
      // Get element at index, throws if out of bounds.
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
    void operator[]( int i );
      // Sets element at index i, undefined behavior if out of bounds.
    void removeAt( unsigned int index );
      // Removes the element at the specified index, throws if invalid, array may shrink.
    void insertAt( unsigned int index, const T& element );
      // Inserts element at specified index, array may grow, shifts array.
}



} // End sgdc namespace

} // End StevensDev namespace

#endif
