#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include "point.h"
#include "velocity.h"

class FlyingObject
{
protected:
   bool alive;
   Point point;
   Velocity velocity;

public:
   FlyingObject()
   {
      this->velocity = velocity;
      this->point = point;      
   }

   Point getPoint();
   Velocity getVelocity();
   void setPoint(Point point);
   void setVelocity(Velocity velocity);

   bool isAlive();
   void kill();
   void advance();
};

#endif