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

#define DEFAULT_CAPACITY 3
#define GOLDEN_RATIO 1.618
#define GROW_RATIO .8

template <class T>
class Map
{
  private:
    sgdm::IAllocator<T>* d_alloc;
      // Memory allocator for values.

    T* d_values;
      // Array of map values.

    sgdm::IAllocator<std::string>* d_keyAlloc;
      // Memory allocator for keys.

    std::string* d_keys;
      // Array of map keys.

    sgdm::IAllocator<bool>* d_initAlloc;
      // Memory allocator for initialized entries.

    bool* d_init;
      // Array of initialized map locations.

    unsigned int d_capacity;
      // Capacity of hash map.

    unsigned int d_valueCount;
      // Counts of elements in the map.

    // MEMBER FUNCTIONS
    void checkRehash();
      // Checks if rehashing should occur.

    unsigned int getHash( const std::string& key ) const;
      // Hashing function of keys.

    unsigned int getHash( const std::string& key, unsigned int size ) const;
      // Hashing function for rehash.

    void rehash( unsigned int growSize );
      // Grows the map and rehashes all elements.

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
    d_initAlloc = new sgdm::DefaultAllocator<bool>( );
    d_capacity = DEFAULT_CAPACITY;
    d_values = d_alloc->get( d_capacity );
    d_keys = d_keyAlloc->get( d_capacity );
    d_init = d_initAlloc->get( d_capacity );
    d_valueCount = 0;
}

template <class T>
Map<T>::Map( sgdm::IAllocator<T>* alloc )
{
    d_alloc = alloc;
    d_keyAlloc = new sgdm::DefaultAllocator<std::string>( );
    d_initAlloc = new sgdm::DefaultAllocator<bool>( );
    d_capacity = DEFAULT_CAPACITY;
    d_values = d_alloc->get( d_capacity );
    d_keys = d_keyAlloc->get( d_capacity );
    d_init = d_initAlloc->get( d_capacity );
    d_valueCount = 0;
}

template <class T>
Map<T>::Map( const Map<T>& copy )
{
    d_alloc = new sgdm::IAllocator<T>( *copy.d_alloc );
    d_keyAlloc = new sgdm::IAllocator<std::string>( *copy.d_keyAlloc );
    d_initAlloc = new sgdm::IAllocator<bool>( *copy.d_initAlloc );
    d_capacity = copy.d_capacity;
    d_valueCount = copy.d_valueCount;
    d_values = d_alloc->get( d_capacity );
    d_values = std::copy( *copy.d_values );
    d_keys = d_keyAlloc->get( d_capacity );
    d_keys = std::copy( *copy.d_keys );
    d_init = d_initAlloc->get( d_capacity );
    d_init = std::copy( *copy.d_init );
}

template <class T>
Map<T>::Map( Map<T>&& move )
{
    d_alloc = std::move( move.d_alloc );
    d_keyAlloc = std::move( move.d_keyAlloc );
    d_initAlloc = std::move( move.d_initAlloc );
    d_values = std::move( move.d_values );
    d_keys = std::move( move.d_keys );
    d_init = std::move( move.d_init );
    d_capacity = move.d_capacity;
    d_valueCount = move.d_valueCount;
}

template <class T>
Map<T>& Map<T>::operator=( const Map<T>& rhs )
{
    if( this != rhs )
    {
      d_alloc = new sgdm::IAllocator<T>( *rhs.d_alloc );
      d_keyAlloc = new sgdm::IAllocator<std::string>( *rhs.d_keyAlloc );
      d_initAlloc = new sgdm::IAllocator<bool>( *rhs.d_initAlloc );
      d_capacity = rhs.d_capacity;
      d_valueCount = rhs.d_valueCount;
      d_values = d_alloc->get( d_capacity );
      d_values = std::copy( *rhs.d_values );
      d_keys = d_keyAlloc->get( d_capacity );
      d_keys = std::copy( *rhs.d_values);
      d_init = d_initAlloc->get( d_capacity );
      d_init = std::copy( *rhs.d_init );
    }
    return *this;
}

