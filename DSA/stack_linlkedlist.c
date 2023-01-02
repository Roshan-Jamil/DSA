#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; 
    struct node *link;
} *top = NULL;

void push(int data)
{
    struct node *newnode =(struct node*) malloc (sizeof(struct node));
    if(newnode == NULL)
    {
        printf("stack underflow \n");
        exit(1);
    }
    newnode -> data = data;
    newnode -> link = top;
    top = newnode;
}

int empty()
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop()
{
    int val;
    struct node * temp;
    temp = top;
    if(empty())
    {
        printf("Stack underflow \n");
    }
    val = temp -> data;
    top = top -> link;
    free(temp);
    temp = NULL;
}

void display()
{
    struct node *temp;
    temp = top;
    if(empty())
    {
        printf("stack underflow ");
        exit(1);
    }
    printf("Entered value of stack are : \n");
    while (temp)
    {
        printf("%d\n",temp->data);
        temp = temp -> link;
    }
    printf("\n");
}

int peek()
{
    if(empty())
    {
        printf("Stack underflow ");
        exit(1);
    }

    return top -> data;
}

int main()
{
    int choice , data;
    while(1)
    {
        printf("1. Push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. display\n");
        printf("5. exit\n");

        printf("Enter the choice [1/2/3/4/5] : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("Enter the data in stack : ");
            scanf("%d",&data);
            push(data);
            break;

            case 2:
            pop();
            printf("poped element of stack is : %d \n", data);
            break;

            case 3:
            printf("The topmost element of stack is : %d\n", peek());
            break;

            case 4:
            display();
            break;

            case 5:
            exit(1);

            default :
            printf("Invalid input please input [1/2/3/4/5] : \n");
            break;
        }
    }
    return 0;
}
    