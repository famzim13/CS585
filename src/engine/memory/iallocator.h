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

    // FREE OPERATORS
    virtual T* get( int count ) = 0;
      // Abstract which will be implemented in sub-classes.

    virtual void release ( T* memory, int count ) = 0;
      // Abstract which will be implemented in sub-classes.
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

} // end namespace sgdm

} // end namespace StevensDev

#endif
