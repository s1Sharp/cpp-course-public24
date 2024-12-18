#include <algorithm>
#include <iostream>
#include <vector>

// Motivation

struct Lookup {
	explicit Lookup(int v) : m_value{v} {
	}

	void operator()(int entry) {
		if (entry == m_value) {
			std::cout << "Found!" << std::endl;
		}
	}

private:
	int m_value;
};

void lookupAndPrint(const std::vector<int> &values, int v) {

	std::for_each(values.begin(), values.end(), Lookup{v});
}

struct Closure {
	explicit Closure(int z_) : z(z_){};

	int operator()(int a, int b) {
		return z + a + b;
	}

	int z;
};

// Basic
void example_1() {

	Closure cl(100);
	std::cout << cl(1, 2) << std::endl;
}

// Easy
void example_2() {

	std::cout << Closure(100)(1, 2) << std::endl;
}

struct Closure2 {
	explicit Closure2(int z_) : z(z_){};

	int operator()(int a, int b) {
		return z + a + b;
	}

	int z;
};

// Middle
void example_3() {
	// [z=100] - capture with initialize (since C++14)
	auto closure = [z = 100](int a, int b) { return z + a + b; };
	std::cout << closure(1, 2) << std::endl;

	auto closure2 = [](int a, int b, int c) {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return a + b + c;
	};
	closure2(1, 2, 3);

	// lambda expression
	// [z=100](int a, int b) { return z + a + b; };

	// f - closure
	// auto f = [z=100](int a, int b) { return z + a + b; };

	// closure class
	// class lambda_x123dalsd033j1230a;
}

// Hard
void example_4() {

	std::cout << [z = 100](int a, int b) { return z + a + b; }(1, 2) << std::endl;

	std::vector<int> values = {0, 1, 2, 3, 3, 3, 4, 5, 6};
	std::for_each(
		values.begin(),
		values.end(),
		[value = 3](int entry) {
			if (entry == value)
				std::cout << "Found!" << std::endl;
		});

	int value = 3;
	std::for_each(
		values.begin(),
		values.end(),
		[value](int entry) {
			if (entry == value)
				std::cout << "Found!" << std::endl;
		});

	auto closure = [z = 100](int a, int b) mutable -> int { z = 150; return a + b + z; };
	closure(1, 2);

	auto closure2 = [z = 100](int a, int b) mutable -> decltype(a + b) { z = 150; return a + b + z; };
	closure2(2, 3);

	auto closure3 = [](auto a, auto b) { return a + b; };
	std::cout << closure3(1.5, 2.7) << std::endl;

	std::cout << "value = " << value << std::endl;
	auto closure4 = [&value]() { value = 100; };
	closure4();
	std::cout << "value = " << value << std::endl;
}

int main() {

	std::vector<int> values = {0, 1, 2, 3, 3, 3, 4, 5, 6};
	lookupAndPrint(values, 3);

	example_1();
	example_2();
	example_3();
	example_4();

	return 0;
}
