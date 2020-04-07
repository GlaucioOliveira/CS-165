#include "ship.h"

//The value of thurst of the lander
#define THURSTDOWN_VALUE 0.05

Ship::Ship()
{
   _angle = 0;

   point.setX(0);
   point.setY(0);

   applyGravity(0.2);

   _isMovingLeft = true;
   _isMovingRight = false;
   _thrust = false;

   velocity = Velocity();
   velocity.setMaxSpeed(10);
}

void Ship::applyGravity(float Gravity)
{
   _gravity = Gravity;
}

float Ship::getGravity() const
{
   return 0;
}

void Ship::draw()
{
   drawShip(point, _angle - 90, getThrust());
}

void Ship::moveLeft()
{
   _angle -= SHIP_MOVE_AMOUNT;

   if (_angle <= 0) _angle = 360;
}


void Ship::moveRight()
{
   _angle += SHIP_MOVE_AMOUNT;

   if (_angle >= 360) _angle = 0; //reset the angle counting... 
}


bool Ship::getThrust()
{
   return _thrust;
}
void Ship::setThrust(bool thrust)
{
   _thrust = thrust;
}


void Ship::applyThrustBottom()
{
   if (velocity.getDx() > 0) velocity.addDx(-THURSTDOWN_VALUE);
   if (velocity.getDy() > 0) velocity.addDy(-THURSTDOWN_VALUE);
}

void Ship::applyThrustTop()
{
   velocity.addDy(THURSTDOWN_VALUE);
   velocity.addDx(THURSTDOWN_VALUE);

   point.addX(velocity.getDx() * (cos(M_PI / 180.0 * _angle)));
   point.addY(velocity.getDy() * (sin(M_PI / 180.0 * _angle)));
}

 void Ship::advance()
{
   point.addX(velocity.getDx() * (cos(M_PI / 180.0 * _angle)));
   point.addY(velocity.getDy() * (sin(M_PI / 180.0 * _angle)));

   //The following is to wrapping around for Bullets, Ship, and Rocks  
   if (point.getX() < topLeft.getX())
   {
      point.setX(bottomRight.getX());
   }

   if (point.getX() > bottomRight.getX())
   {
      point.setX(topLeft.getX());
   }

   if (point.getY() > topLeft.getY())
   {
      point.setY(bottomRight.getY());
   }

   if (point.getY() < bottomRight.getY())
   {
      point.setY(topLeft.getY());
   }
}
