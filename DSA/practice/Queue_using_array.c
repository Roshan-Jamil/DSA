#include <stdio.h>
//#include<stdlib.h>

#define max 5

int queue[max];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data ;
    }
    else if (rear == max -1)
    {
        printf("\nQueue is overflow\n");
    }
    else
    {
        rear ++;
        queue[rear] = data;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is underflow\n");
    }
    else if (rear == front)
    {
        front = rear = -1;
    }
    else
    {
        printf("\nDeleting Queue is %d\n",queue[front]);
        front ++;
    }
}

void display()
{

    if (front == -1 && rear == -1)
    {
        printf("\nQueue is underflow\n");
    }
    else 
    {
        printf("\nQueue is : \n");
        int i = front;
        for (int j = i ; j<=rear ; j++)
        {
            printf("%d\n",queue[j]);
        }
    }
}

int main()
{
    int data;
    int choice;
    do
    {
        printf("\npress 1. enqueue \npresss 2. dequeue \npress 3. display\npress 4. extit\nchoose : ");
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