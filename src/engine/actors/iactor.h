// iactor.h
#ifndef INCLUDED_IACTOR
#define INCLUDED_IACTOR

#include "../events/event_bus.h"
#include "../rendering/renderable_sprite.h"
#include "../scene/icollider.h"

namespace StevensDev
{

namespace sgda
{

class IActor
{
  private:

  public:
    // CONSTRUCTORS
    IActor( float x, float y, const sf::Texture& texture );

    // ACCESSORS
    virtual sgds::ICollider* getBounds() = 0;
      // Actors may have bounds.

    virtual sgdr::RenderableSprite* getSprite() = 0;
      // Actors may have a sprite.

    virtual sgde::EventBus* getEvents() = 0;
      // Actors may have events.
};

} // End namespace sgda.

} // End namespace StevensDev.

#endif
