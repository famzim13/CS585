// json_parser.cpp
#include "json_parser.h"

namespace StevensDev
{

namespace sgdd
{

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
    std::cout << rawJson << "\n";
}

// Stuff to know
// { } means an object, input values are name:value
// [ ] means an array, entries are split with ,
// " " means a string
//

} // End namespace sgdd.

} // End namespace StevensDev.
