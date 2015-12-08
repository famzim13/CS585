// ball_actor.cpp
#include "ball_actor.h"

namespace StevensDev
{

namespace sgdg
{
// CONSTRUCTORS
BallActor::BallActor( float x, float y, const sf::Texture& texture )
{
    d_sprite = new sgdr::RenderableSprite( x, y );
    d_sprite->setTexture( texture );
    d_bounds = new sgds::RectangleBounds( x, y, (float)texture.getSize().x, (float)texture.getSize().y );
}

BallActor::~BallActor()
{
}

sgdr::RenderableSprite* BallActor::getSprite()
{
    return d_sprite;
}

sgds::RectangleBounds* BallActor::getBounds()
{
    return d_bounds;
}

void BallActor::move( float x, float y )
{
    d_sprite->move( x, y );
    d_bounds->setPosition( d_sprite->getPositionX(), d_sprite->getPositionY() );
}

void BallActor::setPosition( float x, float y )
{
    d_sprite->move( x, y );
    d_bounds->setPosition( d_sprite->getPositionX(), d_sprite->getPositionY() );
}

void BallActor::spawn()
{

}

bool BallActor::doesCollide( const sgds::RectangleBounds& candidate )
{
    return d_bounds->doesCollide( candidate );
}

} // End namespace sgdg.

} // End namespace StevensDev.
