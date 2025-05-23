#include <stdexcept>

template <typename T>
struct node
{
    node *next = nullptr;
    T data;
};

template <typename T>
class LinkedList
{

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    LinkedList(T data)
    {
        head = new node<T>;
        head->next = nullptr;
        head->data = data;
        tail = head;
        size = 1;
    }

    ~LinkedList()
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

    bool isEmpty() const
    {
        return size == 0;
    }

    int getSize() const
    {
        return size;
    }

    void add(T data)
    {
        if (head)
        {
            node<T> *tmp = tail;
            tail = new node;
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

    bool contains(T data) const
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

    T &get(int index) const
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

    void clear()
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

    void remove(T data)
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

private:
    node<T> *head = nullptr;
    node<T> *tail = nullptr;
    int size = 0;
};