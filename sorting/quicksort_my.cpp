#include<iostream>

void swap(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}


void quickSort(int high, int low, int pivot, int arr[], int i){
    do{
        high = arr[i];
        i++;
    }while(pivot > arr[i]);

    i = 8;

    do{
        low = arr[i];
        i--;
    }while(pivot < arr[i]);


    swap(arr, high,low);
}

int main(){
    int arr[] = {2,44,6,8,242,75,35,23};

    int pivot = arr[0];
    int i = 0, high,low;

    quickSort(high,low,pivot,arr,i);
    
}
