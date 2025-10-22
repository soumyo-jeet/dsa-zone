// Algo ->
// 1. Create max heap from the given array
// 2. The first elment of heap is the greatest one
// 3. Replace the first elment with the last one and decrease size by 1
// 4. Heapify the remaining part of the heap
// 5. Continue 2, 3, 4 untill heap size becomes 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

void swap (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insert (int heap[], int x, int id)
{
    heap[id] = x;
    while(id > 0)
    {
        // find the parent
        int par = (id - 1) / 2;
        // if parent already greater => structure is already sorted
        if(heap[par] >= heap[id]) break;

        // else continue swapping
        int temp = heap[id];
        heap[id] = heap[par];
        heap[par] = temp;

        id = par;
    } 
}

void createMaxHeap (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        insert(arr, arr[i], i);
    }

    cout << "Max heap created: \n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }  
}

void heapify(int arr[], int size, int i)
{
    if (i >= size) return;

    int gc = i;
    int lc = i * 2 + 1;
    int rc = i * 2 + 2;

    if(lc < size && arr[lc] > arr[gc]) gc = lc;
    if(rc < size && arr[rc] > arr[gc]) gc = rc;

    if(gc != i) swap(arr[gc], arr[i]);
    else return;

    heapify(arr, size, gc);
}


void heapSort (int arr[], int size)
{
    createMaxHeap(arr, size);

    while(size > 1)
    {
        heapify(arr, size, 0);
        swap(arr[0], arr[size - 1]);
        size--;
    }
}

int main()
{
    int n, arr[50];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        // Initialize or use arr[i] here
    }

    heapSort(arr, n);
    cout << "\nSorted array: " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
        // Initialize or use arr[i] here
    }
}