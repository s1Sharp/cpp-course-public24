#include "list.h"


List::List()
{
    first = nullptr;
    last = nullptr;
}


bool
List::is_empty()
{
    return first == nullptr;
}


void
List::clear()
{
    Node* currentValue = first;
    while (currentValue != nullptr) {
        Node* deletedValue = currentValue;
        currentValue = currentValue->next;
        delete deletedValue;
    }
    first = last = nullptr;
}


void
List::push_front(int _val)
{   
    Node* pushValue = new Node(_val);
    pushValue->next = first;
    first = pushValue;

    if (last == nullptr) {
        last = pushValue;
    }
}


void
List::push_back(int _val)
{
    Node* pushValue = new Node(_val);
    if (is_empty()) {
        first = last = pushValue;
    } else {
        last->next = pushValue;
        last = pushValue;
    }
}


Node* 
List::find(int _val)
{
    Node* currentValue = first;
    while (currentValue != nullptr) {
        if (currentValue->val == _val) {
            return currentValue; 
        }
        currentValue = currentValue->next;
    }
    return nullptr;
}

void
List::remove_front()
{
    if (first != nullptr) {
        Node* tmp = first;
        first = first->next;
        delete tmp;
    } else {
        last = nullptr;
    }
}


void
List::remove_back()
{
    if (first == nullptr) {
        return;
    }

    if (first == last) {
        delete first;
        first = last = nullptr;
    } else {
        Node* currentValue = first;
        while (currentValue->next != last) {
            currentValue = currentValue->next;
        }
        delete last;            
        last = currentValue;   
        last->next = nullptr;  
    }
}


bool
List::remove(const Node* _node)
{
    if (first == nullptr) {
        return false;
    }

    if (first == _node) {
        Node* tmp = first;
        first = first->next;
        delete tmp;

        if (first == nullptr) {
            last = nullptr;
        }

        return true;
    }

    Node* currentValue = first;
    while (currentValue->next != nullptr) {
        if (currentValue->next == _node) {
            Node* tmp = currentValue->next;
            currentValue->next = currentValue->next->next;

            if (tmp == last) {
                last = currentValue;
            }

            delete tmp;
            return true;
        }
        currentValue = currentValue->next;
    }

    return false;
}
