#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct Queue
{
    int arr[MAX];
    int front;
    int rear;
};

void display(struct Queue *q){
    int i;
    if(q->front == -1 && q->rear == -1)
        {
            printf("The queue is empty\n");
            return;
        }
    printf("The queue is :");
    for(i=q->front;i<=q->rear;i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

void enqueue(struct Queue *q, int data)
{
    if (q->rear == -1 && q->front == -1)
    {
        q->rear = 0;
        q->front = 0;
        q->arr[q->rear] = data;
        return;
    }
    q->arr[++q->rear] = data;
}

void dequeue(struct Queue *q)
{
    if (!(q->front == -1 && q->rear == -1))
    {
        printf("The front-most element in the queue is %d\n", q->arr[q->front]);
        
         if (q->front == 0 && q->rear == 0)
        {
            q->front = -1;
            q->rear = -1;
        }
        else if (q->front == q->rear)
        {

            q->front = 0;
            q->rear = 0;
        }
        else
        {

            q->front++;
        }
    }

    else
        printf("The queue is empty\n");
}

void main()
{
    struct Queue q;
    int ch;
    int item;
    q.front = -1;
    q.rear = -1;

    while (1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Isempty \n4. Display\n5. Exit\nEnter your choice. ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the item ");
            scanf("%d", &item);
            enqueue(&q, item);
            break;
        case 2:
            dequeue(&q);
            break;
        case 4:
            display(&q);
            break;
        case 5:
            exit(0);
        case 3:
            if (q.front == -1 && q.rear == -1)
                printf("The queue is empty\n");
            else
            {
                printf("The queue is not empty\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}