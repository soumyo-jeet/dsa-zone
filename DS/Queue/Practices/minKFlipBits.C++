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

int minFlips (vector<int> arr, int k)
{
    queue<int> flipEnd;
    int flips=0;
    for(int i = 0; i < arr.size(); i++)
    {
        // if queued flipEnd exceeds the win span remove it
        if (!flipEnd.empty() && flipEnd.front() < i)
        {
            flipEnd.pop();
        }
        
        // 2x flips => no change     else => change
        int curr = flipEnd.size() % 2 == 0 ? arr[i] : !arr[i];
        cout << "curr: " << curr << endl;

        // queue the next flipend when 0 encounters => curr index + k
        if (curr == 0)
        {
            if (i + k - 1 >= arr.size())
            {
                return -1;
            }
            flipEnd.push(i + k - 1);
            flips ++;
            cout << "flips: " << flips << endl;
        }

    }

    return flips;
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

    cout << minFlips(arr, k);
}