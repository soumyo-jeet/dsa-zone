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

void pushAtFront(stack<int> &deQ)
{
    int x;
    cout << "\nEnter x: ";
    cin >> x;
    deQ.push(x);
}

void popFromFront(stack<int> &deQ)
{
    deQ.pop();
}

void pushAtBack(stack<int> &deQ)
{
    int x;
    cout << "\nEnter x: ";
    cin >> x;
    stack<int> temp;

    // clear the stack
    while(!deQ.empty())
    {
        temp.push(deQ.top());
        deQ.pop();
    }

    // push the new element
    deQ.push(x);

    // restore the stack
    while(!temp.empty())
    {
        deQ.push(temp.top());
        temp.pop();
    }
}


void popFromBack(stack<int> &deQ)
{
    stack<int> temp;

    // clear the stack untill size becomes 1
    while(deQ.size() != 1)
    {
        temp.push(deQ.top());
        deQ.pop();
    }

    // push the new element
    deQ.pop();

    // restore the stack
    while(!temp.empty())
    {
        deQ.push(temp.top());
        temp.pop();
    }
}

void display(stack<int> deQ)
{
    stack<int> temp;

    // queue -> reverse stack
    while(!deQ.empty())
    {
        temp.push(deQ.top());
        deQ.pop();
    }

    while(!temp.empty())
    {
        cout << temp.top();
        temp.pop();
    }
}



int main()
{
    stack<int> deQ;
    int f;
    cout << "\n1. Push at the front \n2. Push at the end \n3. Pop from the top \n4. Pop from the back\n5. Display \n: ";
    cin >> f;

    while(f != 6)
    {
        if(f == 1) pushAtFront(deQ);
        else if(f == 2) pushAtBack(deQ);
        else if(f == 3) popFromFront(deQ);
        else if(f == 4) popFromBack(deQ);
        else if(f == 5) display(deQ);
        else break;
        cout << "\n1. Push at the front \n2. Push at the end \n3. Pop from the top \n4. Pop from the back\n5. Display \n: ";
        cin >> f;
    }

}