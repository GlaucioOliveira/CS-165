/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H

 // TODO: Fill in this class
 // Put all of your method bodies right in this file
template <class T1, class T2>
class Pair
{
public:
   void setFirst(T1 first) {
      t1 = first;
   };

   void setSecond(T2 second) {
      t2 = second;
   };

   T1 getFirst() const {
      return t1;
   };

   T2 getSecond() const {
      return t2;
   };

   void display() 
   {
      cout << t1 << " - " << t2 << endl;
   }

private:
   T1 t1;
   T2 t2;
};

#endif // PAIR_H
