#include "renderer.h"

namespace StevensDev
{

namespace sgdr
{
Renderer::Renderer()
{

}

Renderer::Renderer( const Renderer& copy )
{
    d_sprites = sgdc::DynamicArray<RenderableSprite*>( copy.d_sprites );
    d_textures = sgdc::Map<sf::Texture>( copy.d_textures );
}

Renderer::Renderer( Renderer&& move )
{
    d_sprites = std::move( move.d_sprites );
    d_textures = std::move( move.d_textures );
}

Renderer& Renderer::operator=( const Renderer& rhs )
{
    d_sprites = sgdc::DynamicArray<RenderableSprite*>( rhs.d_sprites );
    d_textures = sgdc::Map<sf::Texture>( rhs.d_textures );
}

// DESTRUCTORS
Renderer::~Renderer()
{

}

// ACCESSORS
bool Renderer::isActive()
{
    sf::Event event;
    d_window.pollEvent( event );
    return event.type != sf::Event::Closed;
}

const sf::Texture& Renderer::getTexture( const std::string& name )
{
    return d_textures[name];
}

sf::RenderWindow& Renderer::getWindow( )
{
    return d_window;
}

// MUTATORS
void Renderer::draw()
{
    d_window.clear();

    for( int i=0; i<d_sprites.getLastIndex(); i++ )
    {
      d_window.draw( d_sprites[i]->sprite() );
    }

    d_window.display();
}

void Renderer::addSprite( RenderableSprite* sprite )
{
    d_sprites.push( sprite );
}

void Renderer::removeSprite( RenderableSprite* sprite )
{
    for( int i=0; i<d_sprites.getLastIndex(); i++ )
    {
      if( d_sprites[i] == sprite )
      {
        d_sprites.removeAt(i);
        break;
      }
    }
}

void Renderer::setupWindow( int width, int height, const std::string& title )
{
    d_window.create( sf::VideoMode( width, height ), title );
}

bool Renderer::loadTexture( const std::string& name, const std::string& path )
{
    sf::Texture texture;
    if( texture.loadFromFile( path ) )
    {
      d_textures[name] = texture;
    }
}

} // End namespace sgdr.

} // End namespace StevensDev.
