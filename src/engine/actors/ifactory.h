// ifactory.h
#ifndef INCLUDED_IFACTORY
#define INCLUDED_IFACTORY

#include "iactor.h"
#include "icontroller.h"

namespace StevensDev
{

namespace sgda
{

class IFactory
{
  private:

  public:
    // CONSTRUCTORS
    virtual IActor& buildActor() = 0;
      // Factory builds an actor.

    virtual IController& buildController() = 0;
      // Factory builds a controller.
};

} // End namespace sgda.

} // End namespace StevensDev.

#endif
