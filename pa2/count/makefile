COMPILER = gcc
CCFLAGS  = -Wall -ansi -pedantic
all: count

count: count.c
	$(COMPILER) $(CCFLAGS) -o count count.c
clean:
	rm -f count.c count.o
