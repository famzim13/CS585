// icontroller.h
#ifndef INCLUDED_ICONTROLLER
#define INCLUDED_ICONTROLLER

#include "../scene/itickable.h"
#include "iactor.h"

namespace StevensDev
{

namespace sgda
{

class IController : public sgds::ITickable
{
  private:

  public:
    // ACCESSORS
    virtual const IActor& getActor() const = 0;
      // Controllers have an actor.

    // MUTATORS
    virtual void setActor( const IActor& actor ) = 0;
      // Controllers may set an actor.
};

}

}

#endif
