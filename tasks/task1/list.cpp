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
    while(first)
    {
        remove_front();
    }

    first = last = nullptr;
}



void
List::push_front(int _val)
{
    Node* newNode = new Node(_val);
    if(is_empty())
    {
        first = last = newNode;
    }
    else
    {
        newNode -> next = first;
        first = newNode;
    }
}


void
List::push_back(int _val)
{
    Node* newNode = new Node(_val);
    if (is_empty())
    {
        first = last = newNode;
    }
    else
    {
        last -> next = newNode;
        last = newNode;
    }
}


Node*
List::find(int _val)
{
    Node* currentVal = first;
    while (currentVal != nullptr)
    {
        if (currentVal -> val == _val)
        {
            return currentVal;
        }

        currentVal = currentVal -> next;

    }

    return nullptr;
}


void
List::remove_front()
{
    if (!is_empty())
    {
        Node* temp = first;
        first = first -> next;
        delete temp;
    }
    else
    {
        last = nullptr;
    }
}


void
List::remove_back()
{
    if (is_empty())
    {
        return;
    }
    
    if (first == last)
    {
        first = last = nullptr;
    }
    else
    {
        Node* temp = first;
        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;
        last -> next = nullptr;
    }
}


bool
List::remove(const Node* _node)
{
    if (is_empty())
    {
        return false;
    }

    if (first == _node)
    {
        remove_front();
        return true;
    }

    Node* currentVal = first;
    while (currentVal -> next != nullptr)
    {
        if (currentVal -> next == _node)
        {
            Node* temp = currentVal -> next;
            currentVal -> next = temp -> next;

            if (temp == last)
            {
                last = currentVal;
            }

            delete temp;
            return true;
        }

        currentVal = currentVal -> next;
    }

    return false;
}
