// json_entity.cpp
#include "json_entity.h"

namespace StevensDev
{

namespace sgdd
{

// CONSTRUCTORS
JsonEntity::JsonEntity()
{

}

JsonEntity::JsonEntity( const sgdd::JsonEntity& copy )
{

}

JsonEntity::JsonEntity( sgdd::JsonEntity&& move )
{

}

JsonEntity& JsonEntity::operator=( const sgdd::JsonEntity& copy )
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

/*const sgdm::DynamicArray<int>&  JsonEntity::asArray() const
{

} */

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

} // End namespace sgdd.

} // End namespace StevensDev.
