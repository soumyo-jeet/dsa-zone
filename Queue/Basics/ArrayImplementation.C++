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

    void push(int x)
    {
        if(tail == size)
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        arr[tail % size] = x;
        tail++;
    }

    void pop() 
    {
        if(fr + 1 > tail)
        {
            cout << "Not possible" << endl;
            return;
        }

        fr++;
        size++;
    }

    int isEmpty()
    {
        if(fr == tail)
        {
            return 1;
        }
        return 0;
    }

    int front()
    {
        if(isEmpty())
        {
            return -1;
        }

        return arr[fr % size];
    }

    void show()
    {
        if(tail == fr) 
        {
            return ;
        }

        for(int i = fr; i < tail; i ++)
        {
            cout << arr[i % size] << " ";
        }

        cout << endl;
    }
};

main()
{
    QueuePrototype q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.show(); 
    q.pop();
    q.push(5);
    q.pop();
    q.push(6);
    q.show();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout << q.front() << endl;
    cout << q.isEmpty() << endl;
    q.push(7);
    q.push(8);
    cout << q.front() << endl;
    q.show(); 
}



// Drawbacks --
// Increment in size (int) may cause the int overflow
//  ---> can be override if we consider size as double while n is int
// (same for fr and tail)

