#include<stdio.h>

int main(){
    int a[20], n, item, position, i;
    printf("Enter the number of elements \n");
    scanf("%d", &n);
    printf("Enter the array elements \n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    
    printf("Enter the item and the position to be inserted\n");
    scanf("%d%d", &item, &position);

    
    for(i=n;i>=position;i--)
        a[i]=a[i-1];
    a[position-1] =  item;
    n++;
    printf("The array is \n");

    for(i=0;i<n;i++)
        printf("%d\n", a[i]);

    return 0;

}