// map.h
#ifndef INCLUDED_MAP
#define INCLUDED_MAP

#include "../memory/default_allocator.h"
#include "dynamic_array.h"
#include <iostream>
#include <new>
#include "node.h"
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

    sgdm::IAllocator<Node<T>*>* d_nodeAlloc;
      // Memory allocator for nodes.

    Node<T>** d_nodes;
      // Array for hash map.

    int d_capacity = 100;
      // Capacity of hash map.

    int d_valueCount;
      // Counts of elements in the map.

    // MEMBER FUNCTIONS
    unsigned int hash( const std::string& key ) const;
      // Hashing function of keys.

    void rehash();
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
    d_nodeAlloc = new sgdm::DefaultAllocator<Node<T>*>( );
    d_nodes = d_nodeAlloc->get( 100 );
}

template <class T>
Map<T>::Map( sgdm::IAllocator<T>* alloc )
{
    d_alloc = alloc;
    d_nodeAlloc = new sgdm::DefaultAllocator<Node<T>*>( );
    d_nodes = d_nodeAlloc->get( 100 );
}

template <class T>
Map<T>::Map( const Map<T>& copy )
{
    d_alloc = new sgdm::IAllocator<T>( *copy.d_alloc );
    d_nodeAlloc = new sgdm::IAllocator<Node<T>*>( *copy.d_nodeAlloc );
    d_nodes = d_nodeAlloc->get( 100 );
    d_nodes = std::copy( *copy.d_nodes );
}

template <class T>
Map<T>::Map( Map<T>&& move )
{
    d_alloc = std::move( move.d_alloc );
    d_nodeAlloc = std::move( move.d_nodeAlloc );
    d_nodes = std::move( move.d_nodes );
}

template <class T>
Map<T>& Map<T>::operator=( const Map<T>& rhs )
{
    if( this != rhs )
    {
      d_alloc = new sgdm::IAllocator<T>( *rhs.d_alloc );
      d_nodeAlloc = new sgdm::IAllocator<Node<T>*>( *rhs.d_nodeAlloc );
      d_nodes = new DynamicArray<Node<T>*>( *rhs.d_nodes );
    }
    return *this;
}

// DESTRUCTORS
template <class T>
Map<T>::~Map()
{
    delete d_nodes;
    delete d_nodeAlloc;
}

// ACCESSORS
template <class T>
const T& Map<T>::operator[]( const std::string& key ) const
{
    Node<T>* temp = (*d_nodes)[hash( key )];
    while( temp != NULL )
    {
      if( temp->d_key == key )
      {
        break;
      }
      temp = temp->d_next;
    }
    return temp->d_value;
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
    bool found = false;
    unsigned int h = hash( key );
    Node<T>* temp = d_nodes[h];
    Node<T>* temp2;

    if( temp == NULL )
    {
      temp = new Node<T>();
      d_nodes[h] = temp;
      temp->setKey( key );
    }

    while( temp != NULL )
    {
      if( temp->getKey() == key )
      {
        found = true;
        break;
      }
      temp2 = temp;
      temp = temp->getNext();
    }

    if( !found )
    {
      temp = new Node<T>();
      temp2->setNext( *temp );
      temp->setKey( key );
    }

    return temp->setValue();
}

template <class T>
T Map<T>::remove( const std::string& key )
{
}

// MEMBER FUNCTIONS
template <class T>
unsigned int Map<T>::hash( const std::string& key ) const
{
    unsigned int hash = 1;
    for( int i=0; i<key.length(); i++ )
    {
      hash *= key[i];
    }

    return hash%d_capacity;
}

} // end namespace sgdc

} // end namespace StevensDev

#endif
