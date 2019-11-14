#include<stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int MAX_SIZE =100;
int a[] = {4, 3, 5, 9, 2, 11 };
int n = 6;

void heapifyOG(int a[], int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    printf("\nnInHeapify :%d\n", n);
    if(a[i]<a[l] && l<n){
        largest = l;
    }
    if(a[r]>a[largest]&&r<n){
        largest = r;
    }

    if(largest != i){
        swap(&a[largest], &a[i]);
        heapifyOG(a, largest);
    }

}

void display(int a[], int size){
    for(int i =0;i<size;i++){
        printf(" %d ", a[i]);
    }
}


void addToHeap(int data){
    if (n == MAX_SIZE -1){
        printf("Cannot add to heap as it is full \n");
        return;
    }
    n +=1;
    a[n] = data;
    printf("\n%d %d\n", a[n],n);
    int parent = n/2 - 1;
    printf("parent is %d\n n is %d\n", a[parent], n);
    heapifyOG(a, parent);
}

int main(){

    display(a, n);
    heapifyOG(a, 1);
    printf("\n");
    display(a, n);
    heapifyOG(a,2);
    printf("\n");
    heapifyOG(a, 0);
    display(a, n);
    addToHeap(100);
    printf("\nbhanu %d\n", n);
    display(a, 7);


    return 0;
    
}