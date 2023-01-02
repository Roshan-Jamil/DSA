#include <stdio.h>
//#include <stdlib.h>
#define max 5

int stack [max];
int top = -1;

void push(int d)
{
    if(top == max -1)
    {
        printf("\nStack is overflow \n");
    }
    else
    {
        top ++;
        stack [top] = d;
    }
}

void pop ()
{
    if(top == -1)
    {
        printf("\nStack is underflow\n");
    }
    else
    {
        printf("\nDeleting data from stack is : %d\n",stack[top]);
        top --;
    }
}

void display()
{
    if(top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("Stack is : \n");
        int i = top ;
        for (int j = i ; j >=0 ; j--)
        {
            printf("%d\n",stack[j]);
        }
    }
}

int main()
{
    int data;
    int choice;
    do
    {
        printf("\npress 1. push \npresss 2. pop \npress 3. display\npress 4. extit\nchoose : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
            {
                printf("\nEnter the data in stack : ");
                scanf("%d",&data);
                push(data);
                break;
            }
            case 2 : 
            {
                pop();
                break;
            }
            case 3 : 
            {
                display();
                break;
            }
            case 4 : 
            {
                break;
            }
            default :
            {
                printf("\nEntered choice is invalid\n");
                break;
            }
        }
    }
    while(choice != 4);
    return 0 ;
}