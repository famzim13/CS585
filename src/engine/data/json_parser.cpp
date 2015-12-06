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
      if( rawJson[i] == '[' )
      {
        i = parseArray( rawJson, i );
      }
      else if( rawJson[i] == 't' || rawJson[i] == 'f' )
      {
        i = parseBool( rawJson, i );
      }
      else if( rawJson[i] == '{' )
      {
        i = parseObject( rawJson, i );
      }
      else if( rawJson[i] == '-' || ( rawJson[i] >= '0' && rawJson[i] <= '9' ) )
      {
        i = parseNumber( rawJson, i );
      }
      else if( rawJson[i] == '"' )
      {
        i = parseString( rawJson, i );
      }
    }
}

// MEMBER FUNCTIONS
int JsonParser::parseArray( const std::string& rawJson, int pos )
{
    std::cout << "Parsing array\n";
    while( rawJson[pos] != ']' )
    {
      std::cout << pos << " has value " << rawJson[pos] << "\n";
      pos++;
    }

    return pos+1;
}

int JsonParser::parseBool( const std::string& rawJson, int pos )
{
    std::cout << "Parsing bool\n";
    while( rawJson[pos] != 'e' )
    {
      std::cout << pos << " has value " << rawJson[pos] << "\n";
      pos++;
    }

    return pos+1;
}

int JsonParser::parseNumber( const std::string& rawJson, int pos )
{

}

int JsonParser::parseObject( const std::string& rawJson, int pos )
{
    std::cout << "Parsing object\n";
    while( rawJson[pos] != '}' )
    {
      std::cout << pos << " has value " << rawJson[pos] << "\n";
      pos++;
    }

    return pos+1;
}

int JsonParser::parseString( const std::string& rawJson, int pos )
{
    std::cout << "Parsing string\n";
    while( rawJson[pos] != '"' )
    {
      std::cout << pos << " has value " << rawJson[pos] << "\n";
      pos++;
    }

    return pos+1;
}

// Stuff to know
// { } means an object, input values are name:value
// [ ] means an array, entries are split with ,
// " " means a string
//

} // End namespace sgdd.

} // End namespace StevensDev.
