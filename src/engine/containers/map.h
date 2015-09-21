// map.h
#ifndef INCLUDED_MAP
#define INCLUDED_MAP

#include <iostream>
#include "dynamic_array.h"
#include "../memory/default_allocator.h"
#include <stdexcept>
#include "string.h"

namespace StevensDev
{

namespace sgdc
{

#define ALPHABET_SIZE 26

template <class T>
class Map
{
  private:
    struct d_node
    {
      d_node* children;
      bool isleaf = true;
      std::string key;
      T value;
    };
      // Data type for dynamic array map.
    d_node* root;
      // Root node of the trie.
    sgdm::IAllocator<T>* d_valueAlloc;
      // Map value array allocator.
    sgdm::IAllocator<d_node>* d_nodeAlloc;
      // Map node allocator.
    void buildNode( d_node* node );
      // Function for creating a new node.
    void freeTrie( d_node* node );
      // Function for removing entire Trie.
    void removeNode( d_node* node );
      // Function for removing a node.
    DynamicArray<std::string> retrieveKeys( d_node* node, DynamicArray<std::string>* array );
      // Fills a dynamic array of keys.
    DynamicArray<T> retrieveValues( d_node* node, DynamicArray<T>* array );
      // Fills a dynamic array of values.

  public:
    // CONSTRUCTORS
    Map();
      // Default constructor.
    Map( sgdm::IAllocator<T>* alloc );
      // Constructor with reference to an allocator.
    Map( const Map<T>& map );
      // Copy constructor.
    
    // DESTRUCTORS
    ~Map();
    
    // ACCESSORS
    T& operator[] ( const std::string& key ) const;
      // Get the element with key string, undefined behavior if key is not in use.
    bool has( const std::string& key );
      // Determines if the key is in use.
    DynamicArray<std::string> key() const;
      // Retrieve an array of keys.
    DynamicArray<T> values() const;
      // Retrieve an array of values.

    // MUTATORS
    Map<T>& operator=( const Map<T>& map );
      // Map copy operator.
    T& operator[] ( const std::string& key );
      // Modifies value with key string, undefined behavior if key is not in use.
    void remove( const std::string& key );
      // Removes key-value from the map.
};

// CONSTRUCTORS
template <class T> inline
Map<T>::Map()
{
    sgdm::DefaultAllocator<d_node> nodeDefaultAlloc = sgdm::DefaultAllocator<d_node>();
    d_nodeAlloc = &nodeDefaultAlloc;
    sgdm::DefaultAllocator<T> valueDefaultAlloc = sgdm::DefaultAllocator<T>();
    d_valueAlloc = &valueDefaultAlloc;

    buildNode( root );
}

template <class T> inline
Map<T>::Map( sgdm::IAllocator<T>* alloc )
{
    sgdm::DefaultAllocator<d_node> nodeDefaultAlloc = sgdm::DefaultAllocator<d_node>();
    d_nodeAlloc = &nodeDefaultAlloc;
    d_valueAlloc = alloc;

    buildNode( root );
}

template <class T> inline
Map<T>::Map( const Map<T>& map )
{
    *d_nodeAlloc = *map.d_nodeAlloc;
    *d_valueAlloc = *map.d_valueAlloc;

    *root = *map.root;
}

// DESTRUCTORS
template <class T> inline
Map<T>::~Map()
{
    ~d_nodeAlloc();
    ~d_valueAlloc();
    freeTrie( root );
}

// ACCESSORS
template <class T> inline
T& Map<T>::operator[] ( const std::string& key ) const
{
    d_node* node = root;
    for( int i = 0; i < key.length(); i++ )
    {
      if( node = node->children[key[i]] )
        ;
      else
        return node->value;
    }

    return node->value;
}

template <class T> inline    
bool Map<T>::has( const std::string& key )
{
    d_node* node = root;

    for( int i = 0; i < key.length(); i++ )
    {
      if( root->children[key[i]] )
        node = root->children[key[i]];
      else
        return false;
    }

    return node->key ? true : false;
}

template <class T> inline
DynamicArray<std::string> Map<T>::key() const
{
    sgdm::DefaultAllocator<std::string> keyDefaultAlloc = sgdm::DefaultAllocator<std::string>();
    sgdm::IAllocator<std::string> keyAlloc = &keyDefaultAlloc;
    DynamicArray<std::string> keyArray = DynamicArray<std::string>( keyAlloc );
    keyArray = retrieveKeys( root, &keyArray );
    
    return keyArray;
}

template <class T> inline    
DynamicArray<T> Map<T>::values() const
{
    DynamicArray<T> valueArray = DynamicArray<T>( d_valueAlloc );
    valueArray = retrieveKeys( root, &valueArray );
    
    return valueArray;
}

// MUTATORS
template <class T> inline
Map<T>& Map<T>::operator=( const Map<T>& map )
{
    *d_nodeAlloc = *map.d_nodeAlloc;
    *d_valueAlloc = *map.d_valueAlloc;

    return *this;
}

template <class T> inline
T& Map<T>::operator[]( const std::string& key )
{
    d_node* node = root;
    for( int i = 0; i < key.length(); i++ )
    {
      if( node->children[key[i]] )
        node = node->children[key[i]];
      else
      {
        buildNode( node->children[key[i]] );
        node->isleaf = false;
        node = node->children[key[i]];
      }
    }

    return node->value;
}

template <class T> inline
void Map<T>::remove( const std::string& key )
{
    d_node* node = root;
    for( int i = 0; i < key.length(); i++ )
    {
      if( node->children[key[i]] )
        node = node->children[key[i]];
      else
        return;
    }
    if( node->isleaf )
      removeNode( node );
    else
    {
      node->key = 0;
      node->value = 0;
    }
}

// MEMBER FUNCTIONS
template <class T> inline
void Map<T>::buildNode( d_node* node )
{
    node = new d_node;
    node.key = 0;
    node.value = 0;
    node.arrayPosition = 0;
    node.children = d_nodeAlloc->get( ALPHABET_SIZE );

    for( int i = 0; i < ALPHABET_SIZE; i++ )
      node.children[i] = 0;
}

template <class T> inline
void Map<T>::freeTrie( d_node* node )
{
    for( int i = 0; i < ALPHABET_SIZE; i++ )
      if( node->children[i] )
        freeTrie( node->children[i] );
    removeNode( node );
}

template <class T> inline
void Map<T>::removeNode( d_node* node )
{
    node->key = 0;
    node->value = 0;
    d_nodeAlloc->release( node.children, ALPHABET_SIZE );
}

template <class T> inline
DynamicArray<std::string> Map<T>::retrieveKeys( d_node* node, DynamicArray<std::string>* array )
{
    for( int i = 0; i < ALPHABET_SIZE; i++ )
      if( node->children[i] )
        array = retrieveKeys( node->children[i], array );
    array->push( node->key );

    return &array;
}

template <class T> inline
DynamicArray<T> Map<T>::retrieveValues( d_node* node, DynamicArray<T>* array )
{
    for( int i = 0; i < ALPHABET_SIZE; i++ )
      if( node->children[i] )
        array = retrieveValues( node->children[i], array );
    array->push( node->value );

    return &array;
}

} // end namespace sgdc

} // end namespace StevensDevs

#endif
