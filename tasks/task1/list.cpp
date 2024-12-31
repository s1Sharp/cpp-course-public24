#include "list.h"

List::List()
:   first(nullptr),
    last(nullptr)
{
}

bool List::is_empty()
{
    return first == nullptr;
}

void List::clear()
{
    while (first != nullptr) {
        remove_back();
    }
}

void List::push_front(int _val)
{
    Node* recent_node = new Node(_val);

    if (first == nullptr) {
        first = recent_node;
        last = recent_node;

    }
    else {
        recent_node->next = first;
        first = recent_node;
    }
}

void List::push_back(int _val)
{
    Node* recent_node = new Node(_val);

    if (first == nullptr) {
        first = recent_node;
        last = recent_node;
    }

    else {
        last->next = recent_node;
        last = recent_node;
    }
}

Node* List::find(int _val)
{
    Node* current = first;

    while (current != nullptr) {
        if (current->val == _val) {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

void List::remove_front()
{
    if (first == nullptr) {
        return;
    }

    Node* temp = first;
    first = first->next;

    if (first == nullptr) {
        last = nullptr;
    }

    delete temp;
}

void List::remove_back()
{
    if (first == nullptr) {
        return;
    }

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

bool List::remove(const Node* _node)
{
    if (_node == nullptr || first == nullptr) {
        return false;
    }

    if (_node == first) {
        remove_front();
        return true;
    }

    Node* current = first;

    while (current->next != nullptr && current->next != _node) {
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