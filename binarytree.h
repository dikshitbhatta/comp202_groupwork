#include <iostream>

class binarytree{
    public:
        virtual bool isEmpty()=0;
        virtual void addBST(int)=0;
        virtual int searchBST(int)=0;
        virtual void removeBST(int)=0;
        virtual void output()=0;
        virtual ~ binarytree(){}
};
