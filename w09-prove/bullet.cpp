#include "Bullet.h"
#include "point.h"
#include <cmath>

#define BULLET_SPEED 8.0
#define M_PI       3.14159265358979323846 // dont know why this is not loading :(
#define Angle 180.0

Bullet::Bullet()
{
   this->alive = true;
}

Point Bullet::getPoint()
{
   return point;
}

void Bullet::draw()
{
   drawDot(point);
}

void Bullet::fire(Point point, float position)
{
   point = point;
   float dx = BULLET_SPEED * (-cos( M_PI / Angle * position));
   float dy = BULLET_SPEED * (sin( M_PI / Angle * position));

   velocity.setDx(velocity.getDx() + dx);
   velocity.setDy(velocity.getDy() + dy);
}
