#include<stdio.h>
#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// int a[100] = {4, 3, 5, 9, 2, 11 };
int a[100];
int n = 0;

void heapifyOG(int a[], int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    // printf("\nnInHeapify :%d\n", n);
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

void display(int a[100], int size){
    for(int i=0;i<size;i++){
        printf(" %d ", a[i]);
    }
    printf("\n");
}



void addHeapify(int i ){
    if(i<=0 || (i-1/2 < 0)){
        return;
    }
    int parent = (i-1)/2;
    // printf("i : %d a[i]: %d parent: %d ap : %d", i, a[i], parent, a[parent]);

    if(a[i]>a[parent])
       {
        //    printf("in if ");
            swap(&a[i], &a[parent]);
        addHeapify(parent);}
}

void decreasePriority(int index, int dec){
    a[index] -= dec;
    heapifyOG(a, index);

}

int getHighestPriority(){
    return a[0];
}

void delHighest(){
    swap(&a[0], &a[n-1]);
    n--;
    heapifyOG(a, 0);
}

void addToHeap(int data){
    if (n == 100 -1){
        printf("Cannot add to heap as it is full \n");
        return;
    }
    a[n] = data;
    n++;

    // printf("\n%d %d\n", a[n],n);

    addHeapify(n-1);
}

void incPriority(int index, int inc){
    a[index] += inc;
    addHeapify(index);
}
void main2(){
    int choice, data, index, i =0;
    while(1){
        printf("1. Add to heap\n2. Display\n3. Decrease priority\n4. Increase Priority\n5. Delete Highest Priority\n6. Get Highest P\n7. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter number of elements ");
            scanf("%d", &i);
            while(i--){

            printf("\nenter the data ");
            scanf("%d", &data);
            addToHeap(data);}
            break;
        case 2:
            display(a, n);
            break;
        case 3:
            printf("enter index and dec ");
            scanf("%d", &index);
            scanf("%d", &data);
            decreasePriority(index, data);
            display(a, n);

            break;
        case 4:
            printf("Enter index and Inc ");
            scanf("%d", &index);
            scanf("%d", &data);
            incPriority(index, data);
            display(a, n);

            break;
        case 5:delHighest();
                display(a, n);
            break;
        case 6: data = getHighestPriority();
            printf("Highest priority is %d", data);
            break;
        case 7:     
            return;
        default:
            break;
        }
    }
}


int main(){

    // display(a, n);
    // heapifyOG(a, 1);
    // printf("\n");
    // display(a, n);
    // heapifyOG(a,2);
    // printf("\n");
    // heapifyOG(a, 0);
    // display(a, n);
    // addToHeap(69);
    // display(a, n);
    // delHighest();
    // cout<<"hbanu"<<endl;
    // display(a, n);
    // incPriority(1, 101);
    // cout<<"endl"<<endl;
    // display(a, n);
    // cout<<"endl"<<endl;

    // decreasePriority(0, 101);

    main2();


    return 0;
    
}

