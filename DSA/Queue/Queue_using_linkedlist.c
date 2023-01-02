#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL ;

void push (int value)
{
    struct node *newnode = (struct node*) malloc (sizeof(struct node));
    newnode -> data = value;
    newnode -> next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear -> next = newnode ;
        rear = newnode;
    }
}

void display()
{
    struct node *temp;
    temp = front;
    printf("Queue is : \n");
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty \n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d\n",temp->data);
            temp = temp -> next;
        }
    }
}

void dequeue()
{
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        front = rear = NULL;
        printf("Queue is empty");
    }
    else
    {
        struct node *temp ;
        temp = front ;
        front = front -> next;
        free (temp);
        temp = NULL;
    }
}

int main()
{
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    display();
    dequeue();
    display();
}
