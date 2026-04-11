#include<stdio.h>
#include<stdlib.h>


void insertionSort(int *arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        for(int j = i ; j > 0; j--)
        {
            if(arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else break;
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main ()
{
    int s;
    printf("Enter size of the array: ");
    scanf("%d", &s);
    int *arr = (int *) malloc(sizeof(int) * s);

    printf("Enter elements of the array: \n");
    for(int i = 0; i < s; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array before sort: \n");
    for(int i = 0; i < s; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("Array after sort: \n");
    insertionSort(arr, s);
    free(arr);
}