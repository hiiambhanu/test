#include<stdio.h>
void concat(char a[100], char b[200]){

    int i = 0, j = 0 ;
    for(i=0;b[i]!='\0';i++);
    for(j = 0 ; a[j]!='\0';j++, i++)
        b[i] = a[j];
    b[i] = '\0';
}
void main(){
    char a[100], b[200];
    printf("Enter the two strings to be concatenated ");
    scanf("%s", b);
    scanf("%s", a);
    concat(a, b);
    printf("The concatenated string is %s \n", b);
}