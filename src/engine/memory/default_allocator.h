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
      // Default constructor.
 
    // DESTRUCTORS
    ~DefaultAllocator();
      // Default destructor.

    // FREE OPERATORS
    T* get( int count );
      // Allocates a block of memory size count of type T.
    void release( T* memory, int count );
      // Releases a block of memory size count of type T.
};

// CONSTRUCTORS
template <class T>
StevensDev::sgdm::DefaultAllocator<T>::DefaultAllocator()
{
}

// DESTRUCTORS
template <class T>
StevensDev::sgdm::DefaultAllocator<T>::~DefaultAllocator()
{
}

// FREE OPERATORS
template <class T>
T* StevensDev::sgdm::DefaultAllocator<T>::get( int count )
{
  return (T*) ::operator new ( count*sizeof(T) );
}

template <class T>
void StevensDev::sgdm::DefaultAllocator<T>::release( T* memory, int count )
{
  delete[] memory;
  memory = 0;
}

} // end namespace sgdm

} // end namespace StevensDev

#endif
