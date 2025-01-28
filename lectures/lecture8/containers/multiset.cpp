#include <iostream>
#include <set>

void testUnique() {
	std::cout << "\ntestUnique\n";

	std::multiset<int> values;

	auto result = values.insert(42);
	std::cout << *result << std::endl;

	result = values.insert(42);
	std::cout << *result << std::endl;

	std::cout << "values.count(42) = " << values.count(42) << std::endl;

}

int main() {
	testUnique();
}
