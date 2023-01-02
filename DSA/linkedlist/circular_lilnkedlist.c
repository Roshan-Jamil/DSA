#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *ptr = NULL;

void create (int num)
{
    printf("Enter the data in linkedlist : \n");
    for (int i = 0 ; i < num ; i++)
    {
        if(i == 0)
        {
            head = (struct node *) malloc (sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr -> next = (struct node *) malloc (sizeof(struct node));
            ptr = ptr -> next;
        }
        scanf("%d",&ptr -> data);
    }
    ptr -> next = head;
}

void display()
{
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head ;
        while(ptr -> next != head)
        {
            printf("%d\t",ptr -> data);
            ptr = ptr -> next;
        }
        printf("%d\n",ptr -> data);
    }
}

int main()
{
    int data;
    printf("Enter the number of nodes reqired for linkedlist : ");
    scanf("%d",&data);
    create(data);
    display();
}