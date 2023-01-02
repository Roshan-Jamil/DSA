#include <stdio.h>
#include <stdlib.h>
#define max 5

int top = -1;
int stack[max];

void push(int n)
{
    if(top == max -1)
    {
        printf("Stack overflow \n");
    }
    else
    {
        top++;
        stack[top] = n;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack underflow \n");
    }
    else
    {
        printf("\nDeleting element is : %d\n",stack[top]);
        top--;
    }
}

void display ()
{
    if(top == -1)
    {
        printf("Stack underflow \n");
    }

    else
    {
        printf("\nStack is : \n");
        int i = top;
        for (int j = i ; j>=0 ; j--)
        {
            printf("%d\n",stack[j]);
        }
    }
}

int main()
{
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    display();
    pop();
    display();

}