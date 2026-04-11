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
        q.push(arr[i]);
    }

    while (i < n)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << q.front() << " ";
            q.push(q.front());
            q.pop();
        }


        q.pop();
        q.push(arr[i++]);
        cout << endl;
    }

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}