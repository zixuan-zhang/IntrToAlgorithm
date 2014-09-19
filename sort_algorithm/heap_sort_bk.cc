#include<iostream>

using namespace std;

const int MAX_HEAP_SIZE = 10;

int HEAP[MAX_HEAP_SIZE] = {1, 4, 5, 3, 6, 9, 7, 2};
int heap_size = 8;

#define PARENT(i) (i-1)/2
#define LEFT(i) (i*2+1)
#define RIGHT(i) (i*2+2)

void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void max_heapify(int array[], int i){
    /*
     * Suppose left subheap is max heap as well as right subheap,
     * The value of node i may less than left node or right node or may not,
     * The function is to make the heap MAX!
     */
    if(i <= heap_size/2 - 1 ){
        //if node i not leaf
        int left = LEFT(i);
        int right = RIGHT(i);

        int temp = i;
        if(array[temp] < array[left]){
            temp = left;
        }
        if(right < heap_size && array[temp] < array[right]){
            temp = right;
        }

        if(temp != i){
            swap(&array[i], &array[temp]);
            max_heapify(array, temp);
        }
    }
}

void build_max_heap(int array[], int heap_size){
    for(int i = heap_size / 2 - 1; i >= 0; i--){
        max_heapify(array, i);
    }
}

void heap_sort(int array[], int &heap_size){
    /*
     * sort heap local, heap_size modified
     */
    while(heap_size > 0){
        swap(&array[0], &array[heap_size - 1]);
        heap_size = heap_size - 1;
        max_heapify(array, 0);
    }
}

void max_heap_insert(int array[], int value, int &heap_size){
    /*
     * insert new element into heap
     */
    heap_size += 1;
    if(heap_size > MAX_HEAP_SIZE){
        cout<<"Heap overflow"<<endl;
        return ;
    }
    array[heap_size - 1] = value;
    
    // max heapify
    int i = heap_size - 1;
    while(i > 0){
        int parent = PARENT(i);
        max_heapify(array, parent);
        i = parent;
    }
}

int main(){
    for(int i = 0; i < heap_size; i++){
        cout<<HEAP[i]<<"\t";
    }
    cout<<endl;

    //build max heap
    build_max_heap(HEAP, heap_size);
    cout<<"build done"<<endl;
    for(int i = 0; i < heap_size; i++){
        cout<<HEAP[i]<<"\t";
    }
    cout<<endl;

    cout<<"insert new element"<<endl;
    max_heap_insert(HEAP, 10, heap_size);
    for(int i = 0; i < heap_size; i++){
        cout<<HEAP[i]<<"\t";
    }
    cout<<endl;

    int temp_heap_size = heap_size;
    heap_sort(HEAP, heap_size);
    cout<<"heap sorted"<<endl;
    for(int i = 0; i < temp_heap_size; i++){
        cout<<HEAP[i]<<"\t";
    }
    cout<<endl;
    return 0;
}
