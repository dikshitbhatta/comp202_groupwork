#include <iostream>

class binarytree{
    public:
        virtual bool isEmpty()=0;
        virtual void addBST(int)=0;
        virtual void searchBST(int)=0;
        virtual int removeBST(int)=0;
        ~ binarytree(){}
};
