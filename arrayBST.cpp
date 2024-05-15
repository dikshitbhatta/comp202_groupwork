#include <iostream>
#include <binarytree.h>

class arrayBST{
    private:
        int * data;
        int size;
        int index;
        int checker;
    public:
        bool isEmpty();
        void addBST(int);
        void searchBST(int);
        int removeBST(int);
        arrayBST(int size);
        ~arrayBST();  
}

arrayBST::arrayBST(int size)
    :size(size),index(0){
        int *data = new int[];
        data[0]=checker;
    }

arrayBST::~arrayBST(){
    delete[] data;
}

bool arrayBST::isEmpty(){
    data[0]=
    if(data[0]==null){
        return true;
    }
    else
        return false;
}
void addBST(int element){
    index++;
    data[index]=element;

}
