#include<iostream>

using namespace std;

int partition(int array[], int start, int end){

    int headPointer = start;
    int tailPointer = end;

    int pivot = array[start];
    while(true){
        while(headPointer < tailPointer && array[tailPointer] > pivot){
            tailPointer -= 1;
        }
        if(headPointer < tailPointer){
            array[headPointer] = array[tailPointer];
            headPointer += 1;
        }
        else{
            break;
        }
        while(headPointer < tailPointer && array[headPointer] < pivot){
            headPointer += 1;
        }
        if(headPointer < tailPointer){
            array[tailPointer] = array[headPointer];
            tailPointer -= 1;
        }
        else{
            break;
        }
    }
    array[headPointer] = pivot;
    return headPointer;
}
void quick_sort(int array[], int start, int end){
    if(start >= end){
        int p = partition(array, start, end);
        quick_sort(array, start, p - 1);
        quick_sort(array, p + 1, end);
    }
}

int main(){
    const int NUM = 6;
    //int array[NUM] = {44, 52, 12, 98, 78, 36, 66, 36, 20, 59};
    int array[NUM] = {}
    quick_sort(array, 0, NUM - 1);

    cout<<"sorted result"<<endl;
    for(int i = 0; i < NUM; i++){
        cout<<array[i]<<"\t";
    }
    cout<<endl;

    return 0;
}
