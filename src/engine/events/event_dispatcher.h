// event_dispatcher.h
#ifndef INCLUDED_EVENT_DISPATCHER
#define INCLUDED_EVENT_DISPATCHER

#include "../containers/dynamic_array.h"
#include "../containers/map.h"
#include "../scene/itickable.h"
#include <functional>
#include "ievent.h"
#include <string>

namespace StevensDev
{

namespace sgde
{

class EventDispatcher : public sgds::ITickable
{
  private:
    sgdc::Map< sgdc::DynamicArray<std::function<void( const IEvent& )>*> > d_events;
      // Map of arrays of current event listeners.

    sgdc::Map< sgdc::DynamicArray<std::function<void( const IEvent& )>*> > d_addEvents;
      // Map of arrays of event listeners to be managed.

    sgdc::Map< sgdc::DynamicArray<std::function<void( const IEvent& )>*> > d_removeEvents;
      // Map of arrays of events to be removed from management.

    // MEMBER FUNCTIONS
    void addListeners();
      // Adds listeners to the map of managed listners.

    void removeListeners();
      // Removes listeners from the map of managed listeners.

  public:
    // CONSTRUCTORS
    EventDispatcher();
      // Default constructor.

    EventDispatcher( const EventDispatcher& copy );
      // Copy constructor.

    EventDispatcher( EventDispatcher&& move );
      // Move constructor.

    EventDispatcher& operator=( const EventDispatcher& rhs );
      // Assignment copy constructor.

    // DESTRUCTORS
    ~EventDispatcher();

    // MUTATORS
    void add( const std::string& type, std::function<void( const IEvent& )>* listener );
      // Add the event listener at the next post tick.

    void remove( const std::string& type, std::function<void( const IEvent& )>* listener );
      // Remove the event listener at the next post tick.

    void dispatch( const IEvent& event );
      // Dispatch, perform, the event during tick.

    void preTick();
      // Perform pre-tick routines.

    void tick( float dtS );
      // Perform tick routines.

    void postTick();
      // Perform post-tick routines.
};

} // End namespace sgde.

} // End namespace StevensDev.

#endif
