#include <iostream>
#include "binarytree.h"

LinkedListBST::LinkedListBST() : ROOT(nullptr) {}	

class Node
{
    public:
        Node *Parent;
        Node *Left;
        Node *Right;
        int info;
    public:
        Node():Parent(nullptr),Left(nullptr),Right(nullptr) {}
        ~Node(){}
};

bool LinkedListBST::isEmpty()
{
    if (ROOT == nullptr)
        return true;
    else
        return false;
}

void LinkedListBST::addBST(int data)
{
    if (ROOT == nullptr)
    {
        ROOT = new Node();
        ROOT->info = data;
    }
    else
    {
        Node *temp = ROOT;
        while (temp != nullptr)
        {
            if (data < temp->info)
            {
                if (temp->Left == nullptr)
                {
                    temp->Left = new Node();
                    temp->Left->info = data;
                    break;
                }
                else
                {
                    temp = temp->Left;
                }
            }
            else if (data > temp->info)
            {
                if (temp->Right == nullptr)
                {
                    temp->Right = new Node();
                    temp->Right->info = data;
                    break;
                }
                else
                {
                    temp = temp->Right;
                }
            }
        }
    }
}

bool LinkedListBST::searchBST(int data)
{
    Node *temp = ROOT;
    while (temp != nullptr)
    {
        if (temp->info == data)
        {
            return true;
        }
        else if (data < temp->info)
        {
            temp = temp->Left;
        }
        else
        {
            temp = temp->Right;
        }
    }
    return false;
}

void LinkedListBST::removeBST(int data)
{
    Node *p = nullptr;
    Node *temp = ROOT;
    while (temp != nullptr && temp->info != data)
    {
        p = temp;
        if (data < temp->info)
        {
            temp = temp->Left;
        }
        else
        {
            temp = temp->Right;
        }
    }
    if (temp == nullptr)
    {
        std::cout << "Node not found " << std::endl;
        return;
    }
    if (temp->Left == nullptr && temp->Right == nullptr)
    {
        if (temp != ROOT)
        {
            if (p->Left == temp)
            {
                p->Left = nullptr;
            }
            else
            {
                p->Right = nullptr;
            }
        }
        else
        {
            ROOT = nullptr;
        }
        delete temp;
    }

    else if (temp->Left && temp->Right)
    {
        Node *parentReplace = temp;
        Node *replace = temp->Right;
        while (replace->Left != nullptr)
        {
            parentReplace = replace;
            replace = replace->Left;
        }

        temp->info = replace->info;

        if (parentReplace->Left == replace)
        {
            parentReplace->Left = replace->Right;
        }
        else
        {
            parentReplace->Right = replace->Right;
        }

        delete replace;
    }
    else
    {
        Node *child = (temp->Left) ? temp->Left : temp->Right;

        if (temp != ROOT)
        {
            if (temp == p->Left)
            {
                p->Left = child;
            }
            else
            {
                p->Right = child;
            }
        }
        else
        {
            ROOT = child;
        }
        delete p;
    }
}
