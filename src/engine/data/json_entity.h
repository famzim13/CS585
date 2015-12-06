// json_entity.h
#ifndef INCLUDED_JSON_ENTITY
#define INCLUDED_JSON_ENTITY
#pragma once

#include <string>

namespace StevensDev
{

namespace sgdd
{

class JsonEntity
{
  private:
    enum EntityTypes
    {
      ARRAY,
      BOOL,
      DOUBLE,
      INT,
      OBJECT,
      STRING
    };
      // Enum of possible entity types.

  public:
    // CONSTRUCTORS
    JsonEntity();
      // Default constructor.

    JsonEntity( const sgdd::JsonEntity& copy );
      // Copy constructor.

    JsonEntity( sgdd::JsonEntity&& move );
      // Move constructor.

    JsonEntity& operator=( const sgdd::JsonEntity& copy );
      // Copy assignment constructor.

    // DESTRUCTORS
    ~JsonEntity();
      // Default destructor.

    // ACCESSORS
    JsonEntity::EntityTypes type() const;
      // Enum detailing the type of data stored.

    int asInt() const;
      // Returns element as an int.

    const std::string& asString() const;
      // Returns element as a string.

    double asDouble() const;
      // Returns element as a double.

    //const sgdm::DynamicArray<int>&  asArray() const;
      // Returns element as an array.

    const auto& asObject() const;
      // Returns element as an object.

    bool isInt() const;
      // Checks if element is an int.

    bool isString() const;
      // Checks if element is a string.

    bool isDouble() const;
      // Checks if element is a double.

    bool isArray() const;
      // Checks if element is an array.

    bool isObject() const;
      // Checks if element is an object.

    const JsonEntity& operator[]( std::string& key ) const;
      // Gets element array by its key.

    const JsonEntity& operator[]( int index ) const;
      // Gets element from array by its index.
};

} // end namespace sgdd

} // end namespace StevensDev

#endif
