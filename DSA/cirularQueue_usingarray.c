#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max];
int front = -1;
int rear = -1;

void enqueue (int data)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else if (((rear +1)%max) == front)
    {
        printf("\nQueue is full\n");
    }
    else 
    {
        rear = (rear + 1) % max;
        queue [rear] = data;
    }
}

void dequeue ()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nDeleting element in queue is %d \n",queue[front]);
        front = (front + 1)%max;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("Queue is : ");
        while (i != rear)
        {
            printf("%d\t",queue[i]);
            i = (i+1)%max;
        }
        printf("%d\n",queue[rear]);
        
    }
}

int main()
{
    int choice , data;
    do 
    {
        printf("\n1.Enqueue");
        printf("\n2.dequeue");
        printf("\n3.display");
        printf("\n4.exit");
        printf("Enter choice [1/2/3/4] : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1 :
            {
                printf("Enter the element in Queue : ");
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
                exit(1);
            }

            default :
            {
                printf("Please Enter valid value [1/2/3/4] : \n");
            }
        }
    }
    while(choice != 4);
}