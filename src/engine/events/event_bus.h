// event_bus.h
#ifndef INCLUDED_EVENT_BUS
#define INCLUDED_EVENT_BUS

namespace StevensDev
{

namespace sgde
{

class EventBus
{
  private:
    // CONSTRUCTORS
    EventBus() {};
      //

    EventBus( const EventBus& copy ) = delete;
      // Singleton, copy constructor not allowed.

    EventBus& operator=( const EventBus& rhs ) = delete;
      // Singleton, assignment copy constructor not allowed.

  public:
    // CONSTRUCTORS
    static EventBus& getInstnace();
      // Get an instance of the singleton.
};

} // End namespace sgde.

} // End namespace StevensDev.

#endif
