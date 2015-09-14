// counting_allocator.h
#ifndef INCLUDED_COUNTING_ALLOCATOR
#define INCLUDED_COUNTING_ALLOCATOR

#include "default_allocator.h"
#include <iostream>

namespace StevensDev
{

namespace sgdm
{

template <class T>
class CountingAllocator : public DefaultAllocator<T>
{
  private:
    int d_allocations;
      // Amount of allocations in this instance.
    int d_deallocations;
      // Amount of deallocations in this instance.
    static int d_totalAllocations;
      // Amount of allocations across all instances.
    static int d_totalDeallocations;
      // Amount of deallocations across all instances.

  public:
    // CONSTRUCTORS
    CountingAllocator();
      // Default constructor.

    // DESTRUCTORS
    ~CountingAllocator();
      // Default destructor.

    // ACCESSORS
    int getAllocationCount() const;
      // Get number of allocations in this instance.
    int getReleaseCount() const;
      // Get number of deallocations in this instance.
    int getOutstandingCount() const;
      // Get number of in memory allocations in this instance.
    static int getTotalAllocationCount();
      // Get number of allocations across all instances.
    static int getTotalReleaseCount();
      // Get number of deallocations across all instances.
    static int getTotalOutstandingCount();
      // Get number of in memory allocations across all instances.

    // MEMBER FUNCTIONS
    T* get( int count );
      // Allocates a block of memory of type T with size count.
    void release( T* block, int count );
      // Deallocates memory from block of size count.
};

template <class T>
int CountingAllocator<T>::d_totalAllocations = 0;
  // Set d_totalAllocations to 0 before any objects are constructed.
template <class T>
int CountingAllocator<T>::d_totalDeallocations = 0;
  // Set d_totalDeallocations to 0 before any objects are constructed.

// CONSTRUCTORS
template <class T> inline
CountingAllocator<T>::CountingAllocator()
{
    d_allocations = 0;
    d_deallocations = 0;
}

// DESTRUCTORS
template <class T> inline
CountingAllocator<T>::~CountingAllocator()
{
}

// ACCESSORS
template <class T> inline
int CountingAllocator<T>::getAllocationCount() const
{
    return d_allocations;
}

template <class T> inline
int CountingAllocator<T>::getReleaseCount() const
{
    return d_deallocations;
}

template <class T> inline
int CountingAllocator<T>::getOutstandingCount() const
{
    return d_allocations - d_deallocations;
}

template <class T> inline
int CountingAllocator<T>::getTotalAllocationCount()
{
    return d_totalAllocations;
}

template <class T> inline
int CountingAllocator<T>::getTotalReleaseCount()
{
    return d_totalDeallocations;
}

template <class T> inline
int CountingAllocator<T>::getTotalOutstandingCount()
{
    return d_totalAllocations - d_totalDeallocations;
}

// MEMBER FUNCTIONS
template <class T> inline
T* CountingAllocator<T>::get( int count )
{
    d_allocations += count;
    d_totalAllocations += count;
    return new T[count];
}

template <class T> inline
void CountingAllocator<T>::release( T* block, int count )
{
    d_deallocations += count;
    d_totalDeallocations += count;
    delete block;
    block = 0;
}

} // End sgdm namespace

} // End StevensDev namespace

#endif
