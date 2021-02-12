PROGRAM = main
CC = g++
CFLAGS = -O2 -c
HEADER = ../functions.hpp ../inputs.hpp
SUMMARY =  $(CC) $(CFLAGS) $^ $(HEADER)

ALL : fun1 fun2 fun3 fun4 fun5 fun6 fun7 fun8


fun1 : initializeParticlePositionAndVelocity_for2dim.cpp 
	$(CC) $(CFLAGS) initializeParticlePositionAndVelocity_for2dim.cpp $(HEADER)

fun2 : initializeParticlePositionAndVelocity_for3dim.cpp
	$(CC) $(CFLAGS) initializeParticlePositionAndVelocity_for3dim.cpp $(HEADER)

fun3 : calConstantParameter.cpp
	$(CC) $(CFLAGS) calConstantParameter.cpp $(HEADER)

fun4 : calNZeroAndLambda.cpp
	$(CC) $(CFLAGS) calNZeroAndLambda.cpp $(HEADER)

fun5 : weight.cpp
	$(CC) $(CFLAGS) weight.cpp $(HEADER)

fun6 : mainLoopOfSimulation.cpp
	$(CC) $(CFLAGS) $^ $(HEADER)

fun7 : calGravity.cpp
	$(CC) $(CFLAGS) $^ $(HEADER)

fun8 : calViscosity.cpp
	$(SUMMARY)