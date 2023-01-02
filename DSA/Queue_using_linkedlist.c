#include<stdio.h>
#include<stdlib.h>

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
    newnode ->data = value;
    if(front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next  = newnode ;
        newnode->next = NULL;
        rear = newnode;
    }
}

void display()
{
    struct node *temp = NULL;
    temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty \n");
    }

    else
    {

        while(temp != NULL)
        {
            printf("%d\t",temp ->data);
            temp = temp -> next;
        }
    }
    
}

void dequeue()
{
    struct node *temp = NULL;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty : ");
    }
    else
    {
        printf("\nDeleting queue is %d\n", temp->data);
        front = front -> next;
        free (temp);
        temp = NULL;
    }
}

int main()
{

    display();
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display();
    dequeue();
    display();
    
}