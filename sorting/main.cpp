#include<iostream>
#include"insertionsort.cpp"
using namespace std;

int main() {
    const int length = 8;
    int* ptr;
    int arr[length] = {4, 7, 5, 9, 0, 2, 8, 6};
    ptr=insertionsort(arr,length);
     
    for (int i = 0; i < length; i++) {
        cout << ptr[i] << endl;
    }
    return 0;
}
