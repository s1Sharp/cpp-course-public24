CC=g++

simple: main.o simple.o
	$(CC) -o simple main.o simple.o

main.o: main.cpp simple.h
	$(CC) -c main.cpp

simple.o: simple.cpp simple.h
	$(CC) -c simple.cpp

clean:
	rm -rf simple simple.exe *.o
