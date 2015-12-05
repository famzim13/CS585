// json_parser.h
#ifndef INCLUDED_JSON_PARSER
#define INCLUDED_JSON_PARSER
#pragma once

#include "../containers/dynamic_array.h"
#include "../containers/map.h"
#include "../memory/default_allocator.h"
#include <iostream>
#include "json_entity.h"
#include <new>
#include <string>

namespace StevensDev
{

namespace sgdd
{

struct JsonParser
{
  private:
    sgdm::IAllocator<JsonEntity>* d_alloc;
      // Allocator for the JsonEntity.

    // MEMBER FUNCTIONS
    int parseArray( const std::string& rawJson, int pos );
      // Parsing of arrays.

    int parseBool( const std::string& rawJson, int pos );
      // Parsing of booleans.

    int parseNumber( const std::string& rawJson, int pos );
      // Parsing of ints or doubles.

    int parseObject( const std::string& rawJson, int pos );
      // Parsing of objects.

    int parseString( const std::string& rawJson, int pos );
      // Parsing of strings.

  public:
    // CONSTRUCTORS
    JsonParser();
      // Default constructor.

    // DESTRUCTORS
    ~JsonParser();
      // Default destructor.

    // FREE OPERATORS
    JsonEntity* fromString( const std::string& rawJson );
      // Takes input of a JSON string and outputs a JSON entity.
};

} // end namespace sgdd

} // end namespace StevensDev

#endif
