#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *ptr = NULL;

void create(int n)
{
    struct node *temp = NULL;
    printf("Enter the data in list : ");
    for (int i = 0 ; i<n ; i++)
    {
        if(i == 0)
        {
            head = (struct node*) malloc (sizeof(struct node));
            ptr = head;
            scanf("%d",&ptr -> data);
        }
        else
        {
            temp = ptr -> next;
            temp = (struct node *) malloc (sizeof(struct node));
            temp -> prev = ptr ;
            ptr -> next = temp ;
            scanf("%d",&temp -> data);
            temp -> next  = head;
            ptr = temp;
            tail = temp;
        }
    }
}
void display()
{
    printf("List is : \n");
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head ;
        while (ptr -> next != head)
        {
            printf("%d\t",ptr -> data);
            ptr = ptr -> next;
        }
        printf("%d",ptr -> data);
    }
}

int main()
{
    int num;
    printf("Enter the number of nodes required in list : ");
    scanf("%d",&num);
    create(num);
    display();
}