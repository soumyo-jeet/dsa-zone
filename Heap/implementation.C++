// Heap -> A complete binary tree having two different representation tech 
//           -> 1. Max Heap (Parent nodes are >= child nodes)
//           -> 1. Min Heap (Parent nodes are <= child nodes)

// Approach to represent (array) ->
// Each ith node in the array has its right child at 2 * i + 2 index
// Each ith node in the array has its left child at 2 * i + 1 index

// Insertion Algo (max) -> O(nlogn)
// 1. Insert the new value at the last index of the array
// 2. Check if any of its anscestors is lesser than it
// 3. If detected such anscestor swap them 
// 4. Continue this untill it is balanced as per the structure of heap (max / min) 

// Deletion Algo (max) -> O(logn)
// logically the root has to be deleted but in reality the last node has to be cut down
// Replace the root's value with the last node's value and decrease the array id by 1
// Check the children thoroughly 
// if any child becomes greater than the parent swap them

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

int remove (int heap[], int s)
{
    // remove the last node physically 
    int tr = heap[s - 1];
    s = s - 1;

    // replace root's value
    heap[0] = tr;

    // struct the heap structure
    int i = 0;
    while(i < s)
    {
        int lc = 2 * i + 1;
        int rc = 2 * i + 2;
        int gc = i;
        if(lc < s && heap[lc] >= heap[gc]) gc = lc;
        if(rc < s && heap[rc] >= heap[gc]) gc = rc;

        if(heap[gc] <= heap[i]) break;

        int temp = heap[i];
        heap[i] = heap[gc];
        heap[gc] = temp;

        i = gc;
    }

    return s;
}

void display (int heap[], int s)
{
    cout << "Display of the heap: \n";
    for(int i = 0; i < s; i ++)
    {
        cout << heap[i] << " ";
    }
}

int main()
{
    int heap[50], s;
    cout << "Size of the heap: ";
    cin >> s;

    for(int i = 0; i < s; i++)
    {
        int x;
        cout << "Value: ";
        cin >> x;

        insert(heap, x, i);
    }
    display(heap, s);

    s = remove(heap, s);
    display(heap, s);

    s = remove(heap, s);
    display(heap, s);

}