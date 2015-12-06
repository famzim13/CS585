#ifndef INCLUDED_RENDERABLE_SPRITE
#define INCLUDED_RENDERABLE_SPRITE

#include <SFML/Graphics/Sprite.hpp>

namespace StevensDev
{

namespace sgdr
{

class RenderableSprite
{
  private:
    sf::Sprite d_sprite;
      // Renderable sprite.

    float d_x;
      // Absolute position along the x axis.

    float d_y;
      // Absolute position along the y axis.

  public:
    // CONSTRUCTORS
    RenderableSprite();
      // Default constructor.

    RenderableSprite( float x, float y );
      // Constructor with default sprite positions.

    RenderableSprite( const RenderableSprite& copy );
      // Copy constructor.

    RenderableSprite( RenderableSprite&& move );
      // Move constructor.

    RenderableSprite& operator=( const RenderableSprite& rhs );
      // Copy assignment constructor.

    // DESTRUCTORS
    ~RenderableSprite();
      // Defualt destructor.

    // ACCESSORS
    const sf::Sprite& sprite() const;
      // Returns the internal sprite.

    const float getPositionX( ) const;
      // Returns the absolute x position.

    const float getPositionY( ) const;
      // Returns the absolute y position.

    //MUTATORS
    void setPosition( float x, float y );
      // Sets the absolute x,y position of the sprite.

    void setPositionX( float x );
      // Sets the absolute x position.

    void setPositionY( float y );
      // Sets the absolute y position.

    void move( float x, float y );
      // Increments the x and y positions accordingly to input.
};

} // End namespace sgdr.

} // End namespace StevensDev.

#endif
