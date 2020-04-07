#ifndef VELOCITY_H
#define VELOCITY_H

#include "velocity.h"

/*********************************************
 * Class that deals with the velocity of objects
  *********************************************/
class Velocity
{
public:
   Velocity();

   float getDx() const;
   float getDy() const;
   void setDx(float dx);
   void setDy(float dy);

   void addDx(float dx);
   void addDy(float dy);

   void setMaxSpeed(float maxSpeed);

private:
   float dx;
   float dy;
   float maxSpeed;
};


#endif