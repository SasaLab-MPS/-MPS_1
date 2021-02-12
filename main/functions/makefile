PROGRAM = main
CC = g++
CFLAGS = -O2 -c
HEADER = ../functions.hpp ../inputs.hpp
SUMMARY =  $(CC) $(CFLAGS) $^ $(HEADER)

ALL : fun1 fun2 fun3 fun4 fun5 fun6 fun7 fun8 fun9 fun10 fun11 fun12 fun13 fun14 fun15 fun16 fun17 fun18 fun19 fun20 fun21 fun22 fun23 fun24 fun25


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

fun9 : moveParticle.cpp
	$(SUMMARY)

fun10 : collision.cpp
	$(SUMMARY)

fun11 : calPressure.cpp
	$(SUMMARY)

fun12 : calNumberDensity.cpp
	$(SUMMARY)

fun13 : setBoundaryCondition.cpp
	$(SUMMARY)

fun14 : setSourceTerm.cpp
	$(SUMMARY)

fun15 : setMatrix.cpp
	$(SUMMARY)

fun16 : exceptionalProcessingForBoundaryCondition.cpp
	$(SUMMARY)

fun17 : checkBoundaryCondition.cpp
	$(SUMMARY)

fun18 : increaseDiagonalTerm.cpp
	$(SUMMARY)

fun19 : solveSimultaniousEquationsByGaussEliminationMethod.cpp
	$(SUMMARY)

fun20 : removeNegativePressure.cpp
	$(SUMMARY)

fun21 : setMinimumPressure.cpp
	$(SUMMARY)

fun22 : calPressureGradient.cpp
	$(SUMMARY)

fun23 : moveParticleUsingPressureGradient.cpp
	$(SUMMARY)

fun24 : writeData_inProfFormat.cpp
	$(SUMMARY)

fun25 : writeData_inVtuFormat.cpp
	$(SUMMARY)