#include "scene.h"

namespace StevensDev
{

namespace sgds
{

// CONSTRUCTORS
Scene& Scene::getInstance()
{
    static Scene scene;
    return scene;
}

// MUTATORS
void Scene::tick()
{
    // Add new tickables "preTick" so they are ticked upon
    for( int i=0; i<d_addTickables.getLastIndex(); i++ )
    {
      d_tickables.push( d_addTickables[i] );
    }

    d_addTickables = sgdc::DynamicArray<ITickable*>();

    double dtS = difftime( d_dtPrev, time( NULL ) );

    for( int i=0; i<d_tickables.getLastIndex(); i++ )
    {
      d_tickables[i]->preTick();
    }

    for( int i=0; i<d_tickables.getLastIndex(); i++ )
    {
      d_tickables[i]->tick( dtS );
    }

    for( int i=0; i<d_tickables.getLastIndex(); i++ )
    {
      d_tickables[i]->postTick();
    }

    d_dtPrev = time( NULL );

    for( int i=0; i<d_removeTickables.getLastIndex(); i++ )
    {
      for( int j=0; j<d_tickables.getLastIndex(); j++ )
      {
        if( d_removeTickables[i] == d_tickables[j] )
        {
          d_tickables.removeAt( j );
          j--;
        }
      }
    }

    d_removeTickables = sgdc::DynamicArray<ITickable*>();
}

void Scene::addTickable( ITickable* tickable )
{
    d_addTickables.push( tickable );
}

void Scene::removeTickable( ITickable* tickable )
{
    d_removeTickables.push( tickable );
}

void Scene::setRenderer( sgdr::Renderer* renderer )
{
    d_renderer = renderer;
}

} // End namespace sgds.

} // End namespace StevensDev.
