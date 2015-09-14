// iallocator.h
#ifndef INCLUDED_IALLOCATOR
#define INCLUDED_IALLOCATOR

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

} // End sgdm namespace

} // End StevensDev namespace

#endif
