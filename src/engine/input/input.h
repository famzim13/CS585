// input.h
#ifndef INCLUDED_INPUT
#define INCLUDED_INPUT

namespace StevensDev
{

namespace sgdi
{

class Input : public ITickable
{
  private:

  public:
    // ACCESSORS
static inst() : Input&
isDown( type : InputType ) : bool		// Current state down
isUp( type : InputType ) : bool		// Current state up
wasPressed( type : InputType ) : bool	// Was down and now is up
preTick() : void	// Poll input state at this point, setup internal state

InputType should be an enum outlining all possible input types (all keyboard input, mouse input, etc. -- for example InputType::A_KEY vs. InputType::LEFT_MOUSE).
};

} // end namespace sgdi

} // end namespace StevensDev

#endif
