#include <stdio.h>
#include <stdlib.h>
#define max 5

int first = -1;
int stack[max] ;

void display()
{
    if(first == -1)
    {
        printf("\nStack is empty !\n");
    }
    else
    {
        for(int i = 0 ; i<=first ; i++)
        {
            printf("%d\n",stack[i]);
        }
    }
}
void push(int data)
{
    int i;
    first += 1;
    // printf("Enter the data to the stack : ");
    // scanf("%d",&data);
    if(first == -1)
    {
        printf("stack is empety ");
    }
    else
    {

        for (i = first ; i>0; i--)
        {
            stack[i] = stack [i-1];
        }
        stack [0] = data;
    }
}

int main()
{
    push (3);
    push (4);
    push (6);
    push (5);
    display();

    // int x , choice;
    // printf("Enter the data in stack : ");

    // do
    // {
    //     printf("Enter the choice [1. push , 2. pop , 3. display , 4.exit] : ");
    //     scanf("%d",&choice);
    //     switch(choice)
    //     {
    //         case 1 :
    //         {
    //         push(x);
    //         break;
    //         }
            
    //         case 2 :
    //         {
    //             //pop();
    //             break;
    //         }
    //         case 3:
    //         {
    //             display();
    //             break;
    //         }
    //         case 4:
    //         {
    //             exit(1);
    //             break;
    //         }
    //         default :
    //         {
    //             printf("Please enter the valid choice : ");
    //             break;
    //         }
    //     }
    // }
    // while(choice != 4);

}