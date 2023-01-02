#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *ptr;

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
/*void inser_pos(int count)
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
}*/

void insertnode()
{
    printf("\nit is working");
    int pos , i , nodes = 0;
    struct node *prev, *head , *newnode ;
    struct node *ptr = head;
    printf("\nit is working2222222222222222");
    while (ptr != NULL)
    {
        nodes++;
        ptr = ptr->next;
    }
    printf("\nit is working3333333");
    printf("\nEnter the position : ");
    scanf("%d", &pos);
    if(pos < 1 || pos>nodes)
    {
        printf("\nPosition entered is Invalid \n");
    }

    newnode = (struct node*) malloc (sizeof(struct node));
    printf("Enter the new data : ");
    scanf("%d",&newnode ->data);
    newnode ->next = NULL;

    if (pos == 1)
    {
        newnode ->next = head;
        head = newnode;
    }
    i = 1;
    while(i<pos)
    {
        i++;
        ptr = prev;
        ptr = ptr ->next;
    }
    newnode ->next = prev->next;
    prev ->next = newnode;
}

void delete()
{
    printf("\n1");
    struct node *head ;
    struct node *temp;
    printf("\n3");
    temp = head;
    head = head -> next;
    printf("\n2");
    free(temp);
    ptr = head;

}
void delete_end()
{
    struct node *temp = NULL;
    temp = head;
    while(temp ->next = NULL)
    {
        ptr = temp;
        temp -> next = NULL;
    }
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

int main()
{
    int n;
    printf("Enter the number of nodes required for linkedlist : ");
    scanf("%d", &n);
    printf("Enter the elements for linkedlist : ");
    createlist(n);
    display();
    delete_end();
    display();
}
