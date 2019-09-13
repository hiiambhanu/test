#include<stdio.h>
void swap(char*a, char*b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
void reverse(char a[100]){
    int i=0, j;
    for(j = 0 ; a[j]!='\0';j++);
    j--;
    while(i < j){
        swap(&a[i], &a[j]);
        i++;
        j--;
    }
}
void main(){
    char a[100];
    printf("Enter the string. \n");
    scanf("%s", a);
    reverse(a);
    printf("the string after reversing is %s\n", a);    
}
