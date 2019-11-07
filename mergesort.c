#include<stdio.h>
void merge(int left[], int lsize, int right[], int rsize, int arr[], int arrsize){   
    int i, j, k;
    i = j = k = 0;
    while (i < lsize && j < lsize){
        if (left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < lsize){
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j< rsize){
        arr[k] =right[j];
        j++;
        k++;
    }
}
void disp(int a[], int n){
    int i;
    printf("The array is :");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
}

void mergesort(int a[], int size){
    if(size<2)
        return;
    int mid = size/2;
    int left [mid];
    int right[size - mid];
    for(int i = 0 ; i < mid ; i ++){
        left[i]= a[i];
    }
    for(int i = mid; i < size ; i ++){
        right[i-mid ] = a[i];
    }
    mergesort(left, mid);
    mergesort(right, size - mid);
    merge(left, mid, right, size-mid, a, size);
}
void main(){
    int i, n, a[100];
    printf("Enter the number of elements ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    disp(a,n);
    mergesort(a, n);
    printf("\nAfter sorting: \n");
    disp(a,n);
}   