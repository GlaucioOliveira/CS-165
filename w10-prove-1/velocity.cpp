
#include "velocity.h"

Velocity::Velocity()
{
   dx = 0;
   dy = 0;
   maxSpeed = 0;
}

float Velocity::getDx() const
{
   return dx;
}

float Velocity::getDy() const
{
   return dy;
}


void Velocity::setDx(float dx)
{
   if (maxSpeed != 0 && dx >= maxSpeed) dx = maxSpeed;

   this->dx = dx;
}

void Velocity::setDy(float dy)
{
   if (maxSpeed != 0 && dy >= maxSpeed) dy = maxSpeed;

   this->dy = dy;
}


void Velocity::addDx(float dx)
{
   setDx(getDx() + dx);
}

void Velocity::addDy(float dy)
{
   setDy(getDy() + dy);
}

void Velocity::setMaxSpeed(float maxSpeed)
{
   this->maxSpeed = maxSpeed;
}
