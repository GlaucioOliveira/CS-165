#include "FlyingObject.h"

Point FlyingObject::getPoint()
{
   return point;
}

Velocity FlyingObject::getVelocity()
{
   return velocity;
}

void FlyingObject::setVelocity(Velocity velocity)
{
   this->velocity = velocity;
}

void FlyingObject::setPoint(Point point)
{
   this->point = point;
}

void FlyingObject::advance()
{
   point.setX(point.getX() + velocity.getDx());
   point.setY(point.getY() + velocity.getDy());
}

bool FlyingObject::isAlive()
{
   return alive;
}

void FlyingObject::kill()
{
   alive = false;
}
