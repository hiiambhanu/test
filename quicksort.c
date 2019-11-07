#include<stdio.h>
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[], int start, int end){
    int pivot = a[end];
    int i, p_index;
    p_index = start;
    for( i=start;i<end;i++){
        if(a[i]<=pivot)
            {
                swap(&a[i], &a[p_index]);
                p_index++;
            }
    }
    swap(&a[p_index], &a[end]);
    return p_index;
}

void quicksort(int a[], int start, int end){
    if(start<end){
    int p_index = partition(a, start, end);
    quicksort(a, start, p_index-1);
    quicksort(a, p_index+1, end);
    }
}

void disp(int a[], int n){
    int i;
    printf("The array is :");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
}

void main(){
    int i, n, a[100];
    printf("Enter the number of elements ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    disp(a,n);
    quicksort(a, 0, n-1);
    printf("\nAfter sorting: \n");
    disp(a,n);
}   