#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next ;
};

struct node *head = NULL;
struct node *ptr  = NULL;

void create(int n)
{
    printf("Enter the data in linkedlist : ");
    for (int i = 0 ; i <n ; i++)
    {
        if(i == 0)
        {
            head = (struct node *) malloc (sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr -> next = (struct node *) malloc (sizeof(struct node));
            ptr = ptr -> next ;
        }
        scanf("%d",&ptr -> data);
    }
    ptr -> next = NULL ;
}

void display()
{
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr -> next ;
    }
}

void reverse()
{
    struct node *temp = NULL;
    struct node *prev = NULL;

    ptr = temp = head;
    while(temp != NULL)
    {
        temp = temp -> next;
        ptr -> next = prev;
        prev = ptr ;
        ptr = temp;
    }
    head = prev;
}

int main ()
{
    int i;
    printf("Enter the number of nodes required : ");
    scanf("%d",&i);
    create(i);
    display();
    reverse();
    printf("\nAfter reversing singly linkedlist : \n");
    display();
}
