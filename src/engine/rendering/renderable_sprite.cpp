#include "renderable_sprite.h"

namespace StevensDev
{

namespace sgdr
{
// CONSTRUCTORS
RenderableSprite::RenderableSprite()
{
    setPosition( 0.0f, 0.0f );
}

RenderableSprite::RenderableSprite( float x, float y )
{
    setPosition( x, y );
}

RenderableSprite::RenderableSprite( const RenderableSprite& copy )
{
    setPosition( copy.d_x, copy.d_y );
}

RenderableSprite::RenderableSprite( RenderableSprite&& move )
{
    setPosition( move.d_x, move.d_y );
}

RenderableSprite& RenderableSprite::operator=( const RenderableSprite& rhs )
{
    setPosition( rhs.d_x, rhs.d_y );
}

// DESTRUCTORS
RenderableSprite::~RenderableSprite()
{

}

// MEMBER FUNCTIONS
void RenderableSprite::updateSprite( float x, float y )
{
    d_sprite.setPosition( x, y );
}

// ACCESSORS
const sf::Sprite& RenderableSprite::sprite() const
{
    return d_sprite;
}

const float RenderableSprite::getPositionX( ) const
{
    return d_x;
}

const float RenderableSprite::getPositionY( ) const
{
    return d_y;
}

//MUTATORS
void RenderableSprite::setPosition( float x, float y )
{
    d_x = x;
    d_y = y;
    updateSprite( d_x, d_y );
}

void RenderableSprite::setPositionX( float x )
{
    d_x = x;
    updateSprite( d_x, d_y );
}

void RenderableSprite::setPositionY( float y )
{
    d_y = y;
    updateSprite( d_x, d_y );
}

void RenderableSprite::setTexture( const sf::Texture& texture )
{
    d_sprite.setTexture( texture );
}

void RenderableSprite::move( float x, float y )
{
    d_x += x;
    d_y += y;
    updateSprite( d_x, d_y );
}

} // End namespace sgdr.

} // End namespace StevensDev.
