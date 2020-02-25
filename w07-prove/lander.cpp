#include "lander.h"
#include "uiDraw.h"
#include <random>

//The value of thurst of the lander
#define THURST_VALUE 2

Lander::Lander()
{
   std::default_random_engine generator;
   std::uniform_int_distribution<int> distribution(-190, 200);
   int position = distribution(generator);  // generates number in the range -190, 200

   this->gravity = 0.1;
   this->fuel = 0;

   this->setAlive(true);
   this->setLanded(false);

   this->point.setX(position);
   this->point.setY(200);

   this->velocity = Velocity();

   this->_isMovingLeft = true;
   this->_isMovingRight = false;
   
   this->_canThrust = true;
   this->setFuel(500);
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
   this->point.addY((THURST_VALUE * 3) * -1.0);
   this->setFuel(this->getFuel() - 3);
   //this->_canThrust = true;
}

void Lander::applyThrustLeft()
{
   this->point.addX(THURST_VALUE);
   this->decreaseFuel();

   this->_isMovingRight = true;
   this->_isMovingLeft = false;

   //this->_canThrust = true;
}

void Lander::applyThrustRight()
{
   this->point.addX(THURST_VALUE * -1.0);
   this->decreaseFuel();

   this->_isMovingRight = false;
   this->_isMovingLeft = true;
   //this->_canThrust = true;
}

void Lander::advance()
{
   //this->_canThrust = false;
   this->point.addY(this->getGravity() * -1.0);

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
   this->setFuel(this->getFuel() - 1);
}
