###############################################################
# Program:
#     Project 09, Skeet
#     Brother Walker, CS165
# Author:
#     Glaucio Oliveira
# Summary:
#     Skeet game implementation in C++.
# Above and Beyond 
#     Added a color to a normal bird. 
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o bird.o birdNormal.o birdTough.o birdSacred.o bullet.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o bird.o birdNormal.o birdTough.o birdSacred.o bullet.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
#	 bird.o		   abstract class for birds
#	 velocity.o	   Handles the velocity of objects
#	 bullet.o	   Handles the bullet
#    birdNormal.o   Handles a bird of the type normal
#    birdTough.o   Handles a bird of the type tough
#    birdSacred.o   Handles a bird of the type sacred
###############################################################

uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bird.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

bird.o: bird.h point.h bird.cpp
	g++ -c bird.cpp

bullet.o: bullet.h point.h bullet.cpp
	g++ -c bullet.cpp

velocity.o: velocity.h velocity.cpp	
	g++ -c velocity.cpp

flyingObject.o: flyingObject.h point.h velocity.h flyingObject.cpp
	g++ -c flyingObject.cpp

birdNormal.o: birdNormal.h birdNormal.cpp bird.h
	g++ -c BirdNormal.cpp

birdTough.o: birdTough.cpp birdTough.h bird.h
	g++ -c birdTough.cpp

birdSacred.o: birdSacred.cpp birdSacred.h bird.h
	g++ -c birdSacred.cpp



###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
