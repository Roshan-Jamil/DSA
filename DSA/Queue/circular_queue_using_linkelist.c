#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
    struct node *newnode = NULL;
    newnode = (struct node *) malloc (sizeof(struct node));
    newnode -> data = value;
    newnode -> next = NULL;
    if (rear == NULL)
    {
        front = rear = newnode;
        newnode -> next = front;
    }
    else
    {
        rear -> next = newnode ;
        rear = newnode ;
        rear -> next = front;
    }
}

void dequeue()
{
    struct node *temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty \n");
    }

    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        printf("Deleting element is %d\n",temp->data);
        front = front -> next;
        free(temp);
        temp = NULL;
        rear -> next = front;
    }
}

void display()
{
    struct node *temp;
    temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is underflow \n");
    }
    else
    {
        printf("Queue is \n");
        while(temp -> next != front)
        {
            printf("%d\n",temp -> data);
            temp = temp -> next;
        }
        printf("%d\n",temp ->data);
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