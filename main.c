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

void edit_element(min_heap* h, int index, int element)
{
    h->arr[index] = element;
    if ((index != 0)&&(h->arr[(index-1)/2] > h->arr[index])){
        heapify(h, index);
    } else if ((h->arr[index]>h->arr[index*2+1])||
               (h->arr[index]>h->arr[index*2+2])){
        heapify_to_bottom(h, index);
    }
}

int main()
{
    min_heap* h = (min_heap*)malloc(sizeof(min_heap));
    h->count=0;
    h->capacity = HEAP_SIZE;
    h->arr = (int*)malloc(h->capacity*sizeof(int));

    insert(h,10);
    insert(h,5);
    insert(h,20);
    insert(h,100);
    edit_element(h,1,200);
    printf("min : %d\n", PopMin(h));
    printf("min : %d\n", PopMin(h));
    return 0;
}
