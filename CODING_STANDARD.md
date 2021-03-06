# CS 585 C++ Style Rules
## Physical Rules
* All files must be written in lower snake case (render_engine.cpp)
* Header files and cpp’s must be colocated in the same directory
* Every header file must have a cpp, even if the cpp only includes the header (for example, with templates)
* The root of the directory must contain all files needed for building and running the application (for example, appropriate make files)
* CMake must be used for builds
* Google Test must be used for testing
* All other files must be well organized within subdirectories
* Cpp files, not cc files

## Code rules
* Everything must be in well-formed English where appropriate
* The first line of every file must contain a C++ style comment with the file name (// weapon.h)
* A space must be after the comment double character for all comments (// this is a comment)
* All non-trivial length comments must end in a period
* The private section must come before the public section in a header
* Elements interior to a namespace are not tabbed in
* The private and public keywords must be indented 2 space characters
* Elements interior should be appropriately tabbed (with spaces, not tab characters)
* Classes are upper camel case (DynamicArray)
* Functions are lower camel case (addElement)
* Reusable constants (meaning they are outside the scope of a function) must use upper snake case (DEGREES_IN_RADIANS)
* Boolean variables must contain an appropriate form at the beginning of the variable name (isAvailable, wasCreated, shouldExecute, canAttack, etc.)
* Generally, primitive type specifics should never be used in a variable name (NO: nameStr, nameString, strName, etc., note that things like weaponCount is acceptable, it is not the type, it is a clearer meaning)
* No definition (implementation) within body of class declaration (interface)
* Header may only contain definitions of inline functions and free functions (for non-template classes)
* Header MUST contain include guards in the form of INCLUDED_CLASS_NAME (#pragma once can be used, but is not a replacement for proper include guards)
* All helper functions, internal structs, etc. not meant to be visible or used by external developers MUST use anonymous namespaces unless a private struct makes more sense
* No use of the protected keyword
* There must be spaces interior to parenthesis ( attack( int targetId ); )
* Curly braces must be vertically aligned
* All functions should contain appropriate early-out clauses at the top most portion of the function (for example, immediately erroring at the top if variables are null and it is required that they are not null)
* 0 or nullptr must be used instead of NULL
* No magic numbers
* No direct heap allocations unless absolutely necessary
* Allocations must be wrapped within an appropriate container class for life cycle management
* Only pass pointers if the value is mutable
* Primitives should be passed by copy (const is not necessary)
* Non-primitives meant to not be mutated must be passed by const reference
* All non-trivial classes must implement orthodox canonical form or appropriately control the copy constructor
* Headers must contain comments detailing every function’s use and expected behavior (as well as undefined behavior), comments should be BELOW the function’s declaration, spaced two characters beyond the function’s tabbing
* No code is allowed to break the 80 character line limit, code must be intelligently broken up to read easily, subsequent code from a broken line should be tabbed one full tab (usually 4 spaces)
* All comments must be in C++ style comments (NOT C); this includes multi line comments
* Anything non-obvious code should have appropriate comments (not over commented, not under commented)
* Every class must implement an OStream insertion operator (<<) that writes a valid json string, this must be implemented as a free operator, not a friend
* All public utility functions (for example, builders and converters) must be implemented as static functions interior to a struct
* No cyclical dependencies are allowed (if you find yourself writing a forward declaration, you are doing it wrong)
* No unused includes can be present in the header (if the header does not use the include, the include must be in the cpp)
* The first include in every cpp MUST be the header for the cpp
* Includes must be alphabetical
* Private data members in a header must be prefixed with d_ (d for data)
* The inline keyword must be on its own line
* Sections of a header (for example, the constructor section) must be annotated with a C++ style comment line detailing the section in all caps (// CONSTRUCTORS, // ACCESSORS, // MUTATORS, // FREE OPERATORS, // MEMBER FUNCTIONS), the corresponding sections must be in header inline implementations and cpp’s, all functions must be implemented in the same order they are declared
* All functions that do not modify internal state must be marked with a post-fix const
* Accessor functions must be named the same as the interior data member they retrieve without the prefixed d_ (if you have float d_time, you would then have a float time() const function for retrieving the value)
* Mutators must be prefixed with set (for the same example, you would have a void setTime( float time ))
* All namespaces must have a comment on the closing bracket indicating what namespace was closed in the form of // End nspc namespace (where nspc is the namespace being closed)
* All conditional blocks (if, for, while, etc.) must use curly braces
