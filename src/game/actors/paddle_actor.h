// paddle_actor.h
#ifndef INCLUDED_PADDLE_ACTOR
#define INCLUDED_PADDLE_ACTOR

#include "../../engine/rendering/renderable_sprite.h"
#include "../../engine/scene/rectangle_bounds.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

namespace StevensDev
{

namespace sgdg
{

class PaddleActor
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

    float d_velocity;
      // Velocity along the x axis.

  public:
    // CONSTRUCTORS
    PaddleActor( float x, float y, const sf::Texture& texture );

    // DESTRUCTORS
    ~PaddleActor();
      // Default destructor.

    // ACCESSORS
    sgdr::RenderableSprite* getSprite();
      // Returns the sprite of the actor.

    sgds::RectangleBounds* getBounds();
      // Returns the collider of the actor.

    const float getY() const;
      // Get the y position.

    const float getVelocity() const;
      // Get the velocity of the paddle.

    // MUTATORS
    void move( float x, float y );
      // Update the positioning of the ball.

    void setPosition( float x, float y );
      // Update the positioning of the ball.

    // FREE OPERATORS
    bool doesCollide( const sgds::RectangleBounds& candidate );
      // Checks if a collision had occured.
};

} // End namespace sgdg.

} // End namespace StevensDev.

#endif
