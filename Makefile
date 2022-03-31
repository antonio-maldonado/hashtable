#http://www.cplusplus.com/forum/unices/12499/#msg59885
CC           = g++
CFLAGS   = -ansi -Wall
LDFLAGS = 

all: test clean

test: main.o List.o Node.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: inicial2.cpp
	$(CC) -o $@ -c $(CFLAGS) $<

List.o: libs/List.cpp libs/List.h
	$(CC) -o $@ -c $(CFLAGS) $<

Node.o: libs/Node.cpp libs/Node.h
	$(CC) -o $@ -c $(CFLAGS) $<

.PHONY: clean cleanest

clean:
	rm *.o

cleanest: clean
	rm test


