#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , a , b ;
    printf("Enter the number of elements in array : ");
    scanf("%d", &n);
    int *arr;
    arr = (int*) calloc (n,sizeof(int));
    printf("Enter the elements in the array :\n");
    for(int i =0 ;i<n;i++)
    scanf("%d",&arr[i]);
    printf("Enter the first limit : ");
    scanf("%d",&a);
    printf("Enter the second limit : ");
    scanf("%d",&b);    
    int start ,end;
    for (int i=0 ; i<n ; i++)
    {
        if (arr[i]==a)
        {
            start = i;
            break;
        }
    }
    for (int i=0 ; i<n ; i++)
    {
        if (arr[i]==b)
        {
            end = i;
            break;
        }
    }
    for (int i=start; i<=end;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}