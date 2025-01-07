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
    while (first) {
        remove_back();
    }
}



void
List::push_front(int _val)
{
    Node* value = new Node(_val);
    if (first == nullptr){
        first = last = value;
    } else {
        value->next = first;
        first = value;
    }
}


void
List::push_back(int _val)
{
    Node* value = new Node(_val);
    if (first == nullptr){
        first = last = value;
    } else {
        last->next = value;
        last = value;
    }
}


Node*
List::find(int _val)
{
    Node* crnt = first;
    while (crnt != nullptr){
        if (crnt->val == _val){
            return crnt;
        }
        crnt = crnt->next;
    }
     return nullptr;
}


void
List::remove_front()
{
    if (first == nullptr){
        last = nullptr;
        return;
    }else{
        Node* tmp = first;
        first = first->next;
        delete tmp;
    }   
}


void
List::remove_back()
{
    if (first == nullptr){
        last = nullptr;
        return;
    } else if (first == last){
        delete first;
        first = last = nullptr;
        return;
    } 
    Node* val = first;
    while (val->next != last) {
        val = val->next;
    }
    delete last;            
    last = val;   
    last->next = nullptr;  
}


bool
List::remove(const Node* _node)
{
    if (first == nullptr) {
        return false;
    } else if (first == _node)
    {
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
