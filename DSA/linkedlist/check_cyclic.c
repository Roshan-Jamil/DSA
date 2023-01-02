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
    struct node *newnode = NULL;
    printf("Enter the data in list : ");
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
    newnode->next = head->next->next->next -> next;
}

void checkcyclic()
{
    struct node *temp = head -> next;
    struct node *prev = head ;
    while (temp != tail)
    {
        if (tail -> next == temp)
        {
            
        }
    }
}

void display()
{
    struct node *temp = NULL;
    temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("\nlist is : ");
        while (temp != tail)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

int main()
{
    int num;
    printf("Enter the number of nodes reqired : ");
    scanf("%d", &num);
    create(num);
    display();
    checkcyclic();
}