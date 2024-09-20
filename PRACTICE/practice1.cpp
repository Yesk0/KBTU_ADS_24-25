#include <iostream>
using namespace std;

static void insertion_sort(int* arr, int N){
    int temp;
    for (int j = 1; j< n; j++){
        int i = j - 1;
        temp = arr[j];
        while(i >= 0 && arr[i] < temp){
            arr[i+1] = arr[i];
        }
        arr[i+1] = temp;
    }
}