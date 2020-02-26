#include "lander.h"
#include "uiDraw.h"
#include <random>

//The value of thurst of the lander
#define THURST_VALUE 0.1
#define THURSTDOWN_VALUE (THURST_VALUE*3.0)*-1.0
#define THURST_FUEL_CONSUMPTION 1
#define THURSTDOWN_FUEL_CONSUMPTION 3
#define MOON_GRAVITY 0.1
#define INITIAL_FUEL 500

Lander::Lander()
{
   std::default_random_engine generator;
   std::uniform_int_distribution<int> distribution(-190, 200);
   int position = distribution(generator); //generates number in the range -190, 200

   this->gravity = MOON_GRAVITY;

   this->setAlive(true);
   this->setLanded(false);

   this->point.setX(position);
   this->point.setY(200);

   this->velocity = Velocity();

   this->_isMovingLeft = true;
   this->_isMovingRight = false;

   this->_canThrust = true;
   this->setFuel(INITIAL_FUEL);
}

void Lander::setFuel(int Fuel)
{
   if (Fuel < 0)
   {
      fuel = 0;
      //no more thurst, since there is no more fuel
      this->_canThrust = false;
   }
   else
      fuel = Fuel;
}

int Lander::getFuel() const
{
   return fuel;
}

void Lander::applyGravity(float Gravity)
{
   gravity = Gravity;
}

float Lander::getGravity() const
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

void Lander::setVelocityDx(float dx)
{
   velocity.addDx(dx);
}

void Lander::setVelocityDy(float dy)
{
   velocity.addDy(dy);
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
   drawLander(this->getPoint());
}

void Lander::applyThrustBottom()
{
   if (!_canThrust) return;

   this->point.addY(THURSTDOWN_VALUE);
   this->setFuel(this->getFuel() - THURSTDOWN_FUEL_CONSUMPTION);

   this->setVelocityDy(THURSTDOWN_VALUE);
}

void Lander::applyThrustLeft()
{
   if (!_canThrust) return;

   this->point.addX(THURST_VALUE);
   this->decreaseFuel();

   //if changed the direction, start the 
   //count of the velocity.
   if (this->_isMovingRight == false)
   {
      this->velocity.setDx(0);
      this->setVelocityDx(THURST_VALUE);
   }
   else
   {
      this->setVelocityDx(THURST_VALUE);
   }

   this->_isMovingRight = true;
   this->_isMovingLeft = false;
}

void Lander::applyThrustRight()
{
   if (!_canThrust) return;

   this->point.addX(THURST_VALUE * -1.0);
   this->decreaseFuel();


   //if changed the direction, start the 
   //count of the velocity.
   if (this->_isMovingLeft == false)
   {
      this->velocity.setDx(0);
      this->setVelocityDx(THURST_VALUE);
   }
   else
   {
      this->setVelocityDx(THURST_VALUE);
   }

   this->_isMovingRight = false;
   this->_isMovingLeft = true;
}

void Lander::advance()
{
   //the lander 'Y' direction will always be the effect of the gravity.
   this->point.addY(this->getGravity() * -1.0);

   //the lander 'X' direction will follow the last applied thurst.
   if (_isMovingLeft)
   {
      this->point.addX(this->getGravity() * -1.0);
   }

   if (_isMovingRight)
   {
      this->point.addX(this->getGravity());
   }
}

void Lander::decreaseFuel()
{
   this->setFuel(this->getFuel() - THURST_FUEL_CONSUMPTION);
}
