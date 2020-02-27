#include "point.h"
#ifndef BIRD_H
#define BIRD_H

/*********************************************
 * 
 *********************************************/
class Bird 
{
public:
   bool isAlive() const;

   void advance();

   Point getPoint();

   void kill();

   void draw();

   int hit();

private:

};

#endif