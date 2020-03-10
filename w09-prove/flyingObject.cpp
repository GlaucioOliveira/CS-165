/*************************************************************
 * File: FlyingObject.cpp
 * Author: Liya Wang
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *************************************************************/
#include "FlyingObject.h"

 /*************************************************
 * Function: getPoint
 * Purpose: access to a point
 *************************************************/
Point FlyingObject::getPoint()
{
   return point;
}


/*************************************************
* Function: getVelocity
* Purpose: access to a velocity
*************************************************/

Velocity FlyingObject::getVelocity()
{
   return velocity;
}


/*************************************************
* Function: setPoint
* Purpose: change value in a point
*************************************************/
void FlyingObject::setPoint(Point point)
{
   this->point = point;
}

/******************************************************
* Function: setVelocity
* Purpose: change value in the velocity
*************************************************/
void FlyingObject::setVelocity(Velocity velocity)
{
   this->velocity = velocity;
}

/****************************************************
* Function: advance
* Purpose: will add velocity in the point
*************************************************/
void FlyingObject::advance()
{
   point.setX(point.getX() + velocity.getDx());
   point.setY(point.getY() + velocity.getDy());
}


/******************************************************
* Function: kill
* Purpose: see if the bird is killed
*************************************************/
void FlyingObject::kill()
{
   alive = false;
}

/******************************************************
* Function: isAlived
* Purpose: saccess to the bird's status
*************************************************/
bool FlyingObject::isAlive()
{
   return alive;
}



