#include <stdio.h>
#include <stdlib.h>
#define max 5

int top = -1;
int stack[max];
void push(int data)
{
    printf("value for stack :");
    scanf("%d",&data);
    if (top == max-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = data;
    }
}
int pop()
{
    int value;
    if(top == -1)
    {
        printf("stack underflow");
        exit(1);
    }
    value = stack[top];
    top--;
    return value;
}
void display()
{
    if(top == -1)
    {
        printf("Stack is underflow");
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
    int choice , x , value;
    do
    {
        printf("Enter the choice : 1. push , 2. pop , 3. display , 4. exit : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            {
                push(x);
                break;
            }
            case 2:
            {
                value = pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("Exit the stack");
                break;
            }
            default:
            {
                printf("Please Enter the valid no. (1/2/3/4)");
                break;
            }

        }
    }
    while(choice != 4);

    
    // int value;
    // push(1);
    // push(2);
    // push(3);
    // push(4);
    // push(5);
    // value = pop();
    // value = pop();
    // value = pop();
    // value = pop();
    // display();
}

