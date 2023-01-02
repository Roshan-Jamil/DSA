#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void printArray(int A[],int n){
    for(int i=0;i<n;i++){
        printf(" %d ",A[i]);
    }
    printf("\n");
}
void bubblesort(int A[],int n){
    int temp;
    int g=0;
    for(int i=0;i<n-1;i++){
        g=1;               
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                g=0;
            }
        }
        if(g==1){
            return;
        }
    }
}
void insertionsort(int A[],int n){
    int key,j;
    for(int i=1;i<=n-1;i++){
         key=A[i];
         j=i-1;
         while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
         }
         A[j+1]=key;

    }

}
void selectionsort(int A[],int n){
    for(int j=0;j<n-1;j++){
        int min=n-1;
        for(int i=j;i<n;i++){
        if(A[i]<A[min]){
            min=i;
        }
    }
    if(min!=j){
            int temp=A[j];
            A[j]=A[min];
            A[min]=temp;}
}
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i
        = (low
           - 1); 
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void heapify(int arr[], int N, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--){
        heapify(arr, N, i);}
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
   
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
 
int main(){
    double time_spent = 0.0;
 
    clock_t begin = clock();
       srand(time(NULL));
    int n=rand()%100000+1000;
    printf("%d\n",n);
    int a[n];
    for (int i=0;i<n;i++){
        a[i]=rand()%n+0;
    }
    printArray(a,n);
    printf("For sorted array: ");
    //bubblesort(a,n);
    //insertionsort(a,n);
    //selectionsort(a,n);
    //quickSort(a,0,n-1);
    //mergeSort(a,n);
    heapSort(a,n);
    printArray(a,n);
    printf("\nNo of data:-%d\n",n);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The execution time is %f seconds", time_spent);
}