// trie_node.h
#ifndef INCLUDED_TRIE_NODE
#define INCLUDED_TRIE_NODE

#include "../memory/default_allocator.h"
#include "dynamic_array.h"
#include <new>

namespace StevensDev
{

namespace sgdc
{

template <class T>
class TrieNode
{
  private:
    sgdm::IAllocator<T>* d_alloc;
      // Content memory allocator.

    sgdm::IAllocator<TrieNode<T>*>* d_trieAlloc;
      // TrieNode memory allocator.

    DynamicArray<TrieNode<T>*>* d_children;
      // Children of the current node.

    T d_content;
      // Content of the node.

    bool d_marker;
      // Marker of if the node has content.

    // MEMBER FUNCTIONS
    void rehash();
      // Rehash the children of the node.

  public:
    // CONSTRUCTORS
    TrieNode();
      // Default constructor.

    TrieNode( sgdm::IAllocator<T>* alloc );
      // Constructor using an allocator.

    // DESTRUCTORS
    ~TrieNode();
      // Default destructor.

    // ACCESSORS
    T get() const;
      // Returns content of the node.


    // MUTATORS

};

// CONSTRUCTORS
template <class T>
TrieNode<T>::TrieNode()
{
    d_alloc = new sgdm::DefaultAllocator<T>();
    d_trieAlloc = new sgdm::DefaultAllocator<TrieNode<T>*>();
    d_children = new DynamicArray<TrieNode<T>*>( d_trieAlloc );
    d_content = NULL;
    d_marker = false;
}

template <class T>
TrieNode<T>::TrieNode( sgdm::IAllocator<T>* alloc )
{
    d_alloc = alloc;
    d_children = d_alloc->construct( DynamicArray<TrieNode*>( d_alloc ) );
    d_content = NULL;
    d_marker = false;
}

// DESTRUCTORS
template <class T>
TrieNode<T>::~TrieNode()
{
  for( int i=0; i<d_children->getCapacity(); i++ )
  {
    d_trieAlloc->destruct( &d_children[i] );
  }
}

// ACCESSORS
template <class T>
T TrieNode<T>::get() const
{
  return d_content;
}

} // end namespace sgdc

} // end namespace StevensDev

#endif
