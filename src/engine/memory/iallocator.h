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
      // Default constructor

    // DESTRUCTORS
    ~IAllocator();
      // Default destructor

    // MEMBER FUNCTIONS
    virtual T* get( int count );
      // Allocates a block of memory of type T with size count
    virtual void release( T* block, int count );
      // Deallocates memory from block of size count
};

// CONSTRUCTOR
inline
template <class T>
IAllocator<T>::IAllocator()
{
}

// DESTRUCTOR
inline
template <class T>
IAllocator<T>::~IAllocator()
{
}

// MEMBER FUNCTIONS
inline
template <class T>
virtual T* IAllocator<T>::get( int count )
{
    return 0;
}

inline
template <class T>
virtual void IAllocator<T>::release( T* block, int count )
{
    return 0;
}

} // End sgdm namespace

} // End StevensDev namespace

#endif
