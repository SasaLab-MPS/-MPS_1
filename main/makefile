# http://nao-bamboo.hatenablog.com/entry/2015/09/11/175832
PROGNAME := main
# INCDIR := include
# SRCDIR := src
LIBDIR := functions
HEADER = functions.hpp inputs.hpp
# OUTDIR := build
# TARGET := $(OUTDIR)/$(PROGNAME)
# SRCS := $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/$(LIBDIR)/*.c)
# OBJS := $(addprefix $(OUTDIR)/,$(patsubst %.c,%.o,$(SRCS)))
OBJS := $(wildcard $(LIBDIR)/*.o)
#$(warning $(OBJS))

CC = g++
CFLAGS = -Wall -O2

$(PROGNAME): $(PROGNAME).cpp
	$(CC) $(CFLAGS) -o $@ $^ $(OBJS) $(HEADER)


clean:
	rm -rf $(OUTDIR)