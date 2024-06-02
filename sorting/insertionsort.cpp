#include<iostream>
using namespace std;

int main() {
    const int length = 8;
    int arr[length] = {4, 7, 5, 9, 0, 2, 8, 6};
    for (int i = 0; i < length; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
