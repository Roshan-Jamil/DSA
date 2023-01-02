#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void createlist(int n)
{
    struct node *ptr = NULL;
    struct node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = (struct node *)malloc(sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr->next = (struct node *)malloc(sizeof(struct node));
            ptr = ptr->next;
        }
        scanf("%d", &ptr->data);
    }

    ptr->next = NULL;
    ptr = head;
}

void display()
{
    struct node *ptr, *head;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
// int countnodes(struct node *node)
// {
//     struct node *ptr, *head;
//     ptr = head;
//     int count = 0;
//     while (ptr != NULL)
//     {
//         ptr = ptr->next;
//         count++;
//     }
//     return count;
// }
void insert_node()
{
    struct node *ptr, *head;
    struct node *newhead = NULL;
    ptr = head;
    newhead = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the new element in linkedlist : ");
    scanf("%d", &newhead->data);
    newhead->next = head;
    head = newhead;
    ptr = head;
}
void insert_node_end()
{
    struct node *head, *ptr;
    struct node *newnode = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the new element for end of the linkedlist : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    ptr = head;
}
void inser_pos(int count)
{
    int pos, i = 0;
    struct node *head, *ptr;
    struct node *node = NULL;
    node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the position of at which the node is added :");
    scanf("%d", &pos);
    //int count = countnodes(head);
    if (pos > count)
    {
        printf("\nInvalid position to insert a node ");
    }
    else
    {
        ptr = head;
        while (pos > i)
        {
            ptr = ptr->next;
            i++;
        }
        printf("Enter the data of the node : ");
        scanf("%d", &node->data);
        node->next = ptr->next;
        ptr->next = node;
    }
    ptr = head;
}

int main()
{
    int n;
    printf("Enter the number of nodes required for linkedlist : ");
    scanf("%d", &n);
    printf("Enter the elements for linkedlist : ");
    createlist(n);
    display();
    // insert_node();
    // display();
    // insert_node_end();
    // display();
    inser_pos(n);
    display();
}
