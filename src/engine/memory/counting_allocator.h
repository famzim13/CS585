// counting_allocator.h
#ifndef INCLUDED_COUNTING_ALLOCATOR
#define INCLUDED_COUNTING_ALLOCATOR

#include "default_allocator"
#include <iostream>

namespace StevensDev
{

namespace sgdm
{

template <class T>
class CountingAllocator : public DefaultAllocator
{
  private:
    int d_allocations;
      // Amount of allocations in this instance
    int d_deallocations;
      // Amount of deallocations in this instance
    static int d_totalAllocations;
      // Amount of allocations across all instances
    static int d_totalDeallocations;
      // Amount of deallocations across all instances

  public:
    // CONSTRUCTORS
    CountingAllocator();
      // Default constructor

    // DESTRUCTORS
    ~CountingAllocator();
      // Default destructor

    // ACCESSORS
    int getAllocationCount() const;
      // Get number of allocations in this instance
    int getReleaseCount() const;
      // Get number of deallocations in this instance
    int getOutstandingCount() const;
      // Get number of in memory allocations in this instance
    static int getTotalAllocationCount() const;
      // Get number of allocations across all instances
    static int getTotalReleaseCount() const;
      // Get number of deallocations across all instances
    static int getTotalOutstandingCount() const;
      // Get number of in memory allocations across all instances

    // MEMBER FUNCTIONS
    T* get( int count );
      // Allocates a block of memory of type T with size count
    void release( T* block, int count );
      // Deallocates memory from block of size count
}

template <class T>
CountingAllocator<T>::d_totalAllocations = 0;
  // Set d_totalAllocations to 0 before any objects are constructed
template <class T>
CountingAllocator<T>::d_totalDeallocations = 0;
  // Set d_totalDeallocations to 0 before any objects are constructed

// CONSTRUCTORS
inline
template <class T>
CountingAllocator<T>::CountingAllocator()
{
    d_allocations = 0;
    d_deallocations = 0;
}

// DESTRUCTORS
inline
template <class T>
CountingAllocator<T>::~CountingAllocator();
{
}

// ACCESSORS
inline
template <class T>
int CountingAllocator<T>::getAllocationCount() const
{
    return d_allocations;
}

inline
template <class T>
int CountingAllocator<T>::getReleaseCount() const
{
    return d_deallocations;
}

inline
template <class T>
int CountingAllocator<T>::getOutstandingCount() const
{
    return d_allocations - d_deallocations;
}

inline
template <class T>
static int CountingAllocator<T>::getTotalAllocationCount() const
{
    return d_totalAllocations;
}

inline
template <class T>
static int CountingAllocator<T>::getTotalReleaseCount() const
{
    return d_totalDeallocations;
}

inline
template <class T>
static int CountingAllocator<T>::getTotalOutstandingCount() const
{
    return d_totalAllocations - d_totalDeallocations;
}

// MEMBER FUNCTIONS
inline
template <class T>
T* CountingAllocator<T>::get( int count )
{
    d_allocations += count;
    d_totalAllocations += count;
    return new T[count];
}

inline
template <class T>
void CountingAllocator<T>::release( T* block, int count )
{
    d_deallocations += count;
    d_totalDeallocations += count;
    delete block[];
    block = nullptr;
}

} // End sgdm namespace

} // End StevensDev namespace

#endif
