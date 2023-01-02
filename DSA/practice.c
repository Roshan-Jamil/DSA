#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data)
{
    struct node *newnode = NULL;
    newnode = (struct node *) malloc (sizeof(struct node));
    newnode ->data = data;
    newnode -> next = NULL;
    if(front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear -> next = newnode;
        rear = newnode;
        
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
        while(temp != NULL)
        {
            printf("%d\t",temp->data);
            temp = temp -> next;
        }   
    }
}

void dequeue()
{
    struct node *temp = NULL;
    temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    printf("\nDeleting queue is %d \n",temp ->data );
    front = front -> next ;
    free (temp);
    temp = NULL;

}
int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    display();
    dequeue();
    display();
}