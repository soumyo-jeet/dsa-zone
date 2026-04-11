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

void queueInRevWithRec (queue <int> q) 
{
    if(q.empty()) return;

    int x = q.front();
    q.pop();
    queueInRevWithRec(q);
    cout << x << " ";
    return;
}

void queueInRevWithStack (queue <int> q) 
{
    stack <int> temp;

    while(!q.empty())
    {
        temp.push(q.front());
        q.pop();
    }

    while(!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
}



void queueInAct (queue <int> q)
{
     while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl;
    cout << q.size() << endl;
   
    cout << q.empty() << endl;

    //queue in actual order
    cout << endl << "In actual order: " << endl;
    queueInAct(q);

    //queue in rev order
    cout << endl << "In reverse order: " << endl;
    queueInRevWithRec(q);
    cout << endl;
    queueInRevWithStack(q);
}