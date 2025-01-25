#include "list.h"
#include <iostream>

List::List() : head(nullptr), tail(nullptr), size(0) {}

List::~List() {
    clear();
}

void List::push_front(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void List::push_back(int val) {
    Node* newNode = new Node(val);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void List::pop_front() {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    size--;
}

void List::pop_back() {
    if (tail == nullptr) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    size--;
}

void List::remove(int val) {
    Node* current = head;
    while (current != nullptr) {
        if (current->val == val) {
            if (current == head) {
                pop_front();
            } else if (current == tail) {
                pop_back();
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                size--;
            }
            return;
        }
        current = current->next;
    }
}

void List::clear() {
    while (head != nullptr) {
        pop_front();
    }
}

Node* List::find(int val) {
    Node* current = head;
    while (current != nullptr) {
        if (current->val == val) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

bool List::is_empty() {
    return head == nullptr;
}