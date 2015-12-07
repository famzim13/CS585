// game.m.cpp
#include <iostream>
#include "src/engine/actors/iactor.h"
#include "src/engine/actors/icontroller.h"
#include "src/engine/actors/ifactory.h"
#include "src/engine/containers/dynamic_array.h"
#include "src/engine/containers/map.h"
#include "src/engine/data/json_parser.h"
#include "src/engine/data/json_entity.h"
#include "src/engine/events/event_bus.h"
#include "src/engine/events/event_dispatcher.h"
#include "src/engine/events/ievent.h"
#include "src/engine/input/input.h"
#include "src/engine/memory/counting_allocator.h"
#include "src/engine/memory/default_allocator.h"
#include "src/engine/memory/iallocator.h"
#include "src/engine/rendering/renderable_sprite.h"
#include "src/engine/rendering/renderer.h"
#include "src/engine/scene/icollider.h"
#include "src/engine/scene/itickable.h"
#include "src/engine/scene/nxn_scene_graph.h"
#include "src/engine/scene/rectangle_bounds.h"
#include "src/engine/scene/scene.h"
#include <string>

int main()
{
  using namespace StevensDev;
  sgdr::RenderableSprite* sprite = new sgdr::RenderableSprite();
  sgdr::Renderer* screen = new sgdr::Renderer();
  if( screen->loadTexture( "Test", "src/game/assets/Test.png" ) )
  {
    std::cout << "Texture loaded correctly\n";
    sprite->setTexture( screen->getTexture( "Test" ) );
  }
  screen->addSprite( sprite );
  screen->setupWindow( 800, 600, "Pacboy" );
  screen->getWindow().setActive( true );

  while( true )
  {
    if( !screen->isActive() )
    {
      screen->getWindow().close();
      break;
    }
    screen->draw();
  }

  return 0;
}
