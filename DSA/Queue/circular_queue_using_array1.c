#include <stdio.h>
//#include <stdlib.h>

#define max 5

int front = -1;
int rear = -1;
int queue [max];

void enqueue (int data)
{
    if (front == -1 && rear == -1 )
    {
        front = rear = 0 ;
        queue[rear] = data;
    }
    else if (((rear + 1) % max ) == front )
    {
        printf("Queue is empty \n");
    }
    else
    {
        rear = (rear + 1 ) % max ;
        queue [rear] = data;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is underflow \n");
    }
    else
    {
        printf("Delelting element from queue is %d\n",queue[front]);
        front = (front + 1) % max ;
    }
}

void display ()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is underflow \n");
    }
    else
    {
        int i = front;
        printf("\nqueue is : \n");
        while(i != rear)
        {
            printf("%d\t",queue[i]);
            i = (i + 1) % max;
        }
        printf("%d\n",queue[rear]);
    }
}

int main()
{
    int data;
    int choice;
    printf("\npress 1. enqueue \npresss 2. dequeue \npress 3. display\npress 4. extit\n ");
    do
    {
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
            {
                printf("\nEnter the data in Queue : ");
                scanf("%d",&data);
                enqueue(data);
                break;
            }
            case 2 : 
            {
                dequeue();
                break;
            }
            case 3 : 
            {
                display();
                break;
            }
            case 4 : 
            {
                break;
            }
            default :
            {
                printf("\nEntered choice is invalid\n");
                break;
            }
        }
    }
    while(choice != 4);
    return 0 ;
}