#include <iostream>
#include "list.h"

int main() {
    List list;

    
    list.push_front(10);
    list.push_back(20);
    list.push_front(5);

    
    std::cout << "Initial list: ";
    list.print();

    
    Node* found = list.find(10);
    if (found) {
        std::cout << "Found value: " << found->val << std::endl;
    }

    
    list.remove_front();
    std::cout << "After removing front: ";
    list.print();

    
    list.remove_back();
    std::cout << "After removing back: ";
    list.print();

    
    list.clear();
    std::cout << "After clearing the list: ";
    list.print();

    return 0;
}