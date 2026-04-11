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

int firstNeg(queue<int> q)
{
    while (!q.empty())
    {
        if (q.front() < 0)
            return q.front();
        
        q.pop();
    }
    return 0;
}

int main()
{
    int n, arr[1000], i = 0;
    queue<int> q;
    cout << "enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // Initialize or use arr[i] here
    }

    int k;
    cout << "Enter k : ";
    cin >> k;

    for (i = 0; i < k; i++)
    {
        if(arr[i] < 0)
        {
            q.push(i);
        }
    }

    while (i < n)
    {
        if(q.empty()) cout << endl << 0;
        else cout << endl << arr[q.front()];


        if(!q.empty() && q.front() + k <= i) q.pop();
        if(arr[i] < 0) q.push(i);
        i++;
    }
    if(q.empty()) cout << endl << 0;
    else cout << endl << arr[q.front()];
}