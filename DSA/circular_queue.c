#include <stdio.h>
#include <stdlib.h>
#define max 5

int front = -1;
int rear = -1;
int queue[max];

void enqueue(int data)
{
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else if(((rear+1)%max) == front)
    {
        printf("\nQueue is full\n");
    }
    else
    {
        rear = (rear+1)%max;
        queue [rear] = data;
    }
}
void display()
{
    int i = front;
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("Queue is : ");
        while(i != rear)
        {
            printf("%d\t",queue[i]);
            i = (i+1)%max;
        }
        printf("%d\t",queue[rear]);
    }
}
void dequeue()
{
     if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("%d",queue[front]);
        front = (front + 1 ) % max;
    }
}

int main()
{
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    display();
    printf("\n");
    dequeue();
    enqueue(9);
    display();
}