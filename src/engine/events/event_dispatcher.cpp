// event_dispatcher.cpp
#include "event_dispatcher.h"

namespace StevensDev
{

namespace sgde
{
// CONSTRUCTORS
EventDispatcher()
{
}

EventDispatcher( const EventDispatcher& copy )
{
    d_events = copy.d_events;
    d_addEvents = copy.d_addEvents;
    d_removeEvents = copy.d_removeEvents;
}

EventDispatcher( EventDispatcher&& move )
{
    d_events = std::move( move.d_events );
    d_addEvents = std::move( move.d_addEvents );
    d_removeEvents = std::move( move.d_removeEvents );
}

EventDispatcher& operator=( const EventDispatcher& rhs )
{
    d_events = rhs.d_events;
    d_addEvents = rhs.d_addEvents;
    d_removeEvents = rhs.d_removeEvents;
}

// DESTRUCTORS
~EventDispatcher()
{
}

// MUTATORS
void add( const std::string& type, std::function<void( const IEvent& )>* listener )
{
    d_addEvents[type].push( listener );
}

void remove( const std::string& type, std::function<void( const IEvent& )>* listener )
{
    d_removeEvents[type].push( listener );
}

void dispatch( const IEvent& event )
{

}

void preTick()
{

}

void tick( float dtS )
{

}

void postTick()
{
    
}

}

}
