// node.h
#ifndef INCLUDED_NODE
#define INCLUDED_NODE

#include <iostream>
#include <string>
#include <utility>

namespace StevensDev
{

namespace sgdc
{

template <class T>
class Node
{
  private:
    Node<T>* d_next;
      // Next node in the linked list.

    std::string d_key;
      // Key of the node.

    T d_value;
      // Value of the node.

  public:
    // CONSTRUCTORS
    Node();
      // Default constructor.

    Node( const std::string& key, const T& value );
      // Constructor with values.

    Node( const Node<T>& copy );
      // Copy constructor.

    Node( Node<T>&& move );
      // Move constructor.

    Node<T>& operator=( const Node<T>& copy );
      // Operator copy constructor.

    // DESTRUCTORS
    ~Node();
      // Default destructor.

    // ACCESSORS
    T getValue() const;
      // Retrieve the value of the node.

    std::string getKey() const;
      // Retrieve the key of the node.

    Node<T>* getNext() const;
      // Retrieve the next node in the linked list.

    // MUTATORS
    void setValue( const T& value );
      // Set the value of the node.

    T& setValue();
      // Set value with operator.

    void setKey( const std::string& key );
      // Set the key of the node.

    void setNext( Node<T>& next );
      // Set the next node of the linked list.

};

// CONSTRUCTORS
template <class T>
Node<T>::Node()
{
    d_next = NULL;
}

template <class T>
Node<T>::Node( const std::string& key, const T& value )
{
    d_next = NULL;
    d_key = key;
    d_value = value;
}

template <class T>
Node<T>::Node( const Node<T>& copy )
{
    d_next = std::copy( *copy.d_next );
    d_key = copy.d_key;
    d_value = std::copy( copy.d_value );
}

template <class T>
Node<T>::Node( Node<T>&& move )
{
    d_next = std::move( move.d_next );
    d_key = move.d_key;
    d_value = std::move( move.d_value );
}

template <class T>
Node<T>& Node<T>::operator=( const Node<T>& copy )
{
    d_next = std::copy( *copy.d_next );
    d_key = copy.d_key;
    d_value = std::copy( copy.d_value );
}

// DESTRUCTORS
template <class T>
Node<T>::~Node()
{
    delete d_next;
}

// ACCESSORS
template <class T>
T Node<T>::getValue() const
{
    return d_value;
}

template <class T>
std::string Node<T>::getKey() const
{
    return d_key;
}

template <class T>
Node<T>* Node<T>::getNext() const
{
    return d_next;
}

// MUTATORS
template <class T>
void Node<T>::setValue( const T& value )
{
    d_value = value;
}

template <class T>
T& Node<T>::setValue()
{
    return d_value;
}

template <class T>
void Node<T>::setKey( const std::string& key )
{
    d_key = key;
}

template <class T>
void Node<T>::setNext( Node<T>& next )
{
    d_next = &next;
}

} // end namespace sgdc

} // end namespace StevensDev

#endif
