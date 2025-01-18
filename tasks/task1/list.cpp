#include "list.h"
#include <iostream>

List::List() : first(nullptr), last(nullptr) {}

bool List::is_empty() {
    return first == nullptr;
}

void List::clear() {
    while (first) {
        remove_front();
    }
}

void List::push_front(int _val) {
    Node* new_node = new Node(_val);
    if (is_empty()) {
        first = last = new_node;
    } else {
        new_node->next = first;
        first = new_node;
    }
}

void List::push_back(int _val) {
    Node* new_node = new Node(_val);
    if (is_empty()) {
        first = last = new_node;
    } else {
        last->next = new_node;
        last = new_node;
    }
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

    Node* to_delete = first;
    first = first->next;
    delete to_delete;

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
    if (is_empty() || !_node) return false;

    if (_node == first) {
        remove_front();
        return true;
    }

    Node* current = first;
    while (current->next && current->next != _node) {
        current = current->next;
    }

    if (current->next == _node) {
        Node* to_delete = current->next;
        current->next = to_delete->next;
        if (to_delete == last) { 
            last = current;
        }
        delete to_delete;
        return true;
    }
    return false;
}