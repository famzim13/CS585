// input.h
#ifndef INCLUDED_INPUT
#define INCLUDED_INPUT

#include "../scene/itickable.h"

namespace StevensDev
{

namespace sgdi
{

#define INPUTS 29

class Input : public sgds::ITickable
{
  private:
    Input() {};
      // Default constructor, static instance only.

    Input( const Input& input ) = delete;
      // Singleton, no copy constructor allowed.

    Input& operator=( const Input& input ) = delete;
      // Singleton, no assignment copy constructor allowed.

    enum Type
    {
      A, B, C, D, E, F,
      G, H, I, J, K, L,
      M, N, O, P, Q, R,
      S, T, U, V, W, X,
      Y, Z, L_MOUSE,
      M_MOUSE, R_MOUSE
    };
      // Enum of possible input types.

    bool previousInputs[INPUTS] = {0};
      // Array of previous inputs.

    bool currentInputs[INPUTS] = {0};
      // Array of current inputs.

  public:
    // FREE OPERATORS
    static Input& getInstance();
      // Returns a static instance of the input singleton.

    bool isDown( Type input );
      // Checks if the input is currently pressed.

    bool isUp( Type input );
      // Checks if the input is currently not pressed.

    bool wasPressed( Type input );
      // Checks if the input was pressed and currently is not pressed.

    void preTick();
      // Pre-tick logic.

    void tick( float dtS );
      // Tick logic.

    void postTick();
      // Post-tick logic.

};

} // end namespace sgdi

} // end namespace StevensDev

#endif
