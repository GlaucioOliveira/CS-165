#include <iostream>
using namespace std;


#ifndef VELOCITY_H
#define VELOCITY_H



 class  Velocity 
{
private:
   float dx;
   float dy;

public:
   /**************************
    * Getters and Setters
    **************************/
   float getDx() const { return dx; }
   float getDy() const { return dy; }

   void setDx(float dx) { this->dx = dx; }
   void setDy(float dy) { this->dy = dy; }

   /**************************
    * Public member functions
    **************************/
   void prompt();
   void display() const;

   inline friend Velocity operator - (const Velocity& lhs, const Velocity& rhs)
   {
      Velocity velocity;

      velocity.setDx(lhs.getDx() - rhs.getDx());
      velocity.setDy(lhs.getDy() - rhs.getDy());

      return velocity;
   };

   inline friend Velocity& operator -= (Velocity& lhs, const Velocity& rhs)
   {
      lhs = lhs - rhs;

      return lhs;
   };

};

Velocity operator + (const Velocity& lhs, const Velocity& rhs);
Velocity & operator += ( Velocity & lhs, const Velocity& rhs);

bool operator == (const Velocity& lhs, const Velocity& rhs);

bool operator != (const Velocity& lhs, const Velocity& rhs);

bool operator > (const Velocity& lhs, const Velocity& rhs);
bool operator < (const Velocity& lhs, const Velocity& rhs);

bool operator >= (const Velocity& lhs, const Velocity& rhs);
bool operator <= (const Velocity& lhs, const Velocity& rhs);

ostream & operator << (ostream & out, const Velocity & velocity);
istream &  operator >> (istream & in, Velocity & velocity);

Velocity & operator ++( Velocity & lhs);
Velocity& operator ++(Velocity& lhs, int postfix);
#endif
