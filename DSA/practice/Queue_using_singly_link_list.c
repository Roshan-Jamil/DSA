#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear  = NULL;
struct node *head = NULL;

void enqueue(int value)
{
    
    head = (struct node*) malloc (sizeof(struct node));
    head -> data = value;
    head -> next = NULL;
    if(front == NULL && rear == NULL)
    {
        front = rear = head;
    }
    else
    {
        rear->next= head;
        rear = head;
    }
}

void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("\nQueue is empty\n");
    }
    else if(rear == front)
    {
        rear = front = NULL;
    }
    else
    {
        printf("\nDeleting data from queue is : %d",front -> data);
        front = front -> next;
    }
}

void display()
{
    struct node *temp = NULL;
    if(front == NULL && rear == NULL)
    {
        printf("\nQueue is underflow\n");
    }
    else
    {
        temp = front;
        while(temp != rear)
        {
            printf("%d\t",temp-> data);
            temp = temp -> next;
        }
        printf("%d",rear->data);
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