#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* top = NULL;

void push(int data){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    if(top==NULL){
        top = (struct node*) malloc(sizeof(struct node*));
    }
    temp->next = top;
    
    top = temp;
}

void pop(){
    struct node* temp = top;
    if(temp==NULL){
        printf("Underflow!\n");
        return;
    }
    top = top->next;
    free(temp);
}

void peek(){
    struct node* temp = top;
    if(temp==NULL){
        printf("Underflow!\n");
        return;
    }
    else 
        printf("The value of the topmost item is %d", temp->data);
    }

void main(){
    int choice, data;
    struct node* temp;
    top = NULL;
    while(1){   
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be pushed\n");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
             peek();
            break;
        case 4:
            return;
        default:
            printf("Invalid Choice!\n");
        }
    }
}