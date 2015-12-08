// paddle_actor.cpp
#include "paddle_actor.h"

namespace StevensDev
{

namespace sgdg
{
// CONSTRUCTORS
PaddleActor::PaddleActor( float x, float y, const sf::Texture& texture )
{
    d_sprite = new sgdr::RenderableSprite( x, y );
    d_sprite->setTexture( texture );
    d_bounds = new sgds::RectangleBounds( x, y, texture.getSize().x, texture.getSize().y );
    srand( time( NULL ) );
    d_velocity = rand()%2 + 1.5;
}

// DESTRUCTORS
PaddleActor::~PaddleActor()
{
}

// ACCESSORS
sgdr::RenderableSprite* PaddleActor::getSprite()
{
    return d_sprite;
}

sgds::RectangleBounds* PaddleActor::getBounds()
{
    return d_bounds;
}

const float PaddleActor::getY() const
{
    return d_y;
}

const float PaddleActor::getVelocity() const
{
    return d_velocity;
}

// MUTATORS
void PaddleActor::move( float x, float y )
{
    d_x += x;
    d_y += y;
    d_sprite->move( x, y );
    d_bounds->setPosition( d_x, d_y );
}

void PaddleActor::setPosition( float x, float y )
{
    d_x = x;
    d_y = y;
    d_sprite->setPosition( d_x, d_y );
    d_bounds->setPosition( d_x, d_y );
}

// FREE OPERATORS
bool PaddleActor::doesCollide( const sgds::RectangleBounds& candidate )
{
    return d_bounds->doesCollide( candidate );
}

}

}
