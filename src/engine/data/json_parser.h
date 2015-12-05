// json_parser.h
#ifndef INCLUDED_JSON_PARSER
#define INCLUDED_JSON_PARSER
#pragma once

#include "../containers/dynamic_array.h"
#include "../containers/map.h"
#include "../memory/default_allocator.h"
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
