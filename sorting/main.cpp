#include<iostream>
#include<ctime>
#include <random>
#include"insertionsort.cpp"
using namespace std;

int main() {
    clock_t start,end;
    double timecomplexity;
    start=clock();
    const int length = 8;
    int arr[length];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> rand(0, 99);
    
    cout << "Randomly Generated Array: "<<endl;
    for (int i = 0; i < length; i++) {
        arr[i] = rand(gen);
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int* ptr = insertionsort(arr, length);
    
    cout << "Sorted Array: "<<endl;
    for (int i = 0; i < length; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
    end=clock();

    timecomplexity=((double)(end-start))/CLOCKS_PER_SEC;
    cout<<"Time complexity: "<<timecomplexity<<endl;   
    return 0;
}