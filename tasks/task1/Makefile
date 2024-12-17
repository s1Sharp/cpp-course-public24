.PHONY: test build

config:
	cmake -B ./build -DCMAKE_BUILD_TYPE=Release

build: config
	cmake --build ./build --target tests_run --config Release

test: build build/tests_run
	build/tests_run

clean:
	rm -rf build/