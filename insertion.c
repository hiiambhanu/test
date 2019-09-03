#include<stdio.h>

void display(int a[], int n){
    int i;
     printf("The array is \n");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
}

void insert(int a[], int *n, int item, int position){

    int i;

    if(position>*n){
        printf("invalid position");
        return;
    }
    for(i= (*n);i>=position;i--)
        a[i]=a[i-1];
    a[position-1] =  item;
    (*n)++;

}
void delete(int a[], int* n, int item){

    int i, position, flag  = 0;

    for(i=0;i <(*n);i++){
        if(a[i]==item)
            {
                flag = 1;
                position = i;
                break;
            }
    }

    if(flag==0){
        printf("Element does not exist\n");
        return;
    }

    for(int i = position; i < (*n) -1; i++){
        a[i]=a[i+1];
    }
    (*n)--;


}

int main(){
    int a[20], n, item, position, i;
    printf("Enter the number of elements \n");
    scanf("%d", &n);
    printf("Enter the array elements \n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    
    printf("Enter the item and the position to be inserted\n");
    scanf("%d%d", &item, &position);

    insert(a, &n, item, position);

    display(a, n);

    printf("\nEnter the element to be deleted");
    scanf("%d", &item);

    delete(a, &n, item);

    display(a, n);
    
   
    return 0;

}