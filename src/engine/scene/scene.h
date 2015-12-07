#ifndef INCLUDED_SCENE
#define INCLUDED_SCENE

#include "../containers/dynamic_array.h"
#include "../rendering/renderer.h"
#include <ctime>
#include "itickable.h"


namespace StevensDev
{

namespace sgds
{

class Scene
{
  private:
    Scene() {};
      // Static instances of singleton Scene.

    Scene( const Scene& copy ) = delete;
      // Scene is singleton, no copy constructor allowed.

    Scene& operator=( const Scene& rhs ) = delete;
      // Scene is singleton, no assignment copy constructor allowed.

    sgdc::DynamicArray<ITickable*> d_tickables;
      // Array of managed tickables.

    sgdc::DynamicArray<ITickable*> d_addTickables;
      // Array of tickables awaiting to be added.

    sgdc::DynamicArray<ITickable*> d_removeTickables;
      // Array of tickables awaiting removal.

    sgdr::Renderer* d_renderer;
      // Renderer of the scene.

    time_t d_dtPrev = time( NULL );
      // Last time since last tick, used for delta time. Set to current time.

  public:
    // CONSTRUCTORS
    static Scene& getInstance();
      // Retrieve static Scene instance.

    const sgdr::Renderer& getRenderer() const;
      // Retrieves the sceen renderer.

    // MUTATORS
    void tick();
      // Ticks all tickables

    void addTickable( ITickable* tickable );
      // Add a tickable to the scene.

    void removeTickable( ITickable* tickable );
      // Remove a tickable from the scene.

    void setRenderer( sgdr::Renderer* renderer );
      // Set the renderer of the scene.
};

} // End namespace sgds.

} // End namespace StevensDev.

#endif
