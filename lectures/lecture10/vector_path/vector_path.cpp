/*
Напишите функцию PrintVectorPart, принимающую вектор целых чисел numbers,
	выполняющую поиск первого отрицательного числа в нём и выводящую в стандартный вывод
	все числа, расположенные левее найденного, отсортированные в обратном порядке.
Если вектор не содержит отрицательных чисел,
	выведите все числа в обратном порядке без сортировки.
*/

#include <iostream>
#include <vector>
#include <algorithm>


template </* тут ещё что-то нужно написать :) */>
// std::vector<T>& numbers - или так если вы сделаете иную реализацию
void PrintVectorPart(std::vector<T>&& numbers) {

}

int main()
{
	PrintVectorPart<int>({ 6, 1, 8, -5, 4 });  //  1 6 8
	std::cout << std::endl;
	PrintVectorPart<int>({ -6, 1, 8, -5, 4 });  //  ничего не выведется
	std::cout << std::endl;
	PrintVectorPart<int>({ 6, 1, 8, 5, 4 });  //  4 5 8 1 6
	std::cout << std::endl;
	return 0;
}