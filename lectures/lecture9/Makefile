CC_OPTIONS = g++

all: optional run

optional: optional.o
	$(CC_OPTIONS) optional.o -o  optional

optional.o: optional.cpp
	$(CC_OPTIONS) -c optional.cpp

clear:
	rm -rf *.o optional
	clear

run: optional
	./optional