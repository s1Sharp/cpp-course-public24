#include "list.h"


List::List() : 
    first(nullptr), last(nullptr)
    {}


bool List::is_empty()
{
    return first == nullptr; 
}


void List::clear()
{
    while (!is_empty()) { remove_back(); }
}



void
List::push_front(int val)
{
    Node* newNode = new Node(val); // Создаем новый узел
    if (is_empty()) {
        first = last = newNode; // Если список пуст, новый узел становится и первым, и последним
    } 
    else {
        newNode->next = first;
        first = newNode;
    }
}


void List::push_back(int val)
{
    Node* newNode = new Node(val); // Создаем новый узел
    if (is_empty()) {
        first = last = newNode; // Если список пуст, новый узел становится и первым, и последним
    } 
    else {
        last->next = newNode; 
        last = newNode; 
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
    if (is_empty()) return;
    if (first == last) { // Если в списке только один элемент
        first = nullptr; 
        last = nullptr; 
    } 
    else {
        Node* current = first;
        first = first->next;
        delete current;
    }
}


void List::remove_back()
{
    if (!is_empty()) {
        if (first == last) { // Если в списке только один элемент
            delete first; 
            first = last = nullptr; 
        } 
        else {
            Node* current = first;
            while (current->next != last) { // Находим предпоследний элемент
                current = current->next;
            }
            delete last; 
            last = current; // Обновляем указатель last на предпоследний элемент
            last->next = nullptr; // Обнуляем указатель next у нового последнего элемента
        }
    }
}


bool List::remove(const Node* _node)
{
    if (is_empty() || _node == nullptr) return false; 
    
    if (_node == first) { 
        remove_front();
        return true;
    }

    Node* current = first;
    while (current != nullptr && current->next != _node) {
        current = current->next;
    }

    if (current != nullptr) {
        current->next = _node->next; // Пропускаем узел для удаления
        delete _node; // Удаляем узел 
        return true;
    }
    
    return false; 
}
