#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

void del(){
    int choice;
    struct node *temp = head;
    printf("1. Beginning\n2. End\n3. Position\nEnter choice ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        head = temp->next;
        free(temp);
        break;
    case 2:
        while(temp->next!=NULL)
            temp=temp->next;
        free(temp);
        break;
    case 3:
        int pos;
        struct node *prev = NULL;
        int i = 0;
        printf("Enter Pos ");
        scanf("%d", &pos);
        pos--;
        while(i!=pos){
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next  = temp->next;
        free(temp);
        break;
    }
}

void display(){
    struct node *temp = head;
    while (temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}
void insertbeg(int data){
    struct node *temp =(struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
}
void insertpos(int pos, int data){
    if(head ==NULL && pos!=1){
        printf("invalid location");
        return;
    }
    else if(head == NULL && pos==1 )
        {insertbeg(data);
        return;
        }
    else if(pos == 1){
        insertbeg(data);
        return;
    }
    int i=0;
    struct node* temp = head;
    struct node* prev = NULL;
    struct node* tmp = (struct node*) malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->data = data;
    pos--;
    while(i!=pos){
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = tmp;
    tmp->next = temp;
}
void insertend(int data){
    struct node *temp = head;
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = NULL;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = tmp;
}

int main(){
    int choice;
    int data, pos;
    while(1){
        printf("1. Insert in the beginning\n2. Insert at the end\n3. Insert at a position\n4. Delete an item\n5. Display the linked list\n6. Exit\nEnter your choice"); 
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be inserted ");
                scanf("%d", &data);
                insertbeg(data);
                break;
            case 2:
                printf("Enter the data to be inserted  ");
                scanf("%d", &data);
                insertend(data);
                break;
            case 3:
                printf("Enter the position and the value ");
                scanf("%d %d", &pos, &data);
                insertpos(pos, data);
                break;

            case 4:
                del();
                break;
            case 5: 
                display();
                break;  
            case 6:
                return 0;
            default: printf("Enter the correct choice \n");
        }
    }
    return 0;
}