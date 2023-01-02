#include <stdio.h>
#include <stdlib.h>

void nonzero(int **arr, int n)
{
    int non = 0, j, i;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                non++;
            }
        }
    }
    printf("Total number of Non zero elements in the array is %d \n", non);
}
void sumabove(int **arr, int n)
{
    int sum = 0, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            sum = sum + arr[i][j];
        }
    }
    printf("The sum of elements above the leading diagonal of the matrix is %d \n", sum);
}
void sumbelow(int **arr, int n)
{
    int sum = 0, i, j;
    int f = n - 2;
    for (i = 1; i < n; i++)
    {
        for (j = n - 1; j > f; j--)
        {
            sum = sum + arr[i][j];
        }
        f--;
    }
    printf("The sum of elements below the minor diagonal of the matrix is %d \n", sum);
}
void product(int **arr, int n)
{
    int k = 1, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i; j == i; j++)
        {
            k = k * arr[i][j];
        }
    }
    printf("The product of element of diagonal of the matrix is %d\n", k);
}
int main()
{
    int n, i, j;
    int **arr;
    printf("Enter the value of n for the array of size [nxn]\n");
    scanf("%d", &n);
    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    int g = 1;
    for (i = 0; i < n; i++)
    {
        printf("Enter %d element in Row %d\n", n, (g++));
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n The matrix you gave as input is\n");
    for (i = 0; i < n; i++)
    {
        for (i = 0; j < n; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    nonzero(arr, n);
    sumabove(arr, n);
    sumbelow(arr, n);
    product(arr, n);

    return 0;
}