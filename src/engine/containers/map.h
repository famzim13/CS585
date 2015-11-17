// map.h
#ifndef INCLUDED_MAP
#define INCLUDED_MAP

#include "../memory/default_allocator.h"
#include "dynamic_array.h"
#include <iostream>
#include <new>
#include <stdexcept>
#include <string>
#include <utility>

namespace StevensDev
{

namespace sgdc
{

template <class T>
class Map
{
  private:
    sgdm::IAllocator<T>* d_alloc;
      // Memory allocator for values.

    sgdm::IAllocator<std::string>* d_keyAlloc;
      // Memory allocator for keys.

    DynamicArray<std::string>* d_keys;
      // Keys of the map.

    DynamicArray<T>* d_values;
      // Values of the map.

    // MEMBER FUNCTIONS
    int hash( const std::string key ) const;
      // Hashing function of keys.

  public:
    // CONSTRUCTORS
    Map();
      // Default constructor.

    Map( sgdm::IAllocator<T>* alloc );
      // Allocator constructor.

    Map( const Map<T>& copy );
      // Copy constructor.

    Map( Map<T>&& move );
      // Move constructor.

    Map<T>& operator=( const Map<T>& rhs );
      // Assignment copy constructor.

    // DESTRUCTORS
    ~Map();
      // Default destructor.

    // ACCESSORS
    const T& operator[]( const std::string& key ) const;
      // Retrieves data with that key, undefined behavior if key is not in use.

    bool has( const std::string& key );
      // Determines if key is in use in the map.

    DynamicArray<std::string> keys() const;
      // Retrieves a dynamic array of keys being used by the map.

    DynamicArray<T> values() const;
      // Retrieves a dynamic array of values in the map.

    // MUTATORS
    T& operator[]( const std::string& key );
      // Modifies the value of the key-value pair, adds key-value if key is not in use.

    T remove( const std::string& key );
      // Removes key-value pair if it exists.
};

// FREE OPERATORS


// CONSTRUCTORS
template <class T>
Map<T>::Map()
{
    d_alloc = new sgdm::DefaultAllocator<T>( );
    d_keyAlloc = new sgdm::DefaultAllocator<std::string>( );
    d_keys = new DynamicArray<std::string>( d_keyAlloc, 100 );
    d_values = new DynamicArray<T>( d_alloc, 100 );
}

template <class T>
Map<T>::Map( sgdm::IAllocator<T>* alloc )
{
    d_alloc = alloc;
    d_keyAlloc = new sgdm::DefaultAllocator<std::string>( );
    d_keys = new DynamicArray<std::string>( d_keyAlloc, 100 );
    d_values = new DynamicArray<T>( d_alloc, 100 );
}

template <class T>
Map<T>::Map( const Map<T>& copy )
{
    d_alloc = new sgdm::IAllocator<T>( *copy.d_alloc );
    d_keyAlloc = new sgdm::IAllocator<std::string>( *copy.d_keyAlloc );
    d_keys = new DynamicArray<std::string>( *copy.d_keys );
    d_values = new DynamicArray<T>( *copy.d_values );
}

template <class T>
Map<T>::Map( Map<T>&& move )
{
    d_alloc = std::move( move.d_alloc );
    d_keyAlloc = std::move( move.d_keyAlloc );
    d_keys = std::move( move.d_keys );
    d_values = std::move( move.d_values );
}

template <class T>
Map<T>& Map<T>::operator=( const Map<T>& rhs )
{
    if( this != rhs )
    {
      d_alloc = new sgdm::IAllocator<T>( *rhs.d_alloc );
      d_keyAlloc = new sgdm::IAllocator<std::string>( *rhs.d_keyAlloc );
      d_keys = new DynamicArray<std::string>( *rhs.d_keys );
      d_values = new DynamicArray<T>( *rhs.d_values );
    }
    return *this;
}

// DESTRUCTORS
template <class T>
Map<T>::~Map()
{
    delete d_keys;
    delete d_values;
}

// ACCESSORS
template <class T>
const T& Map<T>::operator[]( const std::string& key ) const
{

}

template <class T>
bool Map<T>::has( const std::string& key )
{

}

template <class T>
DynamicArray<std::string> Map<T>::keys() const
{

}

template <class T>
DynamicArray<T> Map<T>::values() const
{

}

// MUTATORS
template <class T>
T& Map<T>::operator[]( const std::string& key )
{

}

template <class T>
T Map<T>::remove( const std::string& key )
{

}

// MEMBER FUNCTIONS
template <class T>
int Map<T>::hash( const std::string key ) const
{

}

} // end namespace sgdc

} // end namespace StevensDev

#endif
