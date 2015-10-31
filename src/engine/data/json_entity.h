// json_entity.h
#ifndef INCLUDED_JSON_ENTITY
#define INCLUDED_JSON_ENTITY

#include "../containers/dynamic_array.h"
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
      // Enum detailing the type of data stored

    int asInt() const;

    const std::string& asString() const;

    double asDouble() const;

    const sgdc::DynamicArray<JsonEntity>&  asArray() const;

    bool isInt() const;

    bool isString() const;

    bool isDouble() const;

    bool isArray() const;

    bool isObject() const;

    const JsonEntity& operator[]( std::string& key ) const;

    const JsonEntity& operator[]( int index ) const;
      // 
};

} // end namespace sgdd

} // end namespace StevensDev

#endif
