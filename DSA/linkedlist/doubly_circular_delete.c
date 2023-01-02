#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next ;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;
int count = 0;

void create(int n)
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    printf("Enter the data in list : ");
    for (int i = 0 ; i< n ; i++)
    {
        if(head == NULL)
        {
            head = (struct node *) malloc (sizeof(struct node));
            temp = head;
            tail = temp;
            scanf("%d",&head->data);
        }
        else
        {
            newnode = (struct node*) malloc (sizeof(struct node));
            temp -> next = newnode;
            newnode ->prev = temp ;
            temp = newnode;
            tail  = temp ;
            scanf("%d",&newnode -> data);
        }
        tail -> next = head;
        head -> prev = tail;
        count++;
    }
}

void delete()
{
    struct node *temp = NULL;
    temp = head;
    head = head -> next;
    tail -> next = head;
    head -> prev = tail ;
    free (temp);
    temp = NULL;
    count --;
}

void deleteend()
{
    struct node *temp = NULL;
    temp = tail;
    tail = tail -> prev;
    tail -> next = head;
    free(temp);
    temp = NULL;
    count--;
}

void deletepos()
{
    int pos , i = 0;
    struct node *nextnode = NULL;
    struct node *current = NULL;
    printf("\nEnter the postion : ");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("\nEntered position is invalid : ");
    }
    else
    {
        nextnode = head;
        while(i<pos)
        {
            current = nextnode;
            nextnode = nextnode -> next;
            i++;
        }
        current ->next = nextnode -> next;
        nextnode->prev = current;
        free(nextnode);
        nextnode = NULL;
    }
}

void display()
{
    struct node *temp = NULL;
    temp = head;
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        while(temp != tail)
        {
            printf("%d\t",temp->data);
            temp = temp -> next;
        }
        printf("%d",temp -> data);
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    create(n);
    display();
    delete();
    printf("\nAfter deletion at the begining of the link list : \n");
    display();
    deleteend();
    printf("\nAfter deletion at the end of the link list : \n");
    display();
    deletepos();
    printf("\nAfter deletion at the pos of the link list : \n");
    display();
}