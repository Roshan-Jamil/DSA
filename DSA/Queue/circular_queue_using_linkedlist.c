/*#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue (int value)
{
    struct node *newnode = NULL;
    newnode = (struct node *) malloc (sizeof(struct node));
    newnode ->data = value;
    newnode -> next = NULL;
    if(rear == NULL)
    {
        front = rear = newnode;
        newnode -> next = front; 
    }
    else
    {
        rear -> next = newnode;
        rear  = newnode;
        newnode -> next = front ;
    }
}

void dequeue()
{
    struct node *temp = NULL;
    temp = front;
    if (front == NULL  && rear == NULL)
    {
        printf("Queue is empty\n");
    }

    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front ->  next;
        free (temp);
        temp = NULL;
        rear -> next = NULL;
    }
}

void display()
{
    struct node *temp = NULL;
    temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is : \n");
        while(temp ->next != front)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
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
    dequeue();
    display();
}
*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue (int value)
{
    struct node *newnode = NULL;
    newnode = (struct node *) malloc (sizeof(struct node));
    newnode ->data = value;
    newnode -> next = NULL;
    if (rear == NULL)
    {
        front = rear = newnode ;
        newnode -> next = front ;
    }
    else
    {
        rear -> next = newnode;
        rear = newnode ;
        rear -> next = front ;
    }
}

void dequeue()
{
    struct node *temp = NULL;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("Queue is underflow");
    }

    else if (front == rear)
    {
        front = rear= NULL;
    }

    else
    {
        front = front -> next ;
        free (temp);
        temp = NULL;
        rear -> next = front ;
    }
}

void display()
{
    struct node *temp = NULL;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("Queue is \n");
        while(temp -> next != front)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp -> data);
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









