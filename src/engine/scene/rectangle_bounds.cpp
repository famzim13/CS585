// rectangle_bounds.cpp
#include "rectangle_bounds.h"

namespace StevensDev
{

namespace sgds
{
//CONSTRUCTORS
RectangleBounds::RectangleBounds( float x, float y, float width, float height )
{
    setPosition( x, y );
    setDimensions( width, height );
}

RectangleBounds::RectangleBounds( const RectangleBounds& copy )
{
    setPosition( copy.d_x, copy.d_y );
    setDimensions( copy.d_width, copy.d_height );
}

RectangleBounds::RectangleBounds( RectangleBounds&& move )
{
    setPosition( move.d_x, move.d_y );
    setDimensions( move.d_width, move.d_height );
}

RectangleBounds& RectangleBounds::operator=( const RectangleBounds& rhs )
{
    setPosition( rhs.d_x, rhs.d_y );
    setDimensions( rhs.d_width, rhs.d_height );
}

// DESTRUCTORS
RectangleBounds::~RectangleBounds()
{

}

// ACCESSORS
float RectangleBounds::x() const
{
    return d_x;
}

float RectangleBounds::y() const
{
    return d_y;
}

float RectangleBounds::width() const
{
    return d_width;
}

float RectangleBounds::height() const
{
    return d_height;
}

bool RectangleBounds::doesCollide( const RectangleBounds& candidate )
{
    return ( ( d_x < ( candidate.x() + candidate.width() ) ) &&
             ( ( d_x + d_width ) > candidate.x() ) &&
             ( d_y < ( candidate.y() + candidate.height() ) ) &&
             ( ( d_y + d_height ) > candidate.y() ) );
}

// MUTATORS
void RectangleBounds::setX( float x )
{
    d_x = x;
}

void RectangleBounds::setY( float y )
{
    d_y = y;
}

void RectangleBounds::setWidth( float width )
{
    d_width = width;
}

void RectangleBounds::setHeight( float height )
{
    d_height = height;
}

void RectangleBounds::setDimensions( float width, float height )
{
    d_width = width;
    d_height = height;
}

void RectangleBounds::setPosition( float x, float y )
{
    d_x = x;
    d_y = y;
}

} // End namespace sgds.

} // End namespace StevensDev.
