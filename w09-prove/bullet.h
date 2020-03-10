#ifndef BULLET_H
#define BULLET_H

#include "FlyingObject.h"
#include "uiDraw.h"
#include <cmath>


/*********************************************
 * Class that handles the bullets
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