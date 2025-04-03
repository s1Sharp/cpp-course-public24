CC=g++


config:
	cmake -B ./build -DCMAKE_BUILD_TYPE=Release

build: config
	cmake --build ./build --target figure_example --config Release

all: build
	./build/figure_example

show: build
	clear
	@echo "ADD RECT 2 3\n" \
		  "ADD TRIANGLE 3 4 5\n" \
		  "ADD CIRCLE 5\n" \
		  "PRINT\n" \
	| ./build/figure_example

clean:
	rm -rf *.o build/
