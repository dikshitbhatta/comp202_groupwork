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
        void output();
        arrayBST(int size);
        ~arrayBST();  
}

arrayBST::arrayBST(int size)
    :size(size),index(0),checker(0){
        int *data = new int[];
    }

arrayBST::~arrayBST(){
    delete[] data;
}

bool arrayBST::isEmpty(){

    if(checker=0){
        return true;
    }
    else
        return false;
}
void addBST(int element){
    index++;
    data[index]=element;
    checker++;
}
int removeBST(int element){
    if(isEmpty()){
        std::cout<<"BST is empty.";
    }
    else{
        for(int i=0;i<size;i++)
            if(element==data[index])
            index--;
            checker--;
    }
}
void arrayBST::outut(){
    if(isEmpty()){
        std::cout<<"Tree is empty."<<std::endl;
    }
    else{
    for(int i=0;i<size;i++){
        std::cout<<data[index]<<' ';
    }
    std::cout<<endl;
    }

}

int main(){
    binarytree *btree = new arrayBST(10)
    btree->addBST(10);
    btree->addBST(20);
    btree->output();


}

//can do it using key value array implementation