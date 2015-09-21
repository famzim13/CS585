// iallocator.h
#ifndef INCLUDED_IALLOCATOR
#define INCLUDED_IALLOCATOR

#include "string.h"
#include <new>
#include <utility>

namespace StevensDev
{

namespace sgdm
{

template <class T>
class IAllocator
{
  private:

  public:
    // CONSTRUCTORS
    IAllocator();
      // Default constructor.

    // DESTRUCTORS
    ~IAllocator();
      // Default destructor.

    // MEMBER FUNCTIONS
    virtual T* get( int count ) = 0;
      // Allocates a block of memory of type T with size count.
    virtual void release( T* block, int count ) = 0;
      // Deallocates memory from block of size count.
    void construct( T* pointer, const T& copy );
      // Copy constructor.
    void construct( T* pointer, T&& copy );
      // Move constructor.
    void destruct( T* pointer );
};

// CONSTRUCTOR
template <class T> inline
IAllocator<T>::IAllocator()
{
}

// DESTRUCTOR
template <class T> inline
IAllocator<T>::~IAllocator()
{
}

// MEMBER FUNCTIONS
template <class T> inline
void IAllocator<T>::construct( T* pointer, const T& copy )
{
    new ( pointer ) T( copy );
}

template <class T> inline
void IAllocator<T>::construct( T* pointer, T&& copy )
{
    new ( pointer ) T( std::move( copy ) );
}

template <class T> inline
void IAllocator<T>::destruct( T* pointer )
{
    pointer->~T();
    pointer = 0;
}

} // End sgdm namespace

} // End StevensDev namespace

#endif
