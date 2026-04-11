#include<stdio.h>
#include<stdlib.h>

void merge (int * arr, int s, int m, int e)
{
    int tempArr[e + 1];
    int l = s, r = m + 1, i = 0;
    while(l <= m && r <= e)
    {
        if(arr[l] < arr[r])
        {
            tempArr[i++] = arr[l];
            l++;
        }

        else if(arr[l] > arr[r])
        {
            tempArr[i++] = arr[r];
            r++;
        }

        else
        {
            tempArr[i++] = arr[l];
            l++; r++;
        }
    }

    while(l <= m)
    { 
        tempArr[i++] = arr[l];
        l++;
    }

    while(r <= e)
    {
        tempArr[i++] = arr[r];
        r++;
    }

    int a = 0;
    for(int j = s; j <= e; j++)
    {
       arr[j] = tempArr[a++]; 
    }
}


void mergeSort(int *arr, int s, int e)
{
    if(s > e) return;
    int mid = s + (e - s) / 2;
    
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, mid, e);
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
    mergeSort(arr, 0, s - 1);
    free(arr);
}