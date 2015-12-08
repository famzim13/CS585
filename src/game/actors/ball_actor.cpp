// ball_actor.cpp
#include "ball_actor.h"

namespace StevensDev
{

namespace sgdg
{
// CONSTRUCTORS
BallActor::BallActor( float x, float y, const sf::Texture& texture )
{
    d_x = x;
    d_y = y;
    d_sprite = new sgdr::RenderableSprite( x, y );
    d_sprite->setTexture( texture );
    d_bounds = new sgds::RectangleBounds( x, y, (float)texture.getSize().x, (float)texture.getSize().y );
}

// DESTRUCTORS
BallActor::~BallActor()
{
}

// ACCESSORS
sgdr::RenderableSprite* BallActor::getSprite()
{
    return d_sprite;
}

sgds::RectangleBounds* BallActor::getBounds()
{
    return d_bounds;
}

const float BallActor::getX() const
{
    return d_x;
}

const float BallActor::getY() const
{
    return d_y;
}

const float BallActor::getVelocityX() const
{
    return d_velocityX;
}

const float BallActor::getVelocityY() const
{
    return d_velocityY;
}

// MUTATORS
void BallActor::move( float x, float y )
{
    d_x += x;
    d_y += y;
    d_sprite->move( x, y );
    d_bounds->setPosition( d_sprite->getPositionX(), d_sprite->getPositionY() );
}

void BallActor::setPosition( float x, float y )
{
    d_x = x;
    d_y = y;
    d_sprite->setPosition( x, y );
    d_bounds->setPosition( d_sprite->getPositionX(), d_sprite->getPositionY() );
}

void BallActor::bounce( int x, int y )
{
    d_velocityX *= x;
    d_velocityY *= y;
}

void BallActor::spawn()
{
    float speeed = 3.2;
    setPosition( 512, 280 );
    srand( time( NULL ) );
    int angle = rand()%121-60;
    if( d_direction )
    {
      d_velocityX = 3.2 * cos( (float)angle * ( M_PI / 180) );
      d_velocityY = 3.2 * sin( (float)angle * ( M_PI / 180) );
    }
    else
    {
      d_velocityX = -3.2 * cos( (float)angle * ( M_PI / 180) );
      d_velocityY = 3.2 * sin( (float)angle * ( M_PI / 180) );
    }
    d_direction = !d_direction;
}

bool BallActor::doesCollide( const sgds::RectangleBounds& candidate )
{
    return d_bounds->doesCollide( candidate );
}

} // End namespace sgdg.

} // End namespace StevensDev.
