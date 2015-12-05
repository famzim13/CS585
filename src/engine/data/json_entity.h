// json_entity.h
#ifndef INCLUDED_JSON_ENTITY
#define INCLUDED_JSON_ENTITY

#include "../containers/dynamic_array.h"
#include "../containers/map.h"
#include <string>

namespace StevensDev
{

namespace sgdd
{

class JsonEntity
{
  private:
    enum EntityTypes { intType, stringType, doubleType, arrayType, objectType };
      // Enum of possible entity types.

  public:
    // CONSTRUCTORS
    JsonEntity();
      // Default constructor.

    JsonEntity( const JsonEntity& copy );
      // Copy constructor.

    JsonEntity( JsonEntity&& move );
      // Move constructor.

    JsonEntity& operator=( const JsonEntity& copy );
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

    const sgdm::DynamicArray<int>&  asArray() const;
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

// CONSTRUCTORS
JsonEntity::JsonEntity()
{

}

JsonEntity::JsonEntity( const JsonEntity& copy )
{

}

JsonEntity::JsonEntity( JsonEntity&& move )
{

}

JsonEntity& JsonEntity::operator=( const JsonEntity& copy )
{

}

// DESTRUCTORS
JsonEntity::~JsonEntity()
{

}

// ACCESSORS
const JsonEntity& JsonEntity::operator[]( std::string& key ) const
{

}

const JsonEntity& JsonEntity::operator[]( int index ) const
{

}

int JsonEntity::asInt() const
{

}

const std::string& JsonEntity::asString() const
{

}

double JsonEntity::asDouble() const
{

}

const sgdm::DynamicArray<int>&  JsonEntity::asArray() const
{

}

const auto& JsonEntity::asObject() const
{
    return 0;
}

bool JsonEntity::isInt() const
{

}

bool JsonEntity::isString() const
{

}

bool JsonEntity::isDouble() const
{

}

bool JsonEntity::isArray() const
{

}

bool JsonEntity::isObject() const
{

}

JsonEntity::EntityTypes JsonEntity::type() const
{

}

} // end namespace sgdd

} // end namespace StevensDev

#endif
