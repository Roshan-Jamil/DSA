#include <stdio.h>
#include <stdlib.h>
#define max 5

int stack [max];
int top = -1;

void push(int data)
{
    printf("Enter the data for the stack : ");
    scanf("%d",&data);
    if(top == max-1)
    {
        printf("Stack is overflow \n");
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack is underflow ");
    }
    else
    {
        top--;
    }
}

void display()
{
    if(top == -1)
    {
        printf("\nStack is empty ");
    }
    else
    {
        for(int i = top ; i>=0 ; i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    int x , choice;
    printf("Enter the data in stack : ");

    do
    {
        printf("Enter the choice [1. push , 2. pop , 3. display , 4.exit] : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
            {
            push(x);
            break;
            }
            
            case 2 :
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                exit(1);
                break;
            }
            default :
            {
                printf("Please enter the valid choice : ");
                break;
            }
        }
    }
    while(choice != 4);

}