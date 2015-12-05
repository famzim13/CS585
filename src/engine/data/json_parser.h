// json_parser.h
#ifndef INCLUDED_JSON_PARSER
#define INCLUDED_JSON_PARSER

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

// CONSTRUCTORS
JsonParser::JsonParser()
{
    d_alloc = new sgdm::DefaultAllocator<JsonEntity>();
}

// DESTRUCTORS
JsonParser::~JsonParser()
{
    delete d_alloc;
}

// FREE OPERATORS
JsonEntity* JsonParser::fromString( const std::string& rawJson )
{

}

// Stuff to know
// { } means an object, input values are name:value
// [ ] means an array, entries are split with ,
// " " means a string
//

} // end namespace sgdd

} // end namespace StevensDev

#endif
