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

queue<int> reverseFirstK(queue<int> q, int k)
{
    // code here
    queue <int> ans;
    stack<int> temp;
    int size = q.size();

    while(!q.empty() && temp.size() < k)
    {
        temp.push(q.front());
        q.pop();
    }

    while(!temp.empty())
    {
        ans.push(temp.top());
        temp.pop();
    }

    while(!q.empty())
    {
        ans.push(q.front());
        q.pop();
    }

    return ans;
}

int main()
{
    queue<int> q;
    q.push(8);
    q.push(7);
    q.push(6);
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    q = reverseFirstK(q,8);

    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}