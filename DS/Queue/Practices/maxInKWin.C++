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
#include <deque>
using namespace std;

vector<int> maxInKWin(vector<int> arr, int k)
{
    deque<int> ledger;
    vector<int> ans;
    int i = 0, n = arr.size();

    // queue the elements in k size of the array so that the max ele be the front
    for (i = 0; i < k; i++)
    {
        // push the current ele and eleminate the pre lesser
        while (!ledger.empty() && arr[ledger.back()] < arr[i])
        {
            ledger.pop_back();
        }
        ledger.push_back(i);
    }

    while (i < n)
    {
        // the front ele of the ledger => max of the window
        if (!ledger.empty())
        {
            ans.push_back(arr[ledger.front()]);
        }

        // push the current ele and eleminate the prev lesser from back to front
        while (!ledger.empty() && arr[ledger.back()] < arr[i])
        {
            ledger.pop_back();
        }
        ledger.push_back(i);

        if (!ledger.empty() && ledger.front() + k <= i) ledger.pop_front();
        i ++;
    }

    if (!ledger.empty())
    {
        ans.push_back(arr[ledger.front()]);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
        // Initialize or use arr[i] here
    }

    return ans;
}

int main()
{
    int n, k;
    vector<int> arr;
    cout << "Size of the array: ";
    cin >> n;

    cout << "Size of the window: ";
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        // Initialize or use arr[i] here
    }

    maxInKWin(arr, k);
}