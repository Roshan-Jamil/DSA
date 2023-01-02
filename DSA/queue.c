#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max];
int rear = -1;
int front = -1;

void enqueue(int data)
{
    if(rear == max-1)
    {
        printf("Overflow ");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data; 
    }
    else
    {
        rear++;
        queue[rear] = data;
    }

}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("underflow ");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("\nDeleted element is %d\n", queue[front]);
        front ++;
    }
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        for(int i = front ; i<rear+1 ; i++)
        {
            printf("%d\t",queue [i]);
        }
    }
}

void peek ()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\npeek of this queue is %d",queue[front]);
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    peek();
    dequeue();
    display();
}