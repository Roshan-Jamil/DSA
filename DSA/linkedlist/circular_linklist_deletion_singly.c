#include <stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
struct node *temp = NULL;

int count = 0;

void create(int n)
{
    struct node *ptr = NULL;
    printf("Enter the data in list : ");
    for (int i = 0 ; i<n ; i++)
    {
        if(head == NULL)
        {
            head = (struct node *) malloc (sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr -> next = (struct node*) malloc (sizeof(struct node));
            ptr = ptr -> next;
        }
        scanf("%d",&ptr -> data);
        count ++;
    }
    tail = ptr ;
    tail -> next = head;
}

void delete()
{
    struct node *temp = NULL;
    temp = head;
    head = head -> next ;
    tail -> next = head;
    free (temp);
    temp = NULL;
    count --;
}

void deleteEnd()
{
    struct node *temp = NULL;
    struct node *current = NULL;
    temp = head;
    while(temp -> next != head)
    {
        current = temp;
        temp = temp -> next;
    }
    tail = current;
    tail -> next = head;
    free (temp);
    temp = NULL;
    count --;
}

void deletepos()
{
    int pos , i = 0;
    struct node *current = NULL;
    struct node *nextnode = NULL;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("\nEntered position is invalid \n");
    }
    else
    {
        nextnode = head;
        while (i < pos)
        {
            current = nextnode;
            nextnode = nextnode -> next;
            i++;
        }
        current -> next = nextnode -> next;
        current = nextnode;
        free (nextnode);
        nextnode = NULL;
    }
}

void display()
{
    struct node *temp = NULL;
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        temp = head;
        while(temp != tail)
        {
            printf("%d\t",temp -> data);
            temp = temp -> next;
        }
        printf("%d",temp -> data);
    }
}

int main()
{
    int num;
    printf("Enter the number of nodes require in linklist : ");
    scanf("%d",&num);
    create(num);
    display();
    delete();
    printf("\nAfter deletion list : \n");
    display();
    printf("\nAfter deletion list : \n");
    deleteEnd();
    display();
    printf("\nAfter deletion list : \n");
    deletepos();
    display();
}