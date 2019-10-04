#include<stdio.h>
#define MAX 20
struct Queue{
    int arr[MAX];
    int front;
    int rear;
};
void enqueue(struct Queue* q, int data){
    if(q->rear == -1 && q->front == -1 ){
        q->rear =0;
        q->front =0;
        q->arr[q->rear] =data;
        return;
    }
    q->arr[++q->rear]=data;
}

void dequeue(struct Queue *q){
    printf("The front-most element in the queue is %d\n", q->arr[q->front]);
    if(q->front == q->rear)
        {
            q->front = 0;
            q->rear = 0;
        }
    else
    {
        q->front ++;
    }
} 
void isempty(struct Queue *q){

}
void main(){
    struct Queue q;
    q.front = -1;
    q.rear = -1;

}