#include <iostream>
#include <vector>

// ---
void testPlacing() {
	std::cout << "\ntestPlacing\n";

	int stackVariable = 0;
	std::vector<int> values = {0, 1, 2, 3};

	std::cout << "&stackVariable = " << &stackVariable << std::endl;
	std::cout << "&values        = " << &values << std::endl;
	std::cout << "values.data()  = " << values.data() << std::endl;

	for(auto& v : values)
		std::cout << v << ' ';
	std::cout << std::endl;
}

// // Неэффективно...
void testReallocate() {
	std::cout << "\ntestReallocate\n";

	int stackVariable = 0;
	std::vector<int> values;

	auto capacity = values.capacity();
	std::cout << '[' << 0 << ']' << " capacity = " << values.capacity() << std::endl;
	for (int i=0; i<10000; ++i) {
		if (capacity != values.capacity()) {
			std::cout << '[' << i << ']' << " capacity = " << values.capacity() << std::endl;
			capacity = values.capacity();
		}
		values.push_back(i);
	}
	std::cout << std::endl;

	std::cout << "&stackVariable = " << &stackVariable << std::endl;
	std::cout << "&values        = " << &values << std::endl;
	std::cout << "values.data()  = " << values.data() << std::endl;
}

void testReserve() {
	std::cout << "\ntestReserve\n";

	const int count = 100;
	std::vector<int> values;

	values.reserve(count);
	std::cout << "capacity = " << values.capacity() << std::endl;

	for (int i=0; i<count/2; ++i)
		values.push_back(i);

	std::cout << "capacity = " << values.capacity() << std::endl;

	std::cout << "shrink_to_fit" << std::endl;
	values.shrink_to_fit();

	std::cout << "capacity = " << values.capacity() << std::endl;
	
	std::cout << "one more" << std::endl;
	values.push_back(42);

	std::cout << "capacity = " << values.capacity() << std::endl;
}

void testIterator() {
	std::cout << "\ntestIterator\n";

	std::vector<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	std::cout << "capacity = " << values.capacity() << std::endl;

	auto iter = std::next(values.cbegin(), 3);
	std::cout << *iter << std::endl;

	++iter;
	std::cout << *iter << std::endl;

	--iter;
	--iter;
	std::cout << *iter << std::endl;

	iter += 3;
	std::cout << *iter << std::endl;

	auto iterPos = std::distance(values.cbegin(), iter);
	std::cout << "iterPos = " << iterPos << std::endl;

	std::cout << "one more" << std::endl;
	values.push_back(42);	
	std::cout << "capacity = " << values.capacity() << std::endl;

	std::cout << "&values[0]       = " << &values[0] << std::endl;
	std::cout << "&values[iterPos] = " << &values[iterPos] << std::endl;
	
	// Ooops. Iterator is invalid.
	// std::cout << "&*iter           = " << &*iter << std::endl;

	auto iter2 = std::next(values.cbegin(), 3);
	std::cout << "*iter2 = " << *iter2 << std::endl;
	std::cout << "one more at the begining" << std::endl;
	values.insert(values.cbegin(), 42);

	// Ooops. Iterator is invalid.
	// std::cout << "*iter2 = " << *iter2 << std::endl;
}


struct SomeStruct {

	SomeStruct(int value) : m_value{value} {

	}

	SomeStruct(const SomeStruct& other) 
		: m_value{other.m_value} {
		std::cout << '[' << m_value << "] copy!" << std::endl;
	}

	SomeStruct(SomeStruct&& other)
		: m_value{other.m_value} {
		std::cout << '[' << m_value << "] move!" << std::endl;
	}

	SomeStruct& operator=(SomeStruct&& other) {
		m_value = other.m_value;
		std::cout << '[' << m_value << "] operator= move!" << std::endl;
		return *this;
	}

	SomeStruct& operator=(const SomeStruct& other) {
		m_value = other.m_value;
		std::cout << '[' << m_value << "] operator= copy!" << std::endl;
		return *this;
	}
private:
	int m_value;
};

void testCustomReallocate() {
	std::cout << "\ntestCustomReallocate\n";
	std::vector<SomeStruct> values;

	for (int i=0; i<5; ++i) {
		std::cout << "capacity = " << values.capacity() << std::endl;
		SomeStruct entry{i};
		values.push_back(entry);
	}
}

int main() {
	testPlacing();
	testReallocate();
	testReserve();
	testIterator();
	testCustomReallocate();
}