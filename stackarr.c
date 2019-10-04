#include<stdio.h>

void push(int a[], int *top, int item){
    if(*top == 10){
        printf("Overflow. \n");
        return;
    }
    else
    {
        (*top)++;
        a[*top] = item;
    }
}

void pop(int a[], int *top){
    if(*top == -1){
        printf("Underflow. \n");
        return;
    }
    (*top)--;
}

void peek(int a[], int *top){
    if(*top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("The topmost element is %d \n",  a[*top]);
    return;
}

int main(){
    int stack[10], top = -1;
    int n;

    while(1){

        int choice, a;
        printf("1. Push \n2. Pop\n3. Peek\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed.\n");
            scanf("%d", &a);
            push(stack, &top, a);    
            break;
        case 2: 
            pop(stack, &top);   
            break;
        case 3: 
            peek(stack, &top);
            break;
        case 4: 
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}