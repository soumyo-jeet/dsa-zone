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

class MyQueue
{
    stack<int> store, temp;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        store.push(x);
    }

    int pop()
    {
        int el = -1;
        if(temp.empty())
        {
            while (!store.empty())
            {
                temp.push(store.top());
                store.pop();
            }
        }

        el = temp.top();
        temp.pop();
        return el;
    }

    int top()
    {
        int el = -1;
        if(temp.empty())
        {
            while (!store.empty())
            {
                temp.push(store.top());
                store.pop();
            }
        }

        el = temp.top();
        return el;
    }

    bool empty()
    {
        if(temp.empty() && store.empty()) return true;
        else return false;
    }
};

int main()
{
    MyQueue q = MyQueue();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.pop() << endl;
    q.push(7);
    cout << q.top() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    q.push(8);
    cout << q.top() << endl;
}