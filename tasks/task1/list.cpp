#include "list.h"
#include <iostream>

List::List() : first(nullptr), last(nullptr) {}

bool List::is_empty() {
    return first == nullptr;
}

void List::clear() {
    while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
    last = nullptr;
}

void List::push_front(int _val) {
    Node* newNode = new Node(_val);
    if (is_empty()) {
        first = last = newNode;
    } else {
        newNode->next = first;
        first = newNode;
    }
}

void List::push_back(int _val) {
    Node* newNode = new Node(_val);
    if (is_empty()) {
        first = last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

Node* List::find(int _val) {
    Node* current = first;
    while (current != nullptr) {
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

    if (first == nullptr) {
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
    if (is_empty() || _node == nullptr) return false;

    if (first == _node) {
        remove_front();
        return true;
    }

    Node* current = first;
    while (current->next != nullptr && current->next != _node) {
        current = current->next;
    }

    if (current->next == nullptr) return false;

    Node* temp = current->next;
    current->next = temp->next;
    if (temp == last) {
        last = current;
    }
    delete temp;
    return true;
}