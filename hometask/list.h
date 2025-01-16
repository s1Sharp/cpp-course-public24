#ifndef LIST_H
#define LIST_H

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int value) : val(value), prev(nullptr), next(nullptr) {}
};

class List {
private:
    Node* head;
    Node* tail;
    int size;

public:
    List();
    ~List();

    void push_front(int val); 
    void push_back(int val);
    void pop_front();
    void pop_back();
    void remove(int val);
    void clear();
    Node* find(int val);
    bool is_empty();
};

#endif