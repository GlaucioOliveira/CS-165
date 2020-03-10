#ifndef BULLET_H
#define BULLET_H

#include "FlyingObject.h"
#include "uiDraw.h"
#include <cmath> // used for sin, cos, and M_PI



/*********************************************
 * Bullet
 *********************************************/
class Bullet : public FlyingObject
{
   public:
     Bullet();

     Point getPoint();

     void draw();

     void fire(Point point, float position);

   private:

};

#endif