// DESTRUCTORS
template <class T>
Map<T>::~Map()
{
    for( int i=0; i<d_capacity; i++ )
    {
      d_alloc->destruct( &d_values[i] );
      d_keyAlloc->destruct( &d_keys[i] );
      d_initAlloc->destruct( &d_init[i] );
    }
    d_alloc->release( d_values, d_capacity );
    d_keyAlloc->release( d_keys, d_capacity );
    d_initAlloc->release( d_init, d_capacity );
    delete d_values;
    delete d_keys;
    delete d_init;
    delete d_alloc;
    delete d_keyAlloc;
    delete d_initAlloc;
}

// ACCESSORS
template <class T>
const T& Map<T>::operator[]( const std::string& key ) const
{
    return d_values[getHash( key )];
}

template <class T>
bool Map<T>::has( const std::string& key )
{
    unsigned int hash = getHash( key );
    if( d_init[hash] )
    {
      if( d_keys[hash] == key )
      {
        return true;
      }
    }

    return false;
}

template <class T>
DynamicArray<std::string> Map<T>::keys() const
{
  DynamicArray<std::string> keys = DynamicArray<std::string>();

  for( int i=0; i<d_capacity; i++ )
  {
    if( d_init[i] )
    {
      keys.push( d_keys[i] );
    }
  }

  return keys;
}

template <class T>
DynamicArray<T> Map<T>::values() const
{
    DynamicArray<T> values = DynamicArray<T>( );

    for( int i=0; i<d_capacity; i++ )
    {
      if( d_init[i] )
      {
        values.push( d_values[i] );
      }
    }

    return values;
}

// MUTATORS
template <class T>
T& Map<T>::operator[]( const std::string& key )
{
    unsigned int hash = getHash( key );
    while( d_init[hash] )
    {
      if( key == d_keys[hash] )
      {
        return d_values[hash];
      }
      rehash( (unsigned int)(GOLDEN_RATIO * d_capacity) );
      hash = getHash( key );
    }

    d_alloc->construct( &d_values[hash], T() );
    d_keyAlloc->construct( &d_keys[hash], key );
    d_init[hash] = true;
    d_valueCount++;

    return d_values[hash];
}

template <class T>
T Map<T>::remove( const std::string& key )
{
    unsigned int hash = getHash( key );
    T value;
    if( d_init[hash] )
    {
      d_init[hash] = false;
      value = d_values[hash];
      d_alloc->destruct( &d_values[hash] );
      d_keyAlloc->destruct( &d_keys[hash]);
      d_valueCount--;
    }
    return value;
}

// MEMBER FUNCTIONS
template <class T>
void Map<T>::checkRehash( )
{
    if( (unsigned int)(GROW_RATIO * d_capacity) <= d_valueCount )
    {
      rehash( (unsigned int)(GOLDEN_RATIO * d_capacity) );
    }
}

template <class T>
unsigned int Map<T>::getHash( const std::string& key ) const
{
    unsigned int hash = 0;
    for( int i=0; i<key.length(); i++ )
    {
      hash = key[i] + ((hash << 5) - hash);
    }

    return hash%d_capacity;
}

template <class T>
unsigned int Map<T>::getHash( const std::string& key, unsigned int size ) const
{
    unsigned int hash = 0;
    for( int i=0; i<key.length(); i++ )
    {
      hash = key[i] + ((hash << 5) - hash);
    }

    return hash%size;
}

template <class T>
void Map<T>::rehash( unsigned int growSize )
{
    unsigned int hash;
    T* valueGrow = d_alloc->get( growSize );
    std::string* keyGrow = d_keyAlloc->get( growSize );
    bool* initGrow = d_initAlloc->get( growSize );

    for( int i=0; i<d_capacity; i++ )
    {
      if( d_init[i] )
      {
        hash = getHash( d_keys[i], growSize );
        if( initGrow[hash] )
        {
          delete valueGrow;
          delete keyGrow;
          delete initGrow;
          rehash( (unsigned int)(GOLDEN_RATIO * growSize) );
        }

        initGrow[hash] = true;
        d_keyAlloc->construct( &keyGrow[hash], d_keys[i] );;
        d_alloc->construct( &valueGrow[hash], d_values[i] );
      }
    }
    delete d_values;
    delete d_keys;
    delete d_init;

    d_capacity = growSize;
    d_values = valueGrow;
    d_keys = keyGrow;
    d_init = initGrow;
}

} // end namespace sgdc

} // end namespace StevensDev

#endif
