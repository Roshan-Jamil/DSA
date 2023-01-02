//1. WAP to find out the smallest and largest element stored in an array of n integers.

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,n, *ptr;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n;i++)
    {
        printf("Enter the value of %d element of array : ",i+1);
        scanf("%d",&ptr[i]);
    }
    
    for(int i=0; i<n;i++)
    {
        printf("The value of %d in array is %d\n",i+1,ptr[i]);
    }
    // for(int i=0; i<n;i++)
    // {
    //     if (*ptr[i]>*ptr[i+1])
    //     {
    //         printf("Largest in the array is : %d \n:",ptr);
    //     }
    //     if (*ptr[i]<*ptr[i+1])
    //     {
    //         printf("smallest in the array is : %d\n",ptr);
    //     }
    // }
    
    return 0;
}