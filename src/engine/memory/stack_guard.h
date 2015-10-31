// stack_guard.h
#ifndef INCLUDED_STACK_GUARD
#define INCLUDED_STACK_GUARD

#include <new>
#include <utility>

namespace StevensDev
{

namespace sgdm
{

template <class T>
class StackGuard
{
  private:
    T* d_guarded;

    // MEMBER FUNCTIONS
    StackGuard( const StackGuard<T>& guard ) = delete;
      // Copy constructor is disabled for smart pointers.

  public:
    // CONSTRUCTORS
    StackGuard( T* guarded );
      // Constructor taking in the object it will be guarding.

    StackGuard( StackGuard<T>&& move );
      // Move constructor.

    // DESTRUCTORS
    ~StackGuard();
      // Default destructor.

    // ACCESSORS
    T* operator->() const;
      // Access the guarded object to use its functions.

    // FREE OPERATORS
    bool operator==( bool rhs ) const;
      // Determine if the guarded is equal to another objest.

    bool operator!() const;
      // Determine if the guard is guarding an object.

    bool operator!=( bool rhs ) const;
      // Determine if the guarded is not equal to another object.
};

// CONSTRUCTORS
template <class T>
StackGuard<T>::StackGuard( T* guarded )
{
    d_guarded = guarded;
}

template <class T>
StackGuard<T>::StackGuard( StackGuard<T>&& move )
{
    d_guarded = std::move( move.d_guarded );
}

// DESTRUCTORS
template <class T>
StackGuard<T>::~StackGuard()
{
    delete d_guarded;
}

// ACCESSORS
template <class T>
T* StackGuard<T>::operator->() const
{
    return d_guarded;
}

// FREE OPERATORS
template <class T>
bool StackGuard<T>::operator==( bool rhs ) const
{
    return rhs;
}

template <class T>
bool StackGuard<T>::operator!() const
{
    return !d_guarded;
}

template <class T>
bool StackGuard<T>::operator!=( bool rhs ) const
{
    return !rhs;
}

} // end namespace sgdm

} // end namespace StevensDev

#endif
