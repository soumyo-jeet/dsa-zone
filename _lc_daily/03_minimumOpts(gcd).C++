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

// if N 1s are there in the array then opts required = n - N
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int minimumOpts(int arr[], int n)
{
    // find number of 1 present
    int ones = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 1) ones++;
    }

    if(ones != 0) return (n - ones);

    // try to make one 1 and determine the minimum opts count
    int opts = INT_MAX;

    for(int j = 0; j < n ; j++)
    {
        int g = arr[j];
        for(int i = j + 1; i < n - 1; i++)
        {
            int a = arr[i] > g ? arr[i]: g;
            int b = a == arr[i] ? g : arr[i];
            g = gcd(a,b);
            if(g == 1) 
            {
                opts = min(opts, (i + 1) - j);
                break;
            }
        }
    }

    // total opts = opts to make one 1 + opts to make others one 
    if(opts == INT_MAX) return -1;
    return (opts + (n - 1));
}

int main()
{
    int n, arr[50];
    cout << "Size: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << minimumOpts(arr, n);
}