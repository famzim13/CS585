// default_allocator.h
#ifndef INCLUDED_DEFAULT_ALLOCATOR
#define INCLUDED_DEFAULT_ALLOCATOR

#include "iallocator.h"
#include <new>

namespace StevensDev
{

namespace sgdm
{

template <class T>
class DefaultAllocator : public IAllocator<T>
{
  private:

  public:
    // CONSTRUCTORS
    DefaultAllocator();
      // Default constructor

    // DESTRUCTORS
    ~DefaultAllocator();
      // Default destructor

    // MEMBER FUNCTIONS
    T* get( int count );
      // Allocates a block of memory of type T with size count
    void release( T* block, int count );
      // Deallocates memory from block of size count
};

// CONSTRUCTOR
template <class T> inline
DefaultAllocator<T>::DefaultAllocator()
{
}

// DESTRUCTOR
template <class T> inline
DefaultAllocator<T>::~DefaultAllocator()
{
}

// MEMBER FUNCTIONS
template <class T> inline
T* DefaultAllocator<T>::get( int count )
{
    return new T[count];
}

template <class T> inline
void DefaultAllocator<T>::release( T* block, int count )
{
    delete block;
    block = nullptr;
}

} // End sgdm namespace

} // End StevensDev namespace

#endif
