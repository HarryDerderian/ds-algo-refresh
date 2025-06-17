#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
struct node
{
    node *next;
    T data;
};

template <typename T>
class LinkedList
{

public:
    LinkedList();

    LinkedList(T data);

    ~LinkedList();

    bool isEmpty() const;

    int getSize() const;

    void add(T data);

    bool contains(T data) const;

    T &get(int index) const;

    void clear();

    void remove(T data);

private:
    node<T> *head = nullptr;
    node<T> *tail = nullptr;
    int size = 0;
};
#include "LinkedList.cpp"

#endif
