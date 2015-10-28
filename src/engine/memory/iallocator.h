// iallocator.h
#ifndef INCLUDED_IALLOCATOR
#define INCLUDED_IALLOCATOR

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

} // end namespace sgdm

#endif
