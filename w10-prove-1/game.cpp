/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

 // These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
#include "game.h"
#include <vector>
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5

/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game::Game(Point tl, Point br)
   : topLeft(tl), bottomRight(br)
{
   // Set up the initial conditions of the game
   score = 0;
   ship.topLeft = tl;
   ship.bottomRight = br;
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   //remove any allocated bullet...
   for (int i = 0; i <= bullets.size() - 1 ; i++)
   {
      if (bullets[i] != NULL)
      {
         delete bullets[i];

         bullets[i] = NULL;
      }
   }
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game::advance()
{
   ship.advance();
   advanceBullets();
   advanceShip();
   handleCollisions();
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game::advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i] != NULL && bullets[i]->isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i]->advance();

         if (!isOnScreen(bullets[i]->getPoint()))
         {
            // the bullet has left the screen
            bullets[i]->kill();
         }
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE SHIP
 *
 * 1. If there is a bird, and it's alive, advance it
 **************************************************************************/
void Game::advanceShip()
{
   // we have a bird, make sure it's alive
   if (ship.isAlive())
   {
      // move it forward
      ship.advance();
   }
}

/**************************************************************************
 * GAME :: CREATE BIRD
 * Create a bird of a random type according to the rules of the game.
 **************************************************************************/
 //Bird* Game::createBird()
 //{
 //   Bird* newBird = NULL;
 //
 //   int nextBirdType = random(0, 2);
 //
 //   switch (nextBirdType)
 //   {
 //   case 0:
 //      newBird = new BirdNormal;
 //      break;
 //   case 1:
 //      newBird = new BirdTough;
 //      break;
 //   case 2:
 //      newBird = new BirdSacred;
 //      break;
 //   }
 //
 //   return newBird;
 //}

 /**************************************************************************
  * GAME :: IS ON SCREEN
  * Determines if a given point is on the screen.
  **************************************************************************/
bool Game::isOnScreen(const Point& point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game::handleCollisions()
{
   //// now check for a hit (if it is close enough to any live bullets)
   //for (int i = 0; i < bullets.size(); i++)
   //{
   //   if (bullets[i].isAlive())
   //   {
   //      // this bullet is alive, see if its too close

   //      // check if the bird is at this point (in case it was hit)
   //      if (bird != NULL && bird->isAlive())
   //      {
   //         // BTW, this logic could be more sophisiticated, but this will
   //         // get the job done for now...
   //         if (fabs(bullets[i].getPoint().getX() - bird->getPoint().getX()) < CLOSE_ENOUGH
   //            && fabs(bullets[i].getPoint().getY() - bird->getPoint().getY()) < CLOSE_ENOUGH)
   //         {
   //            //we have a hit!

   //            // hit the bird
   //            int points = bird->hit();
   //            score += points;

   //            // the bullet is dead as well
   //            bullets[i].kill();
   //         }
   //      }
   //   } // if bullet is alive

   //} // for bullets
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects take bullets out of the list
 **************************************************************************/
void Game::cleanUpZombies()
{
   // Look for dead bullets
   vector<Bullet*>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet* pBullet = *bulletIt;

      if (!pBullet->isAlive())
      {
         bulletIt = bullets.erase(bulletIt);

         delete pBullet;
         pBullet = NULL;
      }
      else
      {
         bulletIt++; // advance
      }
   }
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game::handleInput(const Interface& ui)
{
   ship.setThrust(false);

   if (ui.isLeft())
   {
      ship.moveRight();
   }

   if (ui.isRight())
   {
      ship.moveLeft();
   }

   if (ui.isUp())
   {
      ship.setThrust(true);
      ship.applyThrustTop();
   }

   if (ui.isDown())
   {
      ship.applyThrustBottom();
   }

   if (ui.isSpace()) // Spacebar Key
   {
      Bullet * newBullet = new Bullet;
      newBullet->fire(ship.getPoint(), ship.getAngle());
      bullets.push_back(newBullet);
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game::draw(const Interface& ui)
{
   ship.draw();

   // draw the bullets, if they are on screen (alive)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i] != NULL && bullets[i]->isAlive())
      {
         bullets[i]->draw();
      }
   }

   // Put the score on the screen
   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);

   drawNumber(scoreLocation, score);
}

// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
 /*
 float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
 {
    // find the maximum distance traveled
    float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
    dMax = max(dMax, abs(obj2.getVelocity().getDx()));
    dMax = max(dMax, abs(obj2.getVelocity().getDy()));
    dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

    float distMin = std::numeric_limits<float>::max();
    for (float i = 0.0; i <= dMax; i++)
    {
       Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                      obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
       Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                      obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));

       float xDiff = point1.getX() - point2.getX();
       float yDiff = point1.getY() - point2.getY();

       float distSquared = (xDiff * xDiff) +(yDiff * yDiff);

       distMin = min(distMin, distSquared);
    }

    return sqrt(distMin);
 }
 */

