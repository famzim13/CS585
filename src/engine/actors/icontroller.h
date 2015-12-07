// icontroller.h
#ifndef INCLUDED_ICONTROLLER
#define INCLUDED_ICONTROLLER

#include "../scene/itickable.h"
#include "iactor.h"

namespace StevensDev
{

namespace sgda
{

class IController
{
  private:

  public:
    // ACCESSORS
    virtual const IActor& getActor() const = 0;
      // Controllers have an actor.

    virtual const sgds::ITickable& getTickable() const = 0;
      // Controllers have tickables.

    // MUTATORS
    virtual void setActor( const IActor& actor ) = 0;
      // Controllers may set an actor.

    virtual void setTickable( const sgds::ITickable& tickable ) = 0;
      // Controllers may set a tickable.
};

}

}

#endif
