// iallocator.h
#ifndef INCLUDED_IALLOCATOR
#define INCLUDED_IALLOCATOR

#include <new>
#include <iostream>

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

    // FREE OPERATORS
    virtual T* get( int count ) = 0;
      // Abstract which will be implemented in sub-classes.

    virtual void release ( T* memory, int count ) = 0;
      // Abstract which will be implemented in sub-classes.

    void construct( T* pointer, const T& copy );
      // Copy constructor for T.

    void construct( T* pointer, T&& copy );
      // Move constructor for T.

    void destruct( T* pointer );
      // Destructor for T.
};

// CONSTRUCTORS
template <class T>
IAllocator<T>::IAllocator()
{
}

// DESTRUCTORS
template <class T>
IAllocator<T>::~IAllocator()
{
}

// FREE OPERATORS
template <class T>
void IAllocator<T>::construct( T* pointer, const T& copy )
{
    new ( pointer ) T( copy );
}

template <class T>
void IAllocator<T>::construct( T* pointer, T&& copy )
{
    new ( pointer ) T( std::move( copy ) );
}

template <class T>
void IAllocator<T>::destruct( T* pointer )
{
    pointer->~T();
}

} // end namespace sgdm

} // end namespace StevensDev

#endif
