// input.cpp
#include "input.h"
#include <SFML/Window.hpp>

namespace StevensDev
{

namespace sgdi
{

Input& Input::getInstance()
{
    static Input instance = Input();
    return instance;
}

bool Input::isDown( Type input )
{
    return currentInputs[input];
}

bool Input::isUp( Type input )
{
    return !currentInputs[input];
}

bool Input::wasPressed( Type input )
{
    return (isUp(input) && previousInputs[input]);
}

void Input::preTick()
{
    for( int i=0; i<INPUTS; i++ )
    {
      previousInputs[i] = currentInputs[i];
    }

    currentInputs[Type::A] = (sf::Keyboard::isKeyPressed( sf::Keyboard::A ))?1:0;
    currentInputs[Type::B] = (sf::Keyboard::isKeyPressed( sf::Keyboard::B ))?1:0;
    currentInputs[Type::C] = (sf::Keyboard::isKeyPressed( sf::Keyboard::C ))?1:0;
    currentInputs[Type::D] = (sf::Keyboard::isKeyPressed( sf::Keyboard::D ))?1:0;
    currentInputs[Type::E] = (sf::Keyboard::isKeyPressed( sf::Keyboard::E ))?1:0;
    currentInputs[Type::F] = (sf::Keyboard::isKeyPressed( sf::Keyboard::F ))?1:0;
    currentInputs[Type::G] = (sf::Keyboard::isKeyPressed( sf::Keyboard::G ))?1:0;
    currentInputs[Type::H] = (sf::Keyboard::isKeyPressed( sf::Keyboard::H ))?1:0;
    currentInputs[Type::I] = (sf::Keyboard::isKeyPressed( sf::Keyboard::I ))?1:0;
    currentInputs[Type::J] = (sf::Keyboard::isKeyPressed( sf::Keyboard::J ))?1:0;
    currentInputs[Type::K] = (sf::Keyboard::isKeyPressed( sf::Keyboard::K ))?1:0;
    currentInputs[Type::L] = (sf::Keyboard::isKeyPressed( sf::Keyboard::L ))?1:0;
    currentInputs[Type::M] = (sf::Keyboard::isKeyPressed( sf::Keyboard::M ))?1:0;
    currentInputs[Type::N] = (sf::Keyboard::isKeyPressed( sf::Keyboard::N ))?1:0;
    currentInputs[Type::O] = (sf::Keyboard::isKeyPressed( sf::Keyboard::O ))?1:0;
    currentInputs[Type::P] = (sf::Keyboard::isKeyPressed( sf::Keyboard::P ))?1:0;
    currentInputs[Type::Q] = (sf::Keyboard::isKeyPressed( sf::Keyboard::Q ))?1:0;
    currentInputs[Type::R] = (sf::Keyboard::isKeyPressed( sf::Keyboard::R ))?1:0;
    currentInputs[Type::S] = (sf::Keyboard::isKeyPressed( sf::Keyboard::S ))?1:0;
    currentInputs[Type::T] = (sf::Keyboard::isKeyPressed( sf::Keyboard::T ))?1:0;
    currentInputs[Type::U] = (sf::Keyboard::isKeyPressed( sf::Keyboard::U ))?1:0;
    currentInputs[Type::V] = (sf::Keyboard::isKeyPressed( sf::Keyboard::V ))?1:0;
    currentInputs[Type::W] = (sf::Keyboard::isKeyPressed( sf::Keyboard::W ))?1:0;
    currentInputs[Type::X] = (sf::Keyboard::isKeyPressed( sf::Keyboard::X ))?1:0;
    currentInputs[Type::Y] = (sf::Keyboard::isKeyPressed( sf::Keyboard::Y ))?1:0;
    currentInputs[Type::Z] = (sf::Keyboard::isKeyPressed( sf::Keyboard::Z ))?1:0;

    currentInputs[Type::L_MOUSE] =
      (sf::Mouse::isButtonPressed( sf::Mouse::Left ))?1:0;
    currentInputs[Type::M_MOUSE] =
      (sf::Mouse::isButtonPressed( sf::Mouse::Middle ))?1:0;
    currentInputs[Type::R_MOUSE] =
      (sf::Mouse::isButtonPressed( sf::Mouse::Right ))?1:0;
}

void Input::tick( float dtS )
{

}

void Input::postTick()
{

}

} // End namespace sgdi.

} // End namespace StevensDev.
