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

class PriorityQueue {
    public:
    int s;
    int arr[50];
    int end;


    PriorityQueue (int size)
    {
        s = size;
        end = -1;
    }

    void swap (int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapify1() 
    {
        int i = (end - 1) / 2;
        while(i >= 0)
        {
            int lc = 2 * i + 1;
            int rc = 2 * i + 2;
            int gc = i;

            if(lc <= end && arr[lc] > arr[gc]) gc = lc;
            if(rc <= end && arr[rc] > arr[gc]) gc = rc;

            if (gc == i) return;
            swap(arr[gc], arr[i]);

            i = (i - 1) / 2;
        }
    }

    void heapify2()
    {
        int i = 0;
        while(i <= end)
        {
            int lc = 2 * i + 1;
            int rc = 2 * i + 2;
            int gc = i;

            if(lc <= end && arr[lc] > arr[gc]) gc = lc;
            if(rc <= end && arr[rc] > arr[gc]) gc = rc;

            if (gc == i) break;
            swap(arr[gc], arr[i]);
            i = gc;
        }
    }


    int isEmpty() 
    {
        return end == -1;
    }

    void push(int x) 
    {
        if(end + 1 == s) 
        {
            cout << "Queue is overflown!\n";
            return;
        }

        end ++;
        arr[end] = x;
        heapify1();
        return;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        arr[0] = arr[end];
        end --;
        if(!isEmpty()) heapify2();
        return;
    }

    int top () 
    {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[0];
    }

    void display ()
    {
        cout << "\nDisplay of the queue:\n";
        for(int i = 0; i <= end; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    PriorityQueue pq = PriorityQueue(9);

    pq.push(8);
    pq.push(7);
    pq.push(11);
    pq.push(5);
    pq.push(10);
    pq.display();
    pq.pop();
    pq.display();
    pq.pop();
    pq.display();
    pq.pop();
    pq.display();
    pq.pop();
    pq.display();
}