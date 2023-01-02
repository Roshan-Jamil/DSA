#include<stdio.h>
#include<stdlib.h>
#define max 5

int front = -1;
int rear = -1;
int queue [max];

void enqueue(int data)
{
    if (rear == max -1)
    {
        printf("Queue is full");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue [rear] = data;
    }
    
    else
    {
        rear++;
        queue[rear] = data;
    }
}

void display()
{
    if(front == max -1 && rear == max -1)
    {
        printf("queue is full\n");
    }

    printf("\nQueue is :\n");
    for(int i = front ; i<rear + 1 ; i++)
    {
        printf("%d\n",queue[i]);
    }
    
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is underflow \n");
    }
    else if(front == rear)
    {
        printf("Deleting element is : %d\n",queue[front]);
        front = rear = -1 ;
    }
    else
    {
        printf("Deleting element is : %d\n",queue[front]);
        front ++ ;
    }
}

int main()
{
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    display();
    enqueue(1);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    enqueue(5);
    display();
}