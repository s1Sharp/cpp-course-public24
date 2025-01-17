#include "list.h"
#include <iostream>


List::List() : first(nullptr), last(nullptr) {}


bool List::is_empty() {
    return first == nullptr;
}


void List::clear() {
    while (!is_empty()) {
        remove_front();
    }
}


void List::push_front(int _val) {
    Node* newNode = new Node(_val);
    newNode->next = first;
    first = newNode;

    if (!last) { 
        last = newNode;
    }
}


void List::push_back(int _val) {
    Node* newNode = new Node(_val);
    if (last) {
        last->next = newNode;
    } else { 
        first = newNode;
    }
    last = newNode;
}


Node* List::find(int _val) {
    Node* current = first;
    while (current) {
        if (current->val == _val) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}


void List::remove_front() {
    if (is_empty()) return; 

    Node* temp = first;
    first = first->next;
    delete temp;

    if (!first) { 
        last = nullptr;
    }
}


void List::remove_back() {
    if (is_empty()) return; 

    if (first == last) { 
        delete first;
        first = last = nullptr;
        return;
    }

    Node* current = first;
    while (current->next != last) {
        current = current->next;
    }

    delete last;
    last = current;
    last->next = nullptr;
}


bool List::remove(const Node* _node) {
    if (!_node || is_empty()) return false;

    if (_node == first) { 
        remove_front();
        return true;
    }

    Node* current = first;
    while (current->next && current->next != _node) {
        current = current->next;
    }

    if (current->next == _node) { 
        Node* temp = current->next;
        current->next = temp->next;

        if (temp == last) { 
            last = current;
        }

        delete temp;
        return true;
    }

    return false; 
}