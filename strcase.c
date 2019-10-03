#include<stdio.h>
void main(){
    char a[100];
    int i = 0 ;
    printf("Enter the string \n");
    scanf("%s", a);
    for(i = 0 ; a[i]!='\0';i++) 
        if((int)a[i]>=97 && (int)a[i]<=137)
            a[i] = (int)a[i] - 32;
    printf("The string is %s \n", a);
}