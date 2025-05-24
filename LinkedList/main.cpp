#include <iostream>
#include "LinkedList.h"

// using namespace std;
int main()
{
    LinkedList<int> *list = new LinkedList<int>;

    // add 10 items
    for (int i = 0; i < 10; ++i)
        list->add(i);

    // confirm items were added correctly and get works
    std::cout << "add/get test\n";
    std::cout << "Expected output: 0 1 2 3 4 5 6 7 8 9\n"
              << "Current  output: ";
    for (int i = 0; i < 10; ++i)
        std::cout << list->get(i) << " ";
    std::cout << std::endl;

    // confirm size works, and remove works
    std::cout << "Expected size: 10\n";
    std::cout << "current  size: " << list->getSize() << std::endl;

    list->remove(0);
    list->remove(5);
    std::cout << "Expected size: 8\n";
    std::cout << "current  size: " << list->getSize() << std::endl;

    list->remove(8);

    std::cout << "add/get test\n";
    std::cout << "Expected output: 1 2 3 4 6 7 9 \n"
              << "Current  output: ";
    for (int i = 0; i < list->getSize(); ++i)
        std::cout << list->get(i) << " ";
    std::cout << std::endl;

    std::cout << "Expected size: 7\n";
    std::cout << "current  size: " << list->getSize() << std::endl;

    std::cout << "clear test\n";
    list->clear();

    std::cout << "Expected size: 0\n";
    std::cout << "current  size: " << list->getSize() << std::endl;

    std::cout << "Expected output: \n"
              << "Current  output: ";
    for (int i = 0; i < list->getSize(); ++i)
        std::cout << list->get(i) << " ";
    std::cout << std::endl;

    std::cout << "isEmpty test\n";
    std::cout << "List is empty: " << std::boolalpha << list->isEmpty() << std::endl;

    // adding 4 and then checking if 4 is within the list
    std::cout << "adding 4 ...\n";
    list->add(4);
    std::cout << "contains 4: " << std::boolalpha << list->contains(4) << std::endl;
    std::cout << "size: " << list->getSize() << std::endl;
    std::cout << "contains 34789573? " << std::boolalpha << list->contains(34789573);

    delete list;

    return 0;
}