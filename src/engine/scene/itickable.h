// itickable.h
#ifndef INCLUDED_ITICKABLE
#define INCLUDED_ITICKABLE

namespace StevensDev
{

namespace sgds
{

class ITickable
{
  private:

  public:
    // CONSTRUCTORS
    ITickable();
      // Default destructor.

    // DESTRUCTORS
    ~ITickable();
      // Default constructor.

    // FREE OPERATORS
    virtual void preTick() = 0;
      // Setting up the scene for the tick update.

    virtual void tick( float dtS ) = 0;
      // Updating the scene based on time elapsed.

    virtual void postTick() = 0;
      // Cleaning up the scene after the tick update.
};

// CONSTRUCTORS
ITickable::ITickable()
{
}

// DESTRUCTORS
ITickable::~ITickable()
{
}

} // end namespace sgds

} // end namespace StevensDev

#endif
