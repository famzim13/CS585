// nxn_scene_graph.cpp
#include "nxn_scene_graph.h"

namespace StevensDev
{

namespace sgds
{
// CONSTRUCTORS
NxNSceneGraph::NxNSceneGraph( float dimensions, unsigned int divisions )
{
    d_dimensions = dimensions;
    d_divisions = divisions;
    *d_colliders = new sgdc::DynamicArray<ICollider*>( d_divisions+1 );
    for( int i=0; i<d_divisions; i++ )
    {
      d_colliders[i] = new sgdc::DynamicArray<ICollider*>( d_divisions+1 );
    }
}

NxNSceneGraph::NxNSceneGraph( const NxNSceneGraph& copy )
{
    d_dimensions = copy.d_dimensions;
    d_divisions = copy.d_divisions;
    d_colliders = copy.d_colliders;
    d_updateColliders = copy.d_updateColliders;
    d_addColliders = copy.d_addColliders;
    d_removeColliders = copy.d_removeColliders;
}

NxNSceneGraph::NxNSceneGraph( NxNSceneGraph&& move )
{
    d_dimensions = move.d_dimensions;
    d_divisions = move.d_divisions;
    d_colliders = std::move( move.d_colliders );
    d_updateColliders = std::move( move.d_updateColliders );
    d_addColliders = std::move( move.d_addColliders );
    d_removeColliders = std::move( move.d_removeColliders );
}

NxNSceneGraph& NxNSceneGraph::operator=( const NxNSceneGraph& rhs )
{
    d_dimensions = rhs.d_dimensions;
    d_divisions = rhs.d_divisions;
    d_colliders = rhs.d_colliders;
    d_updateColliders = rhs.d_updateColliders;
    d_addColliders = rhs.d_addColliders;
    d_removeColliders = rhs.d_removeColliders;
}

// DESTRUCTORS
NxNSceneGraph::~NxNSceneGraph()
{
    delete[] d_colliders;
}

// MEMBER FUNCTIONS
sgdc::DynamicArray<ICollider*> NxNSceneGraph::find( float x, float y,
  float width, float height, unsigned int flags, bool checkFlags,
  const ICollider* collider )
{
    sgdc::DynamicArray<ICollider*> found;
    int beginRow = x/d_dimensions;
    int endRow = (x+width)/d_dimensions;
    int beginColumn = y/d_dimensions;
    int endColumn = (y+height)/d_dimensions;

    bool isFound = false;
    for( int row=beginRow; row<=endRow; row++ )
    {
      for( int col=beginColumn; col<=endColumn; col++ )
      {
        for( int i=0; i<d_colliders[row][col].getLastIndex(); i++ )
        {
          if( ( checkFlags && d_colliders[row][col][i]->flags() == flags ) ||
              ( collider != NULL && collider != d_colliders[row][col][i] ) ||
              ( !checkFlags && collider == NULL ) )
          {
            for( int j=0; j<found.getLastIndex(); j++ )
            {
              if( d_colliders[row][col][i] == found[j] )
              {
                isFound = true;
                break;
              }
            }
            if( !isFound )
            {
              found.push( d_colliders[row][col][i] );
            }
            isFound = false;
          }
        }
      }
    }

    return found;
}

void NxNSceneGraph::updateGraph()
{
    for( int i=0; i<d_divisions; i++ )
    {
      for( int j=0; j<d_divisions; j++ )
      {
        for( int k=0; k<d_colliders[i][j].getLastIndex(); k++ )
        {
          d_colliders[i][j].pop();
        }
      }
    }

    for( int i=0; i<d_updateColliders.getLastIndex(); i++ )
    {
      addToGraph( d_updateColliders[i] );
    }
}

void NxNSceneGraph::addToGraph( ICollider* collider )
{
    RectangleBounds bounds = collider->bounds();
    int beginRow = bounds.x()/d_dimensions;
    int endRow = (bounds.x() + bounds.width())/d_dimensions;
    int beginColumn = bounds.y()/d_dimensions;
    int endColumn = (bounds.y() + bounds.height())/d_dimensions;

    d_updateColliders.push( collider );
    for( int row=beginRow; row<=endRow; row++ )
    {
      for( int col=beginColumn; col<=endColumn; col++ )
      {
        d_colliders[row][col].push( collider );
      }
    }
}

void NxNSceneGraph::removeFromGraph( ICollider* collider )
{
    RectangleBounds bounds = collider->bounds();
    int beginRow = bounds.x()/d_dimensions;
    int endRow = (bounds.x() + bounds.width())/d_dimensions;
    int beginColumn = bounds.y()/d_dimensions;
    int endColumn = (bounds.y() + bounds.height())/d_dimensions;

    for( int row=beginRow; row<=endRow; row++ )
    {
      for( int col=beginColumn; col<=endColumn; col++ )
      {
        for( int i=0; i<d_colliders[row][col].getLastIndex(); i++ )
        {
          if( d_colliders[row][col][i] == collider )
          {
            d_colliders[row][col].removeAt(i);
          }
        }
      }

      for( int j=0; j<d_updateColliders.getLastIndex(); j++ )
      {
        if( d_updateColliders[j] == collider )
        {
          d_updateColliders.removeAt(j);
          break;
        }
      }
    }
}

// MUTATORS
void NxNSceneGraph::addCollider( ICollider* collider )
{
    d_addColliders.push( collider );
}

void NxNSceneGraph::removeCollider( ICollider* collider)
{
    d_removeColliders.push( collider );
}

// ACCESSORS
sgdc::DynamicArray<ICollider*> NxNSceneGraph::find(
  float x, float y, float width, float height )
{
    return find( x, y, width, height, 0, false, NULL );
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find(
  float x, float y, float width, float height, unsigned short flags )
{
    return find( x, y, width, height, flags, true, NULL );
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find( const RectangleBounds& bounds )
{
    return find( bounds.x(), bounds.y(), bounds.width(), bounds.height(),
                 0, false, NULL );
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find(
  const RectangleBounds& bounds, unsigned short flags )
{
    return find( bounds.x(), bounds.y(), bounds.width(), bounds.height(),
                 flags, true, NULL );
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find( const ICollider* collider )
{
    RectangleBounds bounds = collider->bounds();
    return find( bounds.x(), bounds.y(), bounds.width(), bounds.height(),
                 0, false, collider );
}

// FREE OPERATORS
void NxNSceneGraph::preTick()
{
    updateGraph();

    for( int i=0; i<d_addColliders.getLastIndex(); i++ )
    {
      addToGraph( d_addColliders[i] );
    }

    d_addColliders = sgdc::DynamicArray<ICollider*>();
}

void NxNSceneGraph::tick( float dtS )
{

}

void NxNSceneGraph::postTick()
{
    for( int i=0; i<d_removeColliders.getLastIndex(); i++ )
    {
      removeFromGraph( d_removeColliders[i] );
    }

    d_removeColliders = sgdc::DynamicArray<ICollider*>();
}


} // End namespace sgds.

} // End namespace StevensDev.
