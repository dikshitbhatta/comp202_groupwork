#include <iostream>
#include "binarytree.h"
int main()
{
    LinkedListBST list;
    if (list.isEmpty())
    {
        std::cout << "Empty";
    }
    list.addBST(12);
    if (!list.isEmpty())
    {
        std::cout << "\nNot empty";
    }

    list.addBST(24);
    list.addBST(2);
    if (list.searchBST(2))
    {
        std::cout << "\nThe element is found";
    }
    list.removeBST(2);
    if (!list.searchBST(2))
    {
        std::cout << "\nThe element was deleted";
    }
}
