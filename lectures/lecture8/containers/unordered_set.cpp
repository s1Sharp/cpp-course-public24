#include <iostream>
#include <string>
#include <unordered_set>

void testUnique() {
	std::cout << "\ntestUnique\n";

	std::unordered_set<int> values;

	auto result = values.insert(42);
	std::cout << *result.first << " inserted: " << result.second << std::endl;

	result = values.insert(42);
	std::cout << *result.first << " inserted: " << result.second << std::endl;
}

void testOrder_ints() {
	std::cout << "\ntestOrder ints\n";

	std::unordered_set<int> values;
	for (int i=0; i<10; ++i)
		values.insert(i);

	for (auto& v : values) 
		std::cout << v << ' ';
	std::cout << std::endl;
}

void testOrder_strings() {
	std::cout << "\ntestOrder strings\n";

	std::unordered_set<std::string> values;
	for (int i=0; i<10; ++i)
		values.insert(std::to_string(i));

	for (auto& v : values) 
		std::cout << v << ' ';
	std::cout << std::endl;
}

int main() {
	testUnique();
	testOrder_ints();
	testOrder_strings();

	return 0;
}