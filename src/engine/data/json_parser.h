// json_parser.h
#ifndef INCLUDED_JSON_PARSER
#define INCLUDED_JSON_PARSER

#include "../memory/default_allocator.h"
#include "json_entity.h"
#include <string>

namespace StevensDev
{

namespace sgdd
{

class JsonParser
{
  private:

  public:
    // CONSTRUCTORS
    JsonParser();
      // Default constructor.

    // DESTRUCTORS
    ~JsonParser();
      // Default destructor.

    // FREE OPERATORS
    JsonEntity* fromString( const std::string& rawJson, sgdm::IAllocator<T>* allocator = 0 );
      // Takes input of a JSON string and outputs a JSON entity.
};

// CONSTRUCTORS
JsonParser::JsonParser()
{
}

// DESTRUCTORS
JsonParser::~JsonParser()
{
}

// FREE OPERATORS
JsonEntity* JsonParser::fromString( const std::string& rawJson, sgdm::IAllocator<T>* allocator = 0)
{
   
}

} // end namespace sgdd

} // end namespace StevensDev

#endif
