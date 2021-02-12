PROGRAM = main
OBJS = functions/initializeParticlePositionAndVelocity_for2dim.o functions/initializeParticlePositionAndVelocity_for3dim.o functions/calConstantParameter.o
CC = g++
CFLAGS = -O2

$(PROGRAM): $(PROGRAM).o $(OBJS)
   $(CC) -o $(PROGRAM) $(PROGRAM).o $(OBJS) -lm

$(OBJS) $(PROGRAM).o: functions.hpp inputs.hpp

clean:
   rm -f *.o headerfiles/*.o
