#include <stdexcept>
#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
LinkedList<T>::LinkedList(T data)
{
    head = new node<T>;
    head->next = nullptr;
    head->data = data;
    tail = head;
    size = 1;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    node<T> *current = head;
    node<T> *tmp = nullptr;
    while (current)
    {
        tmp = current;
        current = current->next;
        delete tmp;
    }
    size = 0;
    tail = nullptr;
    head = nullptr;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
int LinkedList<T>::getSize() const
{
    return size;
}

template <typename T>
void LinkedList<T>::add(T data)
{
    if (head)
    {
        node<T> *tmp = tail;
        tail = new node<T>;
        tail->next = nullptr;
        tail->data = data;
        tmp->next = tail;
    }
    else
    {
        head = new node<T>;
        head->next = nullptr;
        head->data = data;
        tail = head;
    }
    ++size;
}

template <typename T>
bool LinkedList<T>::contains(T data) const
{
    node<T> *current = head;
    while (current)
    {
        if (current->data == data)
            return true;
        current = current->next;
    }
    return false;
}

template <typename T>
T &LinkedList<T>::get(int index) const
{
    if (index >= size || index < 0)
        throw std::out_of_range("Given index is invalid");

    node<T> *tmp = head;
    for (int i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}

template <typename T>
void LinkedList<T>::clear()
{
    node<T> *current = head;
    node<T> *tmp = nullptr;
    while (current)
    {
        tmp = current;
        current = current->next;
        delete tmp;
    }
    size = 0;
    tail = nullptr;
    head = nullptr;
}

template <typename T>
void LinkedList<T>::remove(T data)
{
    if (size == 0)
        return;

    node<T> *previous = nullptr;
    node<T> *current = head;

    for (int i = 0; i < size; i++)
    {
        if (current->data == data)
        {
            if (current == head)
            {
                node<T> *tmp = head;
                head = head->next;
                delete tmp;
                if (size < 3)
                    tail = head;
            }
            else
            {
                previous->next = current->next;
                if (current == tail)
                    tail = previous;
                delete current;
            }
            --size;
            return;
        }
        previous = current;
        current = current->next;
    }
}
