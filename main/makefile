PROGRAM = main
OBJS = headerfiles/array.o headerfiles/dist.o headerfiles/func.o
CC = gcc
CFLAGS = -O2

$(PROGRAM): $(PROGRAM).o $(OBJS)
   $(CC) -o $(PROGRAM) $(PROGRAM).o $(OBJS) -lm

$(OBJS) $(PROGRAM).o: header.h

clean:
   rm -f *.o headerfiles/*.o