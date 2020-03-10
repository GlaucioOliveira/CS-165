#ifndef BIRDSACRED_H
#define BIRDSACRED_H

#include "bird.h"

/*********************************************
 * Sacred Bird
 *********************************************/
class BirdSacred : public Bird
{
public:
   BirdSacred();

   void draw();

   int hit();

private:

};

#endif