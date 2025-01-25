#include "list.h"
#include <iostream>

int main() {
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(5);

    Node* found = list.find(2);
    if (found) {
        std::cout << "Найден: " << found->val << std::endl;
    } else {
        std::cout << "Не найден" << std::endl;
    }

    list.remove(1);

    if (list.is_empty()) {
        std::cout << "Список пустой" << std::endl;
    } else {
        std::cout << "Список не пустой" << std::endl;
    }
    list.clear();

    return 0;
}