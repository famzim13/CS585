// icollider.h
#ifndef INCLUDED_ICOLLIDER
#define INCLUDED_ICOLLIDER

#include "rectangle_bounds.h"

namespace StevensDev
{

namespace sgds
{

class ICollider
{
  private:

  public:
    virtual RectangleBounds& bounds() = 0;
      // Return the bounds of the collidable.

    virtual unsigned short flags() const = 0;
      //  Return the flags of the collidable.

    virtual void setFlags( unsigned short flags ) = 0;
      // Set the flags of the collidable.

    virtual bool canCollide( unsigned short flags ) const = 0;
      //  Checks if the collidable can collide, phasing and invisible.

    virtual bool doesCollide( const RectangleBounds& candidate ) = 0;
      // Checks if the collidable has collided.
};

} // End namespace sgds.

} // End namespace StevensDev.

#endif
