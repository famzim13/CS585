// counting_allocator.h
#ifndef INCLUDED_COUNTING_ALLOCATOR
#define INCLUDED_COUNTING_ALLOCATOR

#include "default_allocator.h"
#include <iostream>
#include <new>

namespace StevensDev
{

namespace sgdm
{

template <class T>
class CountingAllocator : public DefaultAllocator<T>
{
  private:
    int d_allocations;
      // Count of allocations this allocator has made.
    int d_deallocations;
      // Count of deallocations this allocator has made.
    static int d_totalAllocations;
      // Count of allocations all counting allocators have made.
    static int d_totalDeallocations;
      // Count of deallocations all counting allocators have made.

  public:
    // CONSTRUCTORS
    CountingAllocator();
      // Default constructor.

    // DESTRUCTORS
    ~CountingAllocator();
      // Default destructor.

    // ACCESSORS
    int getAllocationCount() const;
      // Get number of allocations this allocators has made.

    int getDeallocationCount() const;
      // Get number of deallocations this allocator has made.

    int getOutstandingCount() const;
      // Get number of allocations minus deallocations this allocator has made.

    static int getTotalAllocationCount();
      // Get number of allocations by all counting allocators.

    static int getTotalDeallocationCount();
      // Get number of deallocations by all counting allocators.

    static int getTotalOutstandingCount();
      // Get outstanding allocations by all counting allocators.
    
    // FREE OPERATORS
    T* get( int count );
      // Allocate count blocks of memory.

    void release( T* memory, int count );
      // Deallocator the block of memory.
};

template <class T>
int CountingAllocator<T>::d_totalAllocations = 0;
  // Set d_totalAllocations to 0 before any objects are constructed.

template <class T>
int CountingAllocator<T>::d_totalDeallocations = 0;
  // Set d_totalDeallocations to 0 before any objects are constructed.

// CONSTRUCTORS
template <class T>
CountingAllocator<T>::CountingAllocator()
{
    d_allocations = 0;
    d_deallocations = 0;
}

// DESTRUCTORS
template <class T>
CountingAllocator<T>::~CountingAllocator()
{
}

// ACCESSORS
template <class T>
int CountingAllocator<T>::getAllocationCount() const
{
    return d_allocations;
}

template <class T>
int CountingAllocator<T>::getDeallocationCount() const
{
    return d_deallocations;
}

template <class T>
int CountingAllocator<T>::getOutstandingCount() const
{
    return d_allocations - d_deallocations;
}

template <class T>
int CountingAllocator<T>::getTotalAllocationCount()
{
    return d_totalAllocations;
}

template <class T>
int CountingAllocator<T>::getTotalDeallocationCount()
{
    return d_totalDeallocations;
}

template <class T>
int CountingAllocator<T>::getTotalOutstandingCount()
{
    return d_totalAllocations - d_totalDeallocations;
}

// FREE OPERATORS
template <class T>
T* CountingAllocator<T>::get( int count )
{
    d_allocations += count;
    d_totalAllocations += count;
    return (T*) ::operator new (count*sizeof( T ));
}

template <class T>
void CountingAllocator<T>::release( T* memory, int count )
{
    d_deallocations += count;
    d_totalDeallocations += count;
    delete[] memory;
    memory = 0;
}

template <class T>
std::ostream& operator<<( std::ostream& stream, const CountingAllocator<T>& alloc )
{
    return stream << "{ allocations : " << alloc.getAllocationCount() <<
       ", deallocations : " << alloc.getDeallocationCount() << 
       ", outstanding : " << alloc.getOutstandingCount() <<
       ", totalAllocations : " << alloc.getTotalAllocationCount() <<
       ", totalDeallocations : " << alloc.getTotalDeallocationCount() <<
       ", totalOutstanding : " << alloc.getTotalOutstandingCount() << " }";
}

} // end namespace sgdm

} // end namespace StevensDev
#endif
