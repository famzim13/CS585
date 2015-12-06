// ievent.h
#ifndef INCLUDED_IEVENT
#define INCLUDED_IEVENT

namespace StevensDev
{

namespace sgde
{

class IEvent
{
  private:

  public:
    virtual const std::string type() const = 0;
      // Returns the event type.
};

} // End namespace sgde.

} // End namespace StevensDev.

#endif
