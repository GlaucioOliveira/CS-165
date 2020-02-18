#include "lander.h"
#include "uiDraw.h"

void Lander::setFuel(int Fuel)
{
   fuel = Fuel;
}

int Lander::getFuel() const
{
   return fuel;
}

void Lander::applyGravity(int Gravity)
{
   gravity = Gravity;
}

int Lander::getGravity() const
{
   return gravity;
}

bool Lander::canThrust() const
{
   return _canThrust;
}

Point Lander::getPoint() const
{
   return point;
}

Velocity Lander::getVelocity() const
{
   return velocity;
}

void Lander::setAlive(bool Alive)
{
   _isAlive = Alive;
}

bool Lander::isAlive() const
{
   return _isAlive;
}

void Lander::setLanded(bool Landed)
{
   _isLanded = Landed;
}

bool Lander::isLanded() const
{
   return _isLanded;
}

void Lander::draw()
{
   Point landerPosition;
   landerPosition.setX(20);
   landerPosition.setY(20);

   drawLander(landerPosition);
}

void Lander::applyThrustBottom()
{
}

void Lander::applyThrustLeft()
{
}

void Lander::applyThrustRight()
{
}

void Lander::advance()
{
}
