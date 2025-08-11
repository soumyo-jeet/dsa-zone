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

class QueuePrototype
{
    int *arr;
    int size;
    int fr;
    int tail;
    public:
    QueuePrototype(int n)
    {
        size = n;
        arr = new int[n];
        fr = 0;
        tail = 0;
    }

    int isEmpty()
    {
        if(tail == fr) return 1;
        return 0;
    }

    void back_push(int x)
    {
        if(tail == size)
        {
            cout << "Queue overflow";
            return;
        }
        arr[tail++] = x;
    }

    void push_front(int x)
    {
        if(tail == size)
        {
            cout << "Queue overflow";
            return;
        }

        if(fr != 0)
        {
            arr[--fr] = x;
            return;
        }

        for(int i = tail - 1; i >= 0; i--)
        {
            arr[i+1] = arr[i];
        }

        arr[fr] = x;
        tail ++;
    }

    void pop_front()
    {
        if(isEmpty() == 1)
        {
            cout << "Queue underflow";
            return;
        }

        fr++;
    }

    void pop_back()
    {
        if(isEmpty() == 1)
        {
            cout << "Queue underflow";
            return;
        }

        tail--;
    }

    int front()
    {
        if(isEmpty() == 1)
        {
            cout << "Empty Queue";
            return -500;
        }

        return arr[fr];
    }

    int back()
    {
        if(isEmpty() == 1)
        {
            cout << "Empty queue";
            return -500;
        }

        return arr[tail - 1];
    }

    void display ()
    {
        if(isEmpty() == 1)
        {
            cout << "Empty queue";
            return;
        }

        cout << "Elements in the queue" << endl;

        for(int i = fr; i < tail; i++)
        {
            cout << arr[i] << " ";
        }
    }
};



main()
{
    QueuePrototype q(4);
    q.back_push(4);
    q.push_front(5);
    q.back_push(3);
    q.push_front(7);
    q.pop_back();
    q.pop_front();
    cout << endl << "Front of the queue: " << q.front() << endl;
    cout << endl << "End of the queue: " << q.back() << endl;
    q.display(); 
}

