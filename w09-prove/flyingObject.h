#pragma once
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
      this->point = point;
      this->velocity = velocity;
   }

   Point getPoint();
   Velocity getVelocity();
   void setPoint(Point point);
   void setVelocity(Velocity velocity);

   bool isAlive();
   void kill();
   void advance();
};

