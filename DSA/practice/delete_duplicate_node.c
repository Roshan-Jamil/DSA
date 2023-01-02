#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void create(int num)
{
    printf("\nEnter the data in list : ");
    struct node *newnode = NULL;
    for (int i = 0; i < num; i++)
    {
        if (head == NULL)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            head = newnode;
        }
        else
        {
            newnode->next = (struct node *)malloc(sizeof(struct node));
            newnode = newnode->next;
        }
        scanf("%d", &newnode->data);
    }
    tail = newnode;
    newnode->next = NULL;
}

void delete_duplicate()
{
    struct node *temp = NULL;
    struct node *ptr = NULL;
    struct node *tr = NULL;
    temp = head;
    while (temp != NULL && temp -> next != NULL)
    {
        ptr = temp;
        while (ptr->next != NULL)
        {
            if (temp -> data == ptr -> next -> data)
            {
                tr = ptr -> next;
                ptr -> next = ptr -> next -> next;
                free(tr);
                tr = NULL;
            }
            else 
            {
                ptr = ptr -> next;
            }
        }
        temp = temp -> next;
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
    int num;
    printf("Enter the number of nodes required : ");
    scanf("%d", &num);
    create(num);
    display();
    delete_duplicate();
    display();
}