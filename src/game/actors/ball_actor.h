// ball_actor.h
#ifndef INCLUDED_BALL_ACTOR
#define INCLUDED_BALL_ACTOR

#include "../../engine/rendering/renderable_sprite.h"
#include "../../engine/scene/rectangle_bounds.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

namespace StevensDev
{

namespace sgdg
{

class BallActor
{
  private:
    sgdr::RenderableSprite* d_sprite;
      // Sprite of the actor.

    sgds::RectangleBounds* d_bounds;
      // Bounds of the actor.

    float d_x;
      // Position along the x axis.

    float d_y;
      // Position along the y axis.

    float d_velocityX;
      // Velocity along the x axis.

    float d_velocityY;
      // Velocity along the y axis.

    bool d_direction = 0;
      // Determines initial direction of the ball along the x axis.

    bool d_spawned = 0;
      // Determines if the ball has been spawned.

  public:
    // CONSTRUCTORS
    BallActor( float x, float y, const sf::Texture& texture );

    // DESTRUCTORS
    ~BallActor();
      // Default destructor.

    // ACCESSORS
    sgdr::RenderableSprite* getSprite();
      // Returns the sprite of the actor.

    sgds::RectangleBounds* getBounds();
      // Returns the collider of the actor.

    const float getX() const;
      // Get the x position.

    const float getY() const;
      // Get the y position.

    const float getVelocityX() const;
      // Get the x velocity.

    const float getVelocityY() const;
      // Get the y velocity.

    // MUTATORS
    void move( float x, float y );
      // Update the positioning of the ball.

    void setPosition( float x, float y );
      // Update the positioning of the ball.

    void bounce( int x, int y );
      // Bounce off the wall.

    void spawn();
      // Spawn a new ball upon game start or score.

    // FREE OPERATORS
    bool doesCollide( const sgds::RectangleBounds& candidate );
      // Checks if actor collides with another actor.
};

} // End namespace sgdg.

} // End namespace StevensDev.

#endif
