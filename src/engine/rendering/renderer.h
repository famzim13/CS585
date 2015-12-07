#ifndef INCLUDED_RENDERER
#define INCLUDED_RENDERER

#include "../containers/dynamic_array.h"
#include "../containers/map.h"
#include "renderable_sprite.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <string>

namespace StevensDev
{

namespace sgdr
{

class Renderer
{
  private:
    sgdc::DynamicArray<RenderableSprite*> d_sprites;
      // DynamicArray of renderable sprites.

    sgdc::Map<sf::Texture> d_textures;
      // Map of textures, usable on sprites.

    sf::RenderWindow d_window;
      // Windows for rendering.

  public:
    //CONSTRUCTORS
    Renderer();
      // Default constructor.

    Renderer( const Renderer& copy );
      // Copy constructor.

    Renderer( Renderer&& move );
      // Move constructor.

    Renderer& operator=( const Renderer& rhs );
      // Assignment copy constructor.

    // DESTRUCTORS
    ~Renderer();
      // Default destructor.

    // ACCESSORS
    bool isActive();
      // Returns whether or not the window is active.

    const sf::Texture& getTexture( const std::string& name );
      // Returns the texture of sprite.

    sf::RenderWindow& getWindow();
      // Returns SFML's RenderWindow.

    // MUTATORS
    void draw();
      // Render the renderable sprites.

    void addSprite( RenderableSprite* sprite );
      // Adds sprite to the render window.

    void removeSprite( RenderableSprite* sprite );
      // Removes sprite from the render window.

    void setupWindow( int width, int height, const std::string& title );
      // Creates the rendering window.

    bool loadTexture( const std::string& name, const std::string& path );
      // Loads texture into a sprite and if it worked.
};

} // End namespace sgdr.

} // End namespace StevensDev.

#endif
