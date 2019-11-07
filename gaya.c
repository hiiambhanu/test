#include <stdio.h>
#include <stdlib.h>
struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
} *root = NULL, *temp = NULL, *t1, *t2;
void delete1();
void insert();
void delete ();
void inorder(struct btnode *t);
void search(struct btnode *t);
void inorder(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);
void search1(struct btnode *t, int data);
int smallest(struct btnode *t);
int largest(struct btnode *t);
int flag = 1;
void main()
{
    int choice;
    printf("\n1.insert element in tree\n2.delete element from tree\n3.inorder\n4.preorder\n5.postorder\n6.exit\n");
    while (1)
    {
        printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("wrong choice\n");
            break;
        }
    }
}
void insert()
{
    int data;
    printf("enter the data to be inserted\n");
    scanf("%d", &data);
    temp = (struct btnode *)malloc(sizeof(struct btnode));
    temp->value = data;
    temp->l = temp->r = NULL;
    if (root == NULL)
        root = temp;
    else
        search(root);
}
void search(struct btnode *t)
{
    if ((temp->value > t->value) && (t->r != NULL))
        search(t->r);
    else if ((temp->value > t->value) && (t->r == NULL))
        t->r = temp;
    else if ((temp->value > t->value) && (t->l != NULL))
        search(t->l);
    else if ((temp->value > t->value) && (t->l == NULL))
        t->l = temp;
}
void inorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("no elements in tree\n");
    }
    if (t->l != NULL)
        inorder(t->l);
    printf("%d", t->value);
    if (t->r != NULL)
        inorder(t->r);
}
void delete ()
{
    int data;
    if (root == NULL)
    {
        printf("no elements in tree\n");
    }
    printf("enter the data to be deleted\n");
    scanf("%d", &data);
    t1 = root;
    t2 = root;
    search1(root, data);
}
void preorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("no elements in tree\n");
    }
    printf("%d", t->value);
    if (t->l != NULL)
        preorder(t->l);
    if (t->r != NULL)
        preorder(t->r);
}
void postorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("no elements in tree\n");
    }
    if (t->l != NULL)
        postorder(t->l);
    if (t->r != NULL)
        postorder(t->r);
    printf("%d", t->value);
}
void search1(struct btnode *t, int data)
{
    if ((data > t->value))
    {
        t1 = t;
        search1(t->r, data);
    }
    else if ((data < t->value))
    {
        t1 = t;
        search1(t->l, data);
    }
    else if ((data == t->value))
    {
        delete1(t);
    }
}
void delete1(struct btnode *t)
{
    int k;
    if ((t->l == NULL) && (t->r == NULL))
    {
        if (t1->l == t)
        {
            t1->l = NULL;
        }
        else
        {
            t1->r = NULL;
        }
        t = NULL;
        free(t);
    }
else if(t->r==NULL)
{
        if (t1 == t)
        {
            root = t->l;
            t1 = root;
        }
        else if (t1->l == t)
        {
            t1->l = t->l;
        }
        else
        {
            t1->r = t->l;
        }
        t = NULL;
        free(t);

}
else if (t->l == NULL)
{
    if (t1 == t)
    {
        root = t->r;
        t1 = root;
    }
    else if (t1->r == t)
        t1->r = t->r;
    else
        t1->l = t->r;
    t == NULL;
    free(t);
}
else if ((t->l != NULL) && (t->r != NULL))
{
    t2 = root;
    if (t->r != NULL)
    {
        k = smallest(t->r);
        flag = 1;
    }
    else
    {
        k = largest(t->l);
        flag = 2;
    }
    search1(root, k);
    t->value = k;
}
}
int smallest(struct btnode *t)
{
    t2 = t;
    if (t->l != NULL)
    {
        t2 = t;
        return (smallest(t->l));
    }
    else
        return (t->value);
}
int largest(struct btnode *t)
{
    if (t->r != NULL)
    {
        t2 = t;
        return (largest(t->r));
    }
    else
        return (t->value);
}