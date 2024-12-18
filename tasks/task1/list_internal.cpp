#include "list.h"
#include <iostream>


void
List::print() {
    if (is_empty()) return;
    Node* p = first;
    while (p) {
        std::cout << p->val << "->";
        p = p->next;
    }
    std::cout << std::endl;
}


Node*
List::operator[] (const int index) {
    if (is_empty()) return nullptr;
    Node* p = first;
    for (int i = 0; i < index; i++) {
        p = p->next;
        if (!p) return nullptr;
    }
    return p;
}
