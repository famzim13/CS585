// rectangle_bounds.h
#ifndef INCLUDED_RECTANGLE_BOUNDS
#define INCLUDED_RECTANGLE_BOUNDS

namespace StevensDev
{

namespace sgds
{

class RectangleBounds
{
  private:
    float d_x;
      // Positon along the x axis of the bounding box.

    float d_y;
      // Postion along the y axis of the bounding box.

    float d_width;
      // Width added to the bounding box along the x axis.

    float d_height;
      // Heigh added to the bounding box along the y axis.

    // MEMBER FUNCTIONS
    RectangleBounds();
      // Default constructor not allowed, why have an sizeless bounding box.

  public:
    //CONSTRUCTORS
    RectangleBounds( float x, float y, float width, float height );
      // Constructor with x,y and width and height.

    RectangleBounds( const RectangleBounds& copy );
      // Copy constructor.

    RectangleBounds( RectangleBounds&& move );
      // Move constructor.

    RectangleBounds& operator=( const RectangleBounds& rhs );
      // Assignment copy constructor.

    // DESTRUCTORS
    ~RectangleBounds();
      // Default destructor.

    // ACCESSORS
    float x() const;
      // Retrieve x position.

    float y() const;
      // Retrieve y position.

    float width() const;
      // Retrieve width.

    float height() const;
      //Retrieve height.

    bool doesCollide( const RectangleBounds& candidate );
      // Checks if two bounds are in collision.

    // MUTATORS
    void setX( float x );
      // Set the x axis.

    void setY( float y );
      // Set the y axis.

    void setWidth( float width );
      // Set the width.

    void setHeight( float height );
      // Set the height.

    void setDimensions( float width, float height );
      // Set the width and height.

    void setPosition( float x, float y );
      // Set the x and y axises.
};

} // End namespace sgds.

} // End namespace StevensDev.

#endif
