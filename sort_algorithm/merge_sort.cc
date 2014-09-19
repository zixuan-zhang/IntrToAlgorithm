#include<iostream>

using namespace std;

void merge(int array[], int start, int mid, int end){
    int number1 = mid - start + 1; // mid - start + 1
    int number2 = end - mid; // end - (mid + 1) + 1

    int *subArray1 = new int[number1];
    int *subArray2 = new int[number2];

    for(int i = 0; i < number1; i++){
        subArray1[i] = array[start + i];
    }
    for(int i = 0; i < number2; i++){
        subArray2[i] = array[mid + 1 + i];
    }

    // start merge
    int c1 = 0;
    int c2 = 0;
    while(c1 < number1 && c2 < number2){
        if(subArray1[c1] < subArray2[c2]){
            array[start + c1 + c2] = subArray1[c1];
            c1++;
        }
        else{
            array[start + c1 + c2] = subArray2[c2];
            c2++;
        }
    }
    if(c1 == number1){
        while(c2 < number2){
            array[start + c1 + c2] = subArray2[c2];
            c2++;
        }
    }
    else{
        while(c1 < number1){
            array[start + c1 + c2] = subArray1[c1];
            c1++;
        }
    }
}

void merge_sort(int array[], int start, int end){
    if(start < end){
        int mid = (end + start) / 2;
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);

        merge(array, start, mid, end);
    }
}

int main(){
    int array[10] = {4, 2, 1, 6, 10, 9, 7, 3, 6, 5};
    //int array[4] = {4, 2, 5, 1};
    int END = 9;
    merge_sort(array, 0, END);

    for(int i = 0; i < 10; i++){
        cout<<array[i]<<"\t";
    }
    cout<<endl;

    return 0;
}
