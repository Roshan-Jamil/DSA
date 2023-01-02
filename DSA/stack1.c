#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack [MAX];
int top = -1;
void push(int data)
{
    if(top == MAX-1)
    {
        printf("stack Overflow");
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
        printf("\nstack is Underflow\n");
    }
    else
    {
        top--;
    }
}

int main()
{
    push(3);
    pop();
    pop();
    // top();
    // display();
}