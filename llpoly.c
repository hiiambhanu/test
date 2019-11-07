#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff, exp;
    struct node *next;
} *eqn1 = NULL, *eqn2 = NULL, *eqn3 = NULL;

void dispPoly(struct node *thead)
{
    struct node *temp = thead;
    if (temp == NULL)
    {
        printf("\nEmpty..");
    }
    else
    {
        while (temp->next != NULL)
        {
            printf(" %dx^%d +", temp->coeff, temp->exp);
            temp = temp->next;
        }
        printf(" %dx^%d ", temp->coeff, temp->exp);
    }
}

struct node *insNode(struct node *start, int a, int b)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->coeff = a;
    head->exp = b;
    if (start)
    {
        struct node *temp = start;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = head;
    }
    else
    {
        start = head;
    }
    return start;
}
struct node *polyaddition(struct node *p1thead, struct node *p2thead)
{
    struct node *ans = NULL;
    struct node *t1, *t2;
    t1 = p1thead;
    t2 = p2thead;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->exp > t2->exp)
        {
            ans = insNode(ans, t1->coeff, t1->exp);
            t1 = t1->next;
        }
        else if (t1->exp < t2->exp)
        {
            ans = insNode(ans, t2->coeff, t2->exp);
            t2 = t2->next;
        }
        else
        {
            ans = insNode(ans, (t1->coeff) + (t2->coeff), t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    while (t1 != NULL)
    {
        ans = insNode(ans, t1->coeff, t1->exp);
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        ans = insNode(ans, t2->coeff, t2->exp);
        t2 = t2->next;
    }
    return ans;
}
struct node *getPoly(struct node *start)
{
    int a, b, i, n;
    printf("Enter number of terms in equation: ");
    scanf("%d", &n);
    printf("Enter coefficient and exponent of each term in equation:-\n");
    for (i = 1; i <= n; i++)
    {
        printf("\nEnter the coefficient and exponent of the term..");
        scanf("%d%d", &a, &b);
        start = insNode(start, a, b);
    }
    printf("Entered polynomial:-\n");
    dispPoly(start);
    printf("\n");
    return start;
}

void mulPoly()
{

    if (!eqn1 || !eqn2)
    {
        printf("0\n");
    }

    else
    {
        struct node *temp = eqn1, *temp2, *prev;
        int flag;

        while (temp)
        {
            temp2 = eqn2;
            while (temp2)
            {
                eqn3 = insNode(eqn3, (temp->coeff * temp2->coeff), (temp->exp + temp2->exp));
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        temp = eqn3;
        while (temp)
        {
            temp2 = temp->next;
            prev = temp;
            while (temp2)
            {
                if (temp->exp == temp2->exp)
                {
                    temp->coeff += temp2->coeff;
                    prev->next = temp2->next;
                }
                temp2 = temp2->next;
                prev = prev->next;
            }
            temp = temp->next;
        }

        dispPoly(eqn3);
    }
}

void main()
{
    int ch;
    struct node *res;
    printf("Enter polynomial equation 1:-\n");
    eqn1 = getPoly(eqn1);
    printf("Enter polynomial equation 2:-\n");
    eqn2 = getPoly(eqn2);
    printf("\n\nResult of polynomial multiplication:");
    while (ch != 3)
    {
        printf("\n1.Add\n2.Multiply\n3.Exit");
        printf("Enter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            res = polyaddition(eqn1, eqn2);
            dispPoly(res);
            break;
        case 2:
            mulPoly();

        default:
            break;
        }
    }
    printf("\n");
}