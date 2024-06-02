#include <iostream>
#include <cmath>
#include "binarytree.h"

struct Arraykey {
    int data = -1; 
};

class arrayBST : public binarytree {
private:
    Arraykey* data;
    int size;
    int checker;
    bool resize();
    bool resize(int newSize);
    bool isFull();
    void heapify(int index);

public:
    bool isEmpty();
    void addBST(int);
    int searchBST(int);
    void removeBST(int);
    void output();
    arrayBST(int size = 10);
    ~arrayBST();  
};

arrayBST::arrayBST(int size) : data(nullptr), size(size), checker(0) {
    data = new Arraykey[size];
}

arrayBST::~arrayBST() {
    delete[] data;
}

bool arrayBST::resize() {
    return resize(size * 2);
}

bool arrayBST::resize(int newSize) {
    try {
        Arraykey* temp = new Arraykey[newSize];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        for (int i = size; i < newSize; i++) {
            temp[i].data = -1; 
        }
        delete[] data;
        data = temp;
        size = newSize;
        return true;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return false;
    }
}

bool arrayBST::isFull() {
    return checker == size;
}

void arrayBST::heapify(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < checker && data[left].data != -1 && data[left].data < data[smallest].data) {
        smallest = left;
    }

    if (right < checker && data[right].data != -1 && data[right].data < data[smallest].data) {
        smallest = right;
    }

    if (smallest != index) {
        std::swap(data[index], data[smallest]);
        heapify(smallest);
    }
}

bool arrayBST::isEmpty() {
    return checker == 0;
}

void arrayBST::addBST(int element) {
    if (isFull()) {
        if (!resize()) {
            throw std::runtime_error("Error allocating space");
        }
    }

    int current = 0;
    while (data[current].data != -1) {
        if (element < data[current].data) {
            current = 2 * current + 1;
        } else {
            current = 2 * current + 2;
        }
        if (current >= size) {
            if (!resize()) {
                throw std::runtime_error("Error allocating space");
            }
        }
    }

    data[current].data = element;
    checker++;
}

void arrayBST::removeBST(int element) {
    if (isEmpty()) {
        throw std::runtime_error("Empty tree cannot be removed");
    }

    int i;
    for (i = 0; i < size; i++) {
        if (data[i].data == element) {
            break;
        }
    }

    if (i < size && data[i].data == element) {
        data[i].data = data[checker - 1].data;
        data[checker - 1].data = -1;
        checker--;
        if (i != checker) { 
            heapify(i);
        }
    } else {
        throw std::runtime_error("Key not found");
    }
}

int arrayBST::searchBST(int element) {
    if (isEmpty()) {
        throw std::runtime_error("Empty tree cannot be searched");
    }

    int current = 0;
    while (current < size && data[current].data != -1) {
        if (data[current].data == element) {
            return current;
        } else if (element < data[current].data) {
            current = 2 * current + 1;
        } else {
            current = 2 * current + 2;
        }
    }

    return -1;
}

void arrayBST::output() {
    if (isEmpty()) {
        std::cout << "Tree is empty." << std::endl;
    } else {
        for (int i = 0; i < size; i++) {
            if (data[i].data != -1) {
                std::cout << data[i].data << ' ';
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    arrayBST bst;
    
    bst.addBST(10);
    bst.addBST(1);
    bst.addBST(20);
    bst.addBST(3);

    bst.output();

    std::cout << "Searching for 20: " << bst.searchBST(20) << std::endl;
    std::cout << "Searching for 3: " << bst.searchBST(3) << std::endl;
    std::cout << "Searching for 4: " << bst.searchBST(4) << std::endl;

    try {
        bst.removeBST(20);
        std::cout<<"After removing:"<<std::endl;
        bst.output();
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
    }

    try {
        std::cout << "Searching for 20(after removing): " << bst.searchBST(20) << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
    }


    return 0;
}
