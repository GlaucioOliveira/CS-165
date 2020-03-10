#include "birdTough.h"

#define BIRD_COLOR_BLUE 3
#define BIRD_PONTUATION 5
#define BIRD_SPEED 1.5
#define BIRD_SIZE 12
#define BIRD_STRENGTH 3

BirdTough::BirdTough()
{
   setPoint(Point(-200, random(-200, 200)));
   velocity.setDx(this->velocity.getDx() + BIRD_SPEED);

   alive = true;
   hitsReceived = 0;
}

void BirdTough::draw()
{
   drawToughBird(point, BIRD_SIZE, (BIRD_STRENGTH - hitsReceived));
}

//The tough bird will only be killed when the amounts of hits
//is equal to its 'strength'.
int BirdTough::hit()
{
   hitsReceived +=1;

   if (hitsReceived == BIRD_STRENGTH)
   {
      kill();
      return BIRD_PONTUATION;
   }
   else
   {
      return 1;
   }
}
