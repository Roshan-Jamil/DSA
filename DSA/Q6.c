#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *data, n, i;
    int search, found;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("Enter the elements in the array : ");
    data = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
    printf("Enter element to search : ");
    scanf("%d", &search);
    found = 0;
    for (i = 0; i < n; i++)
    {
        if (data[i] == search)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        printf(" %d is found at position %d ", search, i + 1);
    }
    else
    {
        printf("%d is not found in the array : ",search);
    }
    return 0;
}