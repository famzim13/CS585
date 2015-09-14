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
class DefaultAllocator : public IAllocator
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
}

// CONSTRUCTOR
inline
template <class T>
DefaultAllocator<T>::DefaultAllocator()
{
}

// DESTRUCTOR
inline
template <class T>
DefaultAllocator<T>::~DefaultAllocator()
{
}

// MEMBER FUNCTIONS
inline
template <class T>
T* DefaultAllocator<T>::get( int count )
{
    return new T[count];
}

inline
template <class T>
void DefaultAllocator<T>::release( T* block, int count )
{
    delete block[];
    block = nullptr;
}

} // End sgdm namespace

} // End StevensDev namespace

#endif
