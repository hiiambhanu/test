#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;


struct node* search(int data, struct node* root){
    struct node* temp = root;
    if(root == NULL){
        return root;
    }

    if(data==root->data){
        return root;
    }

    if(data>root->data){
        search(data, root->right);
    }

    else 
        search(data, root->left);
}


struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 
  
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
  
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
  
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        struct node* temp = minValueNode(root->right); 
  
        root->data = temp->data; 
  
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 


void insert(int data, struct node** head){
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    if(*head == NULL){
        *head = newnode;
        return;
    }

    if(data>(*head)->data){
        insert(data, &(*head)->right);
    }
    else
    {
        insert(data, &(*head)->left);
    }

}

void inorderdisp(struct node* root){
    if(root!=NULL){
        inorderdisp(root->left);
        printf("%d ", root->data);
        inorderdisp(root->right);
    }
    return;
}

int main(){

    int choice, data;
    struct node* tmp ;
    while(1){
        printf("\n1. Insert\n2. Search\n3. Display\n4. Delete\n5. Exit\nEnter your choice");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("Enter the data ");
            scanf("%d", &data);
            insert(data,&root);
            break;
        case 2:
            printf("Enter the element to be searched ");
            scanf("%d", &data);
            tmp = search(data, root);
            if(tmp==NULL)
                printf("Element not found ");
            else    
                printf("Element found ");

            break;
        case 3: 
            inorderdisp(root);
            break;
        case 4: 
            printf("enter the data ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;
        case 5:
            return 0; 
        default:
            break;
        }
    }
    return 0;
}