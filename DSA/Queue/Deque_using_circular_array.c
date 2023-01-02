#include <stdio.h>
#include <stdlib.h>
#define max 5

int deque[max];
int front = -1;
int rear = -1;

void enquefront(int data)
{
    if ((front == 0 && rear == max-1) || (front  == rear+1))
    {
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque [front] = data ;
    }
    else if (front == 0)
    {
        front = max -1;
        deque[front] = data ;
    }
    else
    {
        front --;
        deque[front] = data ;
    }
}

void enquerear (int data)
{
    if ((front == 0 && rear == max -1) || (front  == rear + 1))
    {
        printf("Queue is full \n");
    }
    else if (rear == max - 1)
    {
        rear = 0;
        deque[rear] = data ;
    }
    else 
    {
        rear ++;
        deque[rear] = data ;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is underflow \n");
    }
    else 
    {
        int i = front ;
        while (i != rear)
        {
            printf("%d\n",deque[i]);
            i = (i+1)%max;
        }
        printf("%d\n",deque[rear]);
    }
}

void dequefront()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is underflow\n");
    }
    else if (front == max -1)
    {
        printf("Deleted element is %d\n",deque[front]);
        front = 0;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("Deleted element is %d\n",deque[front]);
        front ++;
    }
}

int main()
{
    enquefront(5);
    enquerear(4);
    enquerear(4);
    enquerear(4);
    enquefront(5);
    display();
    printf("Deleting elements from queue\n");
    dequefront();
    display();
}