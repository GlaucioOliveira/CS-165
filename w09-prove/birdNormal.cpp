#include "BirdNormal.h"
#define BIRD_COLOR_RED 1

BirdNormal::BirdNormal()
{
   setPoint(Point(LEFT_POSITION, random(TOP_POSITION_MIN, TOP_POSITION_MAX)));
   velocity.setDx(this->velocity.getDx() + BIRD_SPEED);

   alive = true;
}

void BirdNormal::draw()
{
   drawCircle(point, BIRD_SIZE, BIRD_COLOR_RED);
}

int BirdNormal::hit()
{
   kill();
   return BIRD_PONTUATION;
}
