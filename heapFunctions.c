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

void heapSort() {                                                                  

    for (int i = n / 2 - 1; i >= 0; i--)                                    
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


void insert(int arr[100], int n, int data){
    if (n<100){
        n++;
        arr[n] = data;
        heapSort();
    }
    else 
        printf("Cannot perform insertion ");
}

int getHighestPriority(int a[100]){
    return a[0];
}
void deleteHighestPriority(int a[100]){

}

void decreasePriority(int a[100], int n, int index, int decrement){
    if(index>n)
        {
            printf("Invalid index \n");
            return;
        }
    a[index]-=decrement;
    heapSort();
}


void main(){
    int choice, data, dec, hp, index;
    int j;
    n = 5;
    for(j=0;j<n;j++)
        scanf("%d", &a[j]);
    heapSort();
       for(j=0;j<n;j++)
        printf("%d ", a[j]);
    while(1){
        printf("1. Insert\n2. Get Highest Priority\n3. Delele Highest Priority\n4. Decrease Proiority\nEnter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted ");
            scanf("%d", &data);
            insert(a, n, data);
            break;
        case 2:
            hp = getHighestPriority(a);
            printf("The highest priority is %d\n", hp);
            break;
        case 3:
            break;
            printf("Enter the index and the decrement needed ");
            scanf("%d%d", &index, &dec);
            decreasePriority(a, n, index, dec);
            break;
        
        default:    
        return;
        }
    }

}   