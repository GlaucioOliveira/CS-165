#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10
#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#define SHIP_MOVE_AMOUNT 2

#include "flyingObject.h"
#include "uiDraw.h"


class Ship : public FlyingObject
{
   public:
   Ship();
   void draw();
   float getAngle() const { return _angle; }
   void applyGravity(float Gravity);
   float  getGravity() const;
   void moveLeft();
   void moveRight();
   bool getThrust();
   void setThrust(bool thrust);
   void applyThrustBottom();
   void applyThrustTop();
   void advance() override;

   private:
   float _angle;
   bool _thrust;
   bool _isMovingRight;
   bool _isMovingLeft;
   float _gravity;
};

#endif /* ship_h */
