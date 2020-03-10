#ifndef BIRDNORMAL_H
#define BIRDNORMAL_H

#include "bird.h"

/*********************************************
 * Normal Bird
 *********************************************/
class BirdNormal : public Bird
{
public:
   BirdNormal();

   void draw();

   int hit();

private:

};

#endif