#ifndef BIRDSACRED_H
#define BIRDSACRED_H

#include "Bird.h"

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