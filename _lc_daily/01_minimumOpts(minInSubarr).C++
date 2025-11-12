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


// Brute Force
int minOpts (int arr[], int n)
{
    // Select the unique elements of the array
    set<int> digiSet;
    for(int i = 0; i < n; i++)
    {
        digiSet.insert(arr[i]);
    }

    // For each unique elements find the number of operations are required to make it completly 0 
    int opts = 0;
    for(int val: digiSet)
    {
        if (val == 0) continue;

        // Assuming each element can be made to 0 without any break => required operations = 1 
        int hasBreak = 0, visited = 0;
        opts++;

        // Check if break arises
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == val) 
            {
                if(hasBreak == 1) opts += 1;
                hasBreak = 0;
                visited = 1;
            }

            // If there exists any element lesser than the val, break is needed
            if(arr[i] < val && visited == 1)
            {
                hasBreak = 1;
            }
        }
    }

    return opts;
}


// Optimal -> Monotonic increasing stack
int minOpts_ (int arr[], int n)
{
    // Create a monotonic increasing stack with unique elements => 
    // as any element can be minimum / can be converted to 0 as long as no element becomes lesser than that
    stack<int> temp;
    int opts = 0;
    for(int i = 0; i < n; i++)
    {
        while(!temp.empty() && arr[i] < temp.top()) temp.pop();
        // if the element is not present in the stack => extra oparation
        //      1. the previous flow has been broken
        //      2. the element is seen for the first time
        if((temp.empty() || arr[i] > temp.top()) && arr[i] != 0)
        {
            temp.push(arr[i]);
            opts++;
        }

        // if it's present => it can be nullify in continuation with the prev subarray
        else continue;
    }

    return opts;
}

int main()
{
    int n, arr[50];
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements: \n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];    
    }

    int ans = minOpts(arr, n);
    cout << ans;
}