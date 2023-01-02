#include <stdio.h>
#include <stdlib.h>
#define max 5

int deque[max];
int front = -1;
int rear = -1;

void enqueuefront(int data)
{
    if((front == 0 && rear == max -1) || (front == rear +1))
    {
        printf("\nQueue is overfloq \n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front]= data;
    }
    else if (front == 0 )
    {
        front = max -1;
        deque[front] = data;
    }
    else
    {
        front --;
        deque[front] = data;
    }
}

void enquerear (int data)
{
    if((front == 0 && rear == max -1)  || (front == rear +1))
    {
        printf("\nQueue is overflow\n");
    }
    else if (rear == max -1)
    {
        rear = 0;
        deque[rear] = data ;
    }
    else 
    {
        rear ++;
        deque[rear] = data;
    }
}

void display()
{
    
    
    int i = front;
    while(i != rear)
    {
        printf("%d\t",deque[i]);
        i = (i + 1) % max;
    }
    printf("%d\t",deque[rear]);
}

void dequefront()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is underflow\n");
    }
    else if (front == 0)
    {
        printf("\nDeleting data from queue is %d \n",deque[front]);
        front ++ ;
    }
    else if (front == max -1)
    {
        printf("\n Deleting data from queue is %d \n",deque[front]);
        front  = 0 ;
    }
    else
    {
        printf("\n Deleting data from queue is %d \n",deque[front]);
        front ++;
    }
}

void dequerear ()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is overflow \n");
    }
    else if (rear == 0)
    {
        printf("\nDeleting element is %d\n",deque[rear]);
        rear = max -1;
    }
    else
    {
        printf("\nDeleting element is %d\n",deque[rear]);
        rear --;
    }
}

int main()
{
    enqueuefront(5);
    enqueuefront(4);
    enquerear(5);
    enqueuefront(3);
    display();
    dequefront ();
    display();
    dequerear();
    display();
}