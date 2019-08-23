#include<stdio.h>

  
void print(int a[], int n){
  int i;
  printf("Resulted array is ");
 for(i=0 ; i<n ; i++){
 printf("%d", a[i]);
  }
}  
  
int search(int a[], int n, int elem){
int i;

for(i=0;i<n;i++){

if(a[i] == elem){

return i;

}

}

return -1;

}


void delete(int a[], int n, int elem){

int i,index;
index = search(a, n, elem);
if(index == -1){

printf("Element no found");


}
else{

for(i= index; i<n-1 ;i++){
a[i]=a[i+1];

}  

n--;

print(a,n); 

} 



}

void insert(int a[],int n, int pos, int elem)
{ 
int i;

for(i=n-1; i>=pos-1;i--){

a[i+1] = a[i];

}

a[pos-1]=elem;

n++;

print(a,n);
 
}

int main()
{
 int a[100] , i = 0, n, elem, pos;
 char ch;
 printf("Enter size");
 scanf("%d", &n);
 for( i =0 ; i<n ; i++) 
 { 
 printf("Enter %d element" ,i+1);
 scanf("%d" , &a[i]);
 }
 while (1){
 printf("Enter i to insert, d to delete");
 scanf(" %c",&ch);
 if(ch=='i'){
 printf("Enter element to insert");
 scanf("%d", &elem);
 printf("Enter position");
 scanf("%d" , &pos);
 insert (a, n, pos, elem);
 }
 else if(ch=='d'){
 printf("Enter element to delete");
 scanf("%d", &elem);
 delete(a, n, elem);
 }
 else{
 printf("Wrong choice");
 }
 
 printf("\nEnter y to continue?");
 scanf(" %c",&ch);
 if(ch == 'y' || ch =='Y'){
 continue;
 }
 else{
 break;
 }
 
 }
 
 return 0;
 
}

