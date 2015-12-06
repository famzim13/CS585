// nxn_scene_graph.h
#ifndef INCLUDED_NXN_SCENE_GRAPH
#define INCLUDED_NXN_SCENE_GRAPH

#include "../containers/dynamic_array.h"
#include "icollider.h"
#include "itickable.h"

namespace StevensDev
{

namespace sgds
{

class NxNSceneGraph : public ITickable
{
  private:
    float d_x;
      // X dimension of the graph.

    float d_y;
      // Y dimension of the graph.

    int d_divisions;
      // Number of times the graph is divided in each direction.

    sgdc::DynamicArray<ICollider*> d_colliders;
      // Array of colliders in the graph.

  public:
    // CONSTRUCTORS
    NxNSceneGraph();
      // Default constructor.

    // DESTRUCTORS
    ~NxNSceneGraph();
      // Default destructor.

    // ACCESSORS

    // MUTATORS
    void NxNSceneGraph( float dimensions, int divisions );
      // Sets the dimensions and tiles of the graph. This might recalculate it.

    void addCollider( ICollider* collider );
      // Based on the colliders position it puts in a certain tile.

    void removeCollider( ICollider* collider);
      // Based on the colliders position it removes it from a certain tile.

    // ACCESSORS
    sgdc::DynamicArray<ICollider*> find( float x, float y,
                                         float width, float height );
      // Based on position and size it finds all colliders within that area.

    sgdc::DynamicArray<ICollider*> find( float x, float y,
                                         float width, float height,
                                         unsigned short flags );
      // Based on position and size it finds all colliders with matching flags.

    sgdc::DynamicArray<ICollider*> find( const RectangleBounds& bounds );
      // Based on the bounds of the box find all colliders in the area.

    sgdc::DynamicArray<ICollider*> find( const RectangleBounds& bounds,
                                         unsigned short flags );
      // Based on the bounds it finds all colliders with matching flags.

    sgdc::DynamicArray<ICollider*> find( const ICollider* collider );
      // Finds all colliders within the bounds of the collider.

    // FREE OPERATORS
    void preTick();
      // Runs pre-tick routines.

    void tick( float dtS );
      // Runs tick routines.

    void postTick();
      // Runs post-tick routines.
};

}

}

#endif
