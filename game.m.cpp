// game.m.cpp
#include <iostream>
/* #include "src/engine/actors/iactor.h"
#include "src/engine/actors/icontroller.h"
#include "src/engine/actors/ifactory.h"
#include "src/engine/containers/dynamic_array.h"
#include "src/engine/containers/map.h"
#include "src/engine/data/json_parser.h"
#include "src/engine/data/json_entity.h"
#include "src/engine/events/event_bus.h"
#include "src/engine/events/event_dispatcher.h"
#include "src/engine/events/ievent.h"
#include "src/engine/memory/counting_allocator.h"
#include "src/engine/memory/default_allocator.h"
#include "src/engine/memory/iallocator.h"
#include "src/engine/rendering/renderable_sprite.h"
#include "src/engine/scene/icollider.h"
#include "src/engine/scene/itickable.h"
#include "src/engine/scene/nxn_scene_graph.h"
#include "src/engine/scene/rectangle_bounds.h"
#include "src/engine/scene/scene.h" */
#include "src/engine/rendering/renderer.h"
#include "src/engine/input/input.h"
#include "src/game/actors/ball_actor.h"
#include <string>
#include <thread>
#include <chrono>

int main()
{
  using namespace StevensDev;
  sgdg::BallActor* ball;
  sgdi::Input input = std::move( sgdi::Input::getInstance() );
  sgdr::Renderer* screen = new sgdr::Renderer();

  /* sgdr::RenderableSprite* sprite = new sgdr::RenderableSprite( 64, 64);
  sgdr::RenderableSprite* sprite2 = new sgdr::RenderableSprite( 256, 256 );
  sgds::RectangleBounds* bounds = new sgds::RectangleBounds( 64, 64, 16, 16 );
  sgds::RectangleBounds* bounds2 = new sgds::RectangleBounds( 256, 256, 16, 16); */


  if( screen->loadTexture( "Test", "src/game/assets/Test.png" ) )
  {
    ball = new sgdg::BallActor( 16, 16, screen->getTexture( "Test" ) );
  }

  screen->addSprite( ball->getSprite() );
  screen->setupWindow( 1024, 560, "Pang" );
  screen->getWindow().setActive( true );

  float moveX = 0;
  float moveY = 0;
  int loop = 10;

  while( true )
  {
    screen->draw();
    input.preTick();

    if( loop == 10 )
    {
      loop = 0;
      moveY = 0;

      if( input.isDown( sgdi::Input::Type::W ) )
      {
        moveY += -16;
      }
      if( input.isDown( sgdi::Input::Type::S ) )
      {
        moveY += 16;
      }

      moveY = moveY/10;
    }

    sf::Vector2u tSize = ball->getSprite()->sprite().getTexture()->getSize();

    if( moveY != 0 )
    {
      if( ball->getSprite()->getPositionY() + moveY <= 0 )
      {
        ball->setPosition( 0, ball->getSprite()->getPositionY() );
        moveX = 0;
      }
      else if( ball->getSprite()->getPositionX() + moveX + (float)(tSize.x/10) >= 560 )
      {
        ball->setPosition( 560 - (float)(tSize.x/10), ball->getSprite()->getPositionY() );
        moveX = 0;
      }
      else
      {
        ball->move( moveX, 0 );
      }
    }

    loop++;
    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
  }

  return 0;
}
