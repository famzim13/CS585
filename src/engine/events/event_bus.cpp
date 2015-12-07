// event_bus.cpp
#include "event_bus.h"

namespace StevensDev
{

namespace sgde
{
// CONSTRUCTORS
EventBus& EventBus::getInstnace()
{
    static EventBus instance;
    return instance;
}

} // End namespace sgde.

} // End namespace StevensDev.
