#include<stdio.h>
#include<limits.h>
void swap(int *x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void disp(int a[], int n){  
    int i;
    printf("\nThe array is :");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
}


int a[100], n, capacity = 100;

int left(int i){
    return a[(2*i) + 1 ];
}

int parent(int i){
    return (i-1)/2;
}

int right(int i ){
    return a[(2*i) + 2 ];

}

int getMin() { return a[0]; } 

void minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l<n  && a[l]< a[i]) 
        smallest = l;
    if(r<n && a[r]<a[smallest])
        smallest = r;
    if (smallest!=i){
        swap(&a[i], &a[smallest]);
        minHeapify(smallest);
    }
}

void insertKey(int k) 
{ 
    if (n == capacity) 
    { 
        printf("\nOverflow: Could not insertKey\n"); 
        return; 
    } 
  
    // First insert the new key at the end 
    n++; 
    int i = n - 1; 
    a[i] = k; 
  
    // Fix the min heap property if it is violated 
    while (i != 0 && a[parent(i)] > a[i]) 
    { 
       swap(&a[i], &a[parent(i)]); 
       i = parent(i); 
    } 
} 

void decreaseKey(int i, int new_val) 
{ 
    a[i] = new_val; 
    while (i != 0 && a[parent(i)] > a[i]) 
    { 
       swap(&a[i], &a[parent(i)]); 
       i = parent(i); 
    } 
} 
int extractMin(){
    int root =  a[0];
    a[0] = a[n-1];
    n--;
    minHeapify(0);
    return root;
}
void deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}