#ifndef BIRDTOUGH_H
#define BIRDTOUGH_H

#include "bird.h"

/*********************************************
 * Tough Bird (needs more then one hit to kill)
 *********************************************/
class BirdTough : public Bird
{
public:
   BirdTough();

   void draw();

   int hit();

private:
   int hitsReceived;
};

#endif