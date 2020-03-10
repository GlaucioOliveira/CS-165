#ifndef BIRD_H
#define BIRD_H

#include "point.h"
#include "flyingObject.h"
#include "uiDraw.h"

#define BIRD_PONTUATION 1
#define BIRD_SPEED 0.5
#define BIRD_SIZE 15

#define LEFT_POSITION -200
#define TOP_POSITION_MIN -200
#define TOP_POSITION_MAX 200

/*********************************************
 * Base class for a Bird with flying object
 * properties.
 *********************************************/
class Bird : public FlyingObject
{
public:
   Bird();

   virtual void draw() = 0;
   virtual int hit() = 0;

private:

};

#endif