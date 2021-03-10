#include <stdio.h>
#include <stdlib.h>

HEAP_SIZE = 11;

typedef struct{
    int *arr;
    int count;
    int capacity;
}min_heap;

void insert(min_heap *h, int element){
    if( h->count < h->capacity){
        h->arr[h->count] = element;
        heapify(h, h->count);
        h->count++;
    }
}

void heapify(min_heap *h,int index){
    int temp;
    int parent_node = (index-1)/2;

    if(h->arr[parent_node] > h->arr[index]){
        temp = h->arr[parent_node];
        h->arr[parent_node] = h->arr[index];
        h->arr[index] = temp;
        heapify(h,parent_node);
    }
}

int PopMin(min_heap *h){
    int pop;
    if(h->count==0){
        printf("Empty ERROR\n");
        return -1;
    }
    pop = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    heapify_to_bottom(h, 0);
    return pop;
}

void heapify_to_bottom(min_heap *h, int parent){
    int left = parent*2+1;
    int right = parent*2+2;
    int min;
    int temp;
    if(left >= h->count || left <0)
        left = -1;
    if(right >= h->count || right <0)
        right = -1;

    if(left != -1 && h->arr[left] < h->arr[parent])
        min=left;
    else
        min =parent;
    if(right != -1 && h->arr[right] < h->arr[min])
        min = right;
    if(min != parent){
        temp = h->arr[min];
        h->arr[min] = h->arr[parent];
        h->arr[parent] = temp;
        heapify_to_bottom(h, min);
    }
}

int main()
{
    min_heap* h = (min_heap*)malloc(sizeof(min_heap));
    h->count=0;
    h->capacity = HEAP_SIZE;
    h->arr = (int*)malloc(h->capacity*sizeof(int));

    insert(h,3);
    insert(h,2);
    insert(h,1);
    insert(h,15);
    insert(h,5);
    insert(h,4);
    insert(h,45);
    printf("min : %d\n", PopMin(h));
    printf("min : %d\n", PopMin(h));
    return 0;
}
