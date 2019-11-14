#include<stdio.h>
int a[100], n;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}



void disp(int a[], int n){
    int i;
    printf("\nThe array is :");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
}


void maxHeapify(int n, int i){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;
    if(left < n && a[i] < a[left]){
            largest = left;
    }

    if (right<n && a[largest] < a[right])
        largest = right;
    if (largest!=i){
        swap(&a[i], &a[largest]);
        printf("maxHeapify \n");
        disp(a, n);
        maxHeapify(n, largest);
    }
}

void heapSort() 
{                                                                       ///// 0 1 2 3 4 

    for (int i = n / 2 - 1; i >= 0; i--)                                ////  9 1 2 8 7     
        maxHeapify(n, i);
        printf("heapSort 1st\n");

        disp(a, n);
     
    for (int i=n-1; i>=0; i--){  
        swap(&a[0], &a[i]);
        printf("heapSort 2nd \n");

        disp(a, n);
        maxHeapify(i, 0); 
    } 
} 


void main(){
    int j;
    n = 5;
    for(j=0;j<n;j++)
        scanf("%d", &a[j]);
    heapSort();
       for(j=0;j<n;j++)
        printf("%d ", a[j]);
}   