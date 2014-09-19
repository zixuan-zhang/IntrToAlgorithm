/*
 * This script provides a class named MaxHeap
 * MaxHeap class provide folowing functions:
 *
 *  max_heap_insert() to insert new element into MaxHeap
 *  max_heap_sort() to sort the heap
 *
 * besides provider max heap build function in construct funcion.
 */
#include<iostream>

using namespace std;

class MaxHeap{
    public:
        MaxHeap();
        MaxHeap(int array[], int heap_size);
        virtual ~MaxHeap();

        void show_max_heap();
        void max_heap_insert(int value);
        void max_heap_sort();

    private:
        const int MAX_HEAP_SIZE = 10;
        int heap_size;
        int *heap;

        void swap(int *i, int *j);
        int PARENT(int i);
        int LEFT(int i);
        int RIGHT(int i);

        void max_heapify(int i);
};

MaxHeap::MaxHeap(){
    heap_size = 0;
    heap = new int[MAX_HEAP_SIZE];
}

MaxHeap::MaxHeap(int array[], int heap_size){
    if(heap_size > this->MAX_HEAP_SIZE){
        cout<<"Warning: Heap Build Overflow"<<endl;
        return ;
    }
    this->heap_size = heap_size;
    heap = new int[MAX_HEAP_SIZE];

    for(int i = 0; i < heap_size; i++){
        heap[i] = array[i];
    }
    
    for(int i = heap_size / 2 - 1; i >= 0; i--){
        max_heapify(i);
    }
}

MaxHeap::~MaxHeap(){

}

void MaxHeap::swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

int MaxHeap::PARENT(int i){
    return (i - 1) / 2;
}
int MaxHeap::LEFT(int i){
    return i * 2 + 1;
}
int MaxHeap::RIGHT(int i){
    return i * 2 + 2;
}

void MaxHeap::max_heapify(int i){
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
        if(heap[temp] < heap[left]){
            temp = left;
        }
        if(right < heap_size && heap[temp] < heap[right]){
            temp = right;
        }

        if(temp != i){
            swap(&heap[i], &heap[temp]);
            max_heapify(temp);
        }
    }
}

void MaxHeap::max_heap_insert(int value){
    if(heap_size + 1 > MAX_HEAP_SIZE){
        cout<<"Heap overflow, insert failed"<<endl;
        return ;
    }
    heap_size += 1;
    
    heap[heap_size - 1] = value;
    
    // max heapify
    int i = heap_size - 1;
    while(i > 0){
        int parent = PARENT(i);
        max_heapify(parent);
        i = parent;
    }
}

void MaxHeap::max_heap_sort(){
    int temp_heap_size = heap_size;
    while(heap_size > 0){
        swap(&heap[0], &heap[heap_size - 1]);
        heap_size = heap_size - 1;
        max_heapify(0);
    }
    heap_size = temp_heap_size;
}
void MaxHeap::show_max_heap(){
    for(int i = 0; i < heap_size; i++){
        cout<<heap[i]<<"\t";
    }
    cout<<endl;
}

void test_case1(){
    int heap[8] = {1, 4, 5, 3, 6, 9, 7, 2};
    MaxHeap *maxHeap = new MaxHeap(heap, 8);

    cout<<"heap built"<<endl;
    maxHeap->show_max_heap();

    cout<<"max heap insert"<<endl;
    maxHeap->max_heap_insert(10);
    maxHeap->show_max_heap();

    cout<<"max heap sorted"<<endl;
    maxHeap->max_heap_sort();
    maxHeap->show_max_heap();
}

void test_case2(){
    int heap[8] = {1, 4, 5, 3, 6, 9, 7, 2};
    MaxHeap *maxHeap = new MaxHeap(heap, 8);


}

int main(){

    return 0;

}
