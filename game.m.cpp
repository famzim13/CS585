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
#include <thread>
#include <chrono>

int main()
{
  using namespace StevensDev;
  sf::Texture redBox = sf::Texture();
  redBox.loadFromFile( "src/game/assets/Test.png" );
  sgdr::RenderableSprite* sprite = new sgdr::RenderableSprite( 64, 64);
  sgdr::Renderer* screen = new sgdr::Renderer();
  if( screen->loadTexture( "Test", "src/game/assets/Test.png" ) )
  {
    sprite->setTexture( screen->getTexture( "Test" ) );
  }
  screen->addSprite( sprite );
  screen->setupWindow( 800, 600, "Pacboy" );
  screen->getWindow().setActive( true );

  while( true )
  {
    std::cout << "Sprite location is: x " << sprite->getPositionX() <<
                  " y " << sprite->getPositionY() << "\n";
    screen->draw();
    sprite->move( 16, 0 );
    if( sprite->getPositionX() >= 800 )
    {
      sprite->setPosition( 0, sprite->getPositionY() + 16 );
    }
    if( sprite->getPositionY() >= 600 )
    {
      sprite->setPosition( 0, 0 );
    }
    std::this_thread::sleep_for( std::chrono::milliseconds( 50 ) );
  }

  return 0;
}
