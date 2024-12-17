CC=g++

all: read write

read: fileReader.cpp
	$(CC) -o reader fileReader.cpp
	./reader

write: fileWritter.cpp
	$(CC) -o writer fileWritter.cpp
	./writer

clean:
	rm -rf *.o writer reader	
