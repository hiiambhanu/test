#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
   int data;
   struct Node *next;
}*first, *last;
 
void create()
{
   first = last = NULL;
}
 
void enqueue(int x)
{
   struct Node *temp;
   temp = (struct Node *)malloc(sizeof(struct Node));
   temp ->data = x;
   if(last == NULL)
   {
       first = last = temp;
       return;
   }
   temp->next = last ->next;
   last->next = temp;
   last = temp;
}
 
int dequeue()
{
   int x;
   struct Node *temp;
   if(first == NULL)
   {  
       printf("Empty Queue");
       return -1;
   }
   x = first->data;
   temp = first;
   free(temp);
   first = first -> next;
   if(first == NULL)
   {
       last = NULL;
   }
   return x;
  
}
 
void display()
{
   struct Node *t;
   t = first;
   while(t!=NULL)
   {
       printf("%d ",t->data);
       t=t->next;
   }
}
 
int main()
{  
   int elem, ch;
   create();
   while(ch!=4){
       printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4.Exit");
       printf("\nEnter your choice");
       scanf("%d",&ch);
       switch (ch)
       {
       case 1:
           printf("\nEnter element");
           scanf("%d",&elem);
           enqueue(elem);
           break;
       case 2:
           printf("\nDeleted: %d\n",dequeue());
           break;
       case 3:
           display();
           break;
      
       case 4:
           break;
      
       default:
           printf("\nPlease enter valid choice");
       }
      
   }
 
   return 0;
}
