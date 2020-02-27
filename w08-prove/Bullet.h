#include "point.h"
#ifndef BULLET_H
#define BULLET_H

/*********************************************
 * Bullet
 *********************************************/
class Bullet
{
   public:
     bool isAlive() const;
     
     void advance();

     Point getPoint();

     void kill();

     void draw();

     void fire(Point point, float position);

   private:

};

#endif