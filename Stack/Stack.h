#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    void push(const T &value);

    T &peek();

    T &pop();

    bool contains(const T &value) const;

    int size() const;

    bool isEmpty() const;

private:
    void resize();
    int arraySize;
    T *array;
    int topIndex;
};

#endif