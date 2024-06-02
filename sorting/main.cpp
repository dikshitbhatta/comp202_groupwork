#include<iostream>
#include <random>
#include"insertionsort.cpp"
using namespace std;

int main() {
    const int length = 8;
    int arr[length];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 999);
    
    cout << "Randomly Generated Array: "<<endl;
    for (int i = 0; i < length; i++) {
        arr[i] = dis(gen);
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int* ptr = insertionsort(arr, length);
    
    cout << "Sorted Array: "<<endl;
    for (int i = 0; i < length; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
    
    return 0;
}