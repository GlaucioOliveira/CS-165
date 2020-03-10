#include "birdSacred.h"

#define BIRD_COLOR_GREEN 2
#define BIRD_PONTUATION 5
#define BIRD_SPEED 2
#define BIRD_SIZE 12

BirdSacred::BirdSacred() 
{
   setPoint(Point(-200, random(-200, 200)));
   velocity.setDx(this->velocity.getDx() + BIRD_SPEED);
   
   alive = true;
}

void BirdSacred::draw()
{
   drawSacredBird(point, BIRD_SIZE);
}

int BirdSacred::hit()
{
   this->kill();

   return BIRD_PONTUATION;
}
