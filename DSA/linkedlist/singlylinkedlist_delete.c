#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int count = 0;
struct node *head = NULL;
struct node *ptr = NULL ;

void createlist (int n)
{
    printf("Enter the elements in list : ");
    for (int i = 0 ; i<n ; i++)
    {
        if (i == 0)
        {
            head = (struct node *) malloc (sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr -> next = (struct node *) malloc (sizeof(struct node));
            ptr = ptr -> next;
        }

        scanf("%d",&ptr->data);
        count ++;
    }
    ptr -> next = NULL;
}

void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        ptr = head ;
        while (ptr != NULL)
        {
            printf("%d\t",ptr -> data);
            ptr = ptr -> next ;
        }
    }
}

void deletefront()
{
    ptr = head ;
    head = head -> next ;
    free (ptr);
    ptr = NULL;
}

void deleteEnd()
{
    struct node *prev = NULL;
    ptr = head;
    while(ptr -> next != NULL)
    {
        prev = ptr;
        ptr = ptr -> next ;
    }
    prev -> next = NULL;
    free (ptr);
    ptr = NULL;

}

void deletepos()
{
    struct node *temp = NULL;
    int pos , i = 1;
    ptr = head;
    printf("\nEnter the position of deltion : ");
    scanf("%d",&pos);
    if(pos > count )
    {
        printf("Invalid input\n");
    }
    else
    {
        while (i < pos - 1)
        {
            ptr = ptr -> next ;
            i++;
        }
        temp = ptr-> next ;
        ptr -> next = temp -> next;
        free(temp);
        temp = NULL;
    }
}

int main()
{
    int num;
    printf("Enter the number of nodes required in linkelist : ");
    scanf("%d",&num);
    createlist(num);
    display();
    printf("\nAfter deleting at the front of the lilnkelist : \n");
    deletefront();
    display();
    printf("\nAfter deleteing at the end of the linkelist : \n");
    deleteEnd();
    display();
    deletepos();
    printf("\nAfter deleting at the end of the linkedlist : \n");
    display();
}