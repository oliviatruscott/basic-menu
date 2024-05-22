// Rectangle.h is the Rectangle class specification file.
#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

// Rectangle class declaration
class RectangleShape
{
   private:
      double length;
      double width;
   public:
      bool setLength(double);
      bool setWidth(double);
      double getLength();
      double getWidth();
      double getArea();
};
#endif
