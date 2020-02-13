#include "point.h"
#include "velocity.h"

#ifndef LANDER_H
#define LANDER_H

class Lander 
{
   public:
   void setFuel(int Fuel);
   int getFuel() const;

   void applyGravity(int Gravity);
   int  getGravity() const;

   bool canThrust() const;

   Point getPoint() const;
   Velocity getVelocity() const;

   void setAlive(bool Alive);
   bool isAlive() const;

   void setLanded(bool Landed);
   bool isLanded() const;

   void draw();
   void applyThrustBottom();
   void applyThrustLeft();
   void applyThrustRight();
   void advance();

   private:
   int gravity;
   int fuel;
   
   Point point;
   Velocity velocity;

   bool _isAlive;
   bool _isLanded;
   bool _canThrust;   
};

#endif /* LANDER_H */
