#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void createlist(int n)
{
    struct node *ptr = NULL;
    printf("Enter the data in nodes : ");
    for (int i = 0 ; i<n ; i++)
    {
        if(i == 0)
        {
            head = (struct node *) malloc (sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr -> next = (struct node*) malloc (sizeof(struct node));
            ptr = ptr -> next;
        }
        scanf("%d",&ptr->data);
    }
    ptr->next = NULL;
}

void reverse ()
{
    struct node *prev = NULL;
    struct node *ptr = NULL;
    struct  node *temp = NULL;
    ptr = head;
    //prev = head;
    temp = head;
    printf("\n");
    while (temp != NULL)
    {
        ptr = temp -> next;
        temp -> next = prev;
        prev  = temp;
        temp = ptr;
    }
    head = prev;
}

void display()
{
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d\t",ptr ->data);
        ptr = ptr -> next;
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes required : ");
    scanf("%d",&n);
    createlist(n);
    display();
    reverse();
    display();

}