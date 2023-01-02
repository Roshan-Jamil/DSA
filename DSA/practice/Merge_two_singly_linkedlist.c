#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *head1 = NULL;
struct node *tail1 = NULL;
struct node *head2 = NULL;
struct node *tail2 = NULL;

void list1(int num)
{
    printf("\nEnter the data in list : ");
    struct node *newnode = NULL;
    for (int i = 0; i < num; i++)
    {
        if (head1 == NULL)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            head1 = newnode;
        }
        else
        {
            newnode->next = (struct node *)malloc(sizeof(struct node));
            newnode = newnode->next;
        }
        scanf("%d", &newnode->data);
    }
    tail1 = newnode;
    newnode->next = NULL;
}

void list2(int num)
{
    printf("\nEnter the data in list : ");
    struct node *newnode = NULL;
    for (int i = 0; i < num; i++)
    {
        if (head2 == NULL)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            head2 = newnode;
        }
        else
        {
            newnode->next = (struct node *)malloc(sizeof(struct node));
            newnode = newnode->next;
        }
        scanf("%d", &newnode->data);
    }
    tail2 = newnode;
    newnode->next = NULL;
}

void merge()
{
    int choice;
    struct node *merge = NULL;
    printf("\npress 1. list1 + list2 \npress 2. list2 + list1 : ");
    scanf("%d",&choice);
    if(choice == 1)
    {
        head = head1;
        tail1 -> next = head2;
    }
    else 
    {
        head = head2;
        tail2 -> next = head1;
    }
}

void display()
{
    struct node *temp = NULL;
    temp = head;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf("\nList is : \n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int num1 , num2;
    printf("Enter the number of nodes required : ");
    scanf("%d", &num1);
    list1(num1);
    printf("Enter the number of nodes required : ");
    scanf("%d", &num2);
    list2(num2);
    merge();
    display();
    
}