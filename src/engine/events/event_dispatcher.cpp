// event_dispatcher.cpp
#include "event_dispatcher.h"

namespace StevensDev
{

namespace sgde
{
// CONSTRUCTORS
EventDispatcher::EventDispatcher()
{
}

EventDispatcher::EventDispatcher( const EventDispatcher& copy )
{
    d_events = copy.d_events;
    d_addEvents = copy.d_addEvents;
    d_removeEvents = copy.d_removeEvents;
}

EventDispatcher::EventDispatcher( EventDispatcher&& move )
{
    d_events = std::move( move.d_events );
    d_addEvents = std::move( move.d_addEvents );
    d_removeEvents = std::move( move.d_removeEvents );
}

EventDispatcher& EventDispatcher::operator=( const EventDispatcher& rhs )
{
    d_events = rhs.d_events;
    d_addEvents = rhs.d_addEvents;
    d_removeEvents = rhs.d_removeEvents;
}

// DESTRUCTORS
EventDispatcher::~EventDispatcher()
{
}

// MEMBER FUNCTIONS
void EventDispatcher::addListeners()
{
    for( int i=0; i<d_addEvents.getCapacity(); i++ )
    {
      if( d_addEvents.getInit( i ) )
      {
        for( int j=0; j<d_addEvents[i].getLastIndex(); j++ )
        {
          d_events[d_addEvents.getKey( i )].push( d_addEvents[i][j] );
        }
      }
    }

    d_addEvents = sgdc::Map< sgdc::DynamicArray<std::function<void( const IEvent& )>* > >();
}

void EventDispatcher::removeListeners()
{
    for( int i=0; i<d_removeEvents.getCapacity(); i++ )
    {
      if( d_removeEvents.getInit( i ) )
      {
        for( int j=0; j<d_removeEvents[i].getLastIndex(); j++ )
        {
          for( int k=0; k<d_events[d_removeEvents.getKey( i )].getLastIndex(); k++ )
          {
            if( d_removeEvents[i][k] == d_events[d_removeEvents.getKey( i )][k] )
            {
              d_events[d_removeEvents.getKey( i )].removeAt( k );
            }
          }
        }
      }
    }

    d_removeEvents = sgdc::Map< sgdc::DynamicArray<std::function<void( const IEvent& )>* > >();
}

// MUTATORS
void EventDispatcher::add(
  const std::string& type, std::function<void( const IEvent& )>* listener )
{
    d_addEvents[type].push( listener );
}

void EventDispatcher::remove(
  const std::string& type, std::function<void( const IEvent& )>* listener )
{
    d_removeEvents[type].push( listener );
}

void EventDispatcher::dispatch( const IEvent& event )
{

}

void EventDispatcher::preTick()
{
}

void EventDispatcher::tick( float dtS )
{
}

void EventDispatcher::postTick()
{
    addListeners();
    removeListeners();
}

}

}
