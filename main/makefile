PROGRAM = main
OBJS = functions/array.o functions/dist.o functions/func.o
CC = g++
CFLAGS = -O2

$(PROGRAM): $(PROGRAM).o $(OBJS)
   $(CC) -o $(PROGRAM) $(PROGRAM).o $(OBJS) -lm

$(OBJS) $(PROGRAM).o: functions.hpp

clean:
   rm -f *.o headerfiles/*.o