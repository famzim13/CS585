// iactor.h
#ifndef INCLUDED_IACTOR
#define INCLUDED_IACTOR

#include "../events/event_bus.h"
#include "../rendering/renderable_sprite.h"
#include "../scene/rectangle_bounds.h"

namespace StevensDev
{

namespace sgda
{

class IActor
{
  private:

  public:
    // ACCESSORS
    virtaul const ICollider& getBounds() const = 0;
      // Actors may have bounds.

    virtual const RenderableSprite& getSprite() const = 0;
      // Actors may have a sprite.

    virtual const EventBus& getEvents() const = 0;
      // Actors may have events.

    // MUTATORS
    virtual void setBounds( const ICollider& collider ) = 0;
      // Actors may set bounds.

    virtual void setSprite( const RenderableSprite& sprite ) = 0;
      // Actors may set a sprite.

    virtual void setEvents( const EventBus& events ) = 0;
      // Actors may set events.
};

} // End namespace sgda.

} // End namespace StevensDev.

#endif
