// nxn_scene_graph.cpp
#include "nxn_scene_graph.h"

namespace StevensDev
{

namespace sgds
{
// CONSTRUCTORS
NxNSceneGraph( float dimensions, int divisions )
{
    d_dimensions = dimensions;
    d_divisions = divisions;
}

NxNSceneGraph( const NxNSceneGraph& copy )
{
    d_dimensions = copy.d_dimensions;
    d_divisions = copy.d_divisions;
    d_colliders = copy.d_colliders;
    d_addColliders = copy.d_addColliders;
    d_removeColliders = copy.d_removeColliders;
}

NxNSceneGraph( NxNSceneGraph&& move )
{
    d_dimensions = move.d_dimensions;
    d_divisions = move.d_divisions;
    d_colliders = std::move( move.d_colliders );
    d_addColliders = std::move( move.d_addColliders );
    d_removeColliders = std::move( move.d_removeColliders );
}

// DESTRUCTORS
~NxNSceneGraph()
{
    delete[] d_colliders;
    delete[] d_addColliders;
    delete[] d_removeColliders;
}

// MUTATORS
void addCollider( ICollider* collider )
{
    d_addColliders.push( collider );
}

void removeCollider( ICollider* collider)
{
    d_removeColliders.push( collider );
}

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


} // End namespace sgds.

} // End namespace StevensDev.
