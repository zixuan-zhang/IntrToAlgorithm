/*
 * This program implements select-sort algorithm
 * key function: select_sort()
 */

#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int select_sort(int array[], int number){
    /*
     *sort array by select sort algorithm
     */
    for(int i = 0; i < number - 1; i++){
        int temp = i;
        for(int j = i + 1; j < number; j++){
            if(array[temp] < array[j]){
                temp = j;
            }
        }
        swap(&array[i], &array[temp]);
    }
}

int main(){
    /*
     * test case
     */
    int array[10] = {3, 5, 4, 6, 9, 1, 10, 7, 4, 2};
    int number = 10;
    select_sort(array, number);
    cout<<"sorted array:"<<endl;
    for(int i = 0; i < number; i++){
        cout<<array[i]<<'\t';
    }
    cout<<endl;
    
    return 0;
}
