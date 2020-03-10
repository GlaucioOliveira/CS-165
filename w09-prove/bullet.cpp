#include "Bullet.h"
#include "point.h"
#include <cmath> // used for sin, cos, and M_PI
#include <cassert>


#define BULLET_SPEED 8.0
#define M_PI       3.14159265358979323846 // dont know why this is not loading :(

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
   this->point = point;
   float dx = BULLET_SPEED * (-cos(M_PI / 180.0 * position));
   float dy = BULLET_SPEED * (sin(M_PI / 180.0 * position));

   velocity.setDx(velocity.getDx() + dx);
   velocity.setDy(velocity.getDy() + dy);
}
