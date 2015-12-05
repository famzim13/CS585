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
    for( int i=0; i < rawJson.length(); i++ )
    {
      std::cout << rawJson[i];
    }
    std::cout << '\n';
}

// MEMBER FUNCTIONS
int JsonParser::parseArray( const std::string& rawJson, int pos )
{

}

int JsonParser::parseBool( const std::string& rawJson, int pos )
{

}

int JsonParser::parseNumber( const std::string& rawJson, int pos )
{

}

int JsonParser::parseObject( const std::string& rawJson, int pos )
{

}

int JsonParser::parseString( const std::string& rawJson, int pos )
{

}

// Stuff to know
// { } means an object, input values are name:value
// [ ] means an array, entries are split with ,
// " " means a string
//

} // End namespace sgdd.

} // End namespace StevensDev.
