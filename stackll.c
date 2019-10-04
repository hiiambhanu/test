#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct Stack{
    struct node* top;
};

void push(struct Stack* s, int data){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    
    temp->next = s->top;

    s->top = temp;
}

void pop(struct Stack* s){
    struct node* temp = s->top;
    if(temp==NULL){
        printf("Underflow!\n");
        return;
    }
    s->top = s->top->next;
    free(temp);
}

void peek(struct Stack s){
    struct node* temp =  s.top;
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
    struct Stack s;
    s.top = NULL;
    while(1){   
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be pushed\n");
            scanf("%d", &data);
            push(&s, data);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
             peek(s);
            break;
        case 4:
            return;
        default:
            printf("Invalid Choice!\n");
        }
    }
}