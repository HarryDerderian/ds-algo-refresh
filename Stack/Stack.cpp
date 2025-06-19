#include "Stack.h"

template <typename T>
Stack<T>::Stack()
{
    arraySize = 10;
    array = new T[arraySize];
    topIndex = -1;
    totalElements = 0;
}

template <typename T>
bool Stack<T>::contains(const T &data) const
{
    if (topIndex == -1)
        return false;

    for (int index = 0; index <= topIndex; index++)
        if (data == array[index])
            return true;

    return false;
}

template <typename T>
int Stack<T>::size() const
{
    return topIndex + 1;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return topIndex < 0;
}

template <typename T>
void Stack<T>::push(const T &value)
{
    // check if its full
    if (topIndex + 1 == arraySize)
        resize();
    // resize and copy all elements into the new array, destory the old
    // add the new element at the end of the new array

    topIndex += 1;
    array[topIndex] = value;
}

template <typename T>
T &Stack<T>::peek()
{
    return array[topIndex];
}

template <typename T>
T &Stack<T>::pop()
{
    if (topIndex < 0)
        throw std::out_of_range("Stack is empty");

    return array[topIndex--];
}

template <typename T>
void Stack<T>::resize()
{
    arraySize *= 2;
    T *tmp = new T[arraySize];
    for (int index = 0; index <= topIndex; index++)
        tmp[index] = array[index];

    delete[] array;
    array = tmp;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] array;
    array = nullptr;
    topIndex = -1;
    arraySize = 0;
}
