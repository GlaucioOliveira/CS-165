###############################################################
# Program:
#     Checkpoint 06a, Makefiles
#     Brother Walker, CS165
# Author:
#     Glaucio Oliveira
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


# Insert your rule for a.out here:
a.out: check06a.o robot.o point.o
	g++ -o a.out check06a.o robot.o point.o
	tar -cf check06a.tar *.h *.cpp makefile
	
# Insert your rule for robot.o here:
robot.o: robot.cpp robot.h
	g++ -c robot.cpp

# Insert your rule for point.o here:
point.o: point.cpp point.h
	g++ -c point.cpp

# Insert your rule for check06a.o here:
check06a.o: check06a.cpp robot.h
	g++ -c check06a.cpp

### the main rule
#a.out: complexTest.o complex.o
#g++ -o a.out complexTest.o complex.o
#tar -cf example14.tar *.h *.cpp makefile
### for the object files
#complexTest.o: complexTest.cpp complex.h
#g++ -c complexTest.cpp
#complex.o: complex.cpp complex.h
#g++ -c complex.cpp