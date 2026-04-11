#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int celebrity(vector<vector<int>> &arr)
{
    stack<int> celebs;
    for(int i = 0; i < arr.size(); i++)
    {
        celebs.push(i);
    }

    while(celebs.size() > 1)
    {
        int p1 = celebs.top();
        celebs.pop();
        int p2 = celebs.top();      
        if(arr[p1][p2] == 1 && arr[p2][p1] == 0) continue;
        else if(arr[p1][p2] == 0 && arr[p2][p1] == 1)
        {
            celebs.pop();
            celebs.push(p1);
        }
        else
        {
            celebs.pop();
        }
    }

    if(celebs.empty()) return -1;

    for(int i = 0; i < arr.size(); i++)
    {
        if(i != celebs.top())
        {
            if (arr[celebs.top()][i] == 1) return -1;
            if(arr[i][celebs.top()] == 0) return -1;
        }
    }

    return celebs.top();
}


int main()
{
    vector<vector<int>> arr;
    int n;
    cout << "Size of array: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        arr.push_back(temp);
    }
    cout<< "celebrity: " << celebrity(arr);

    return 0;
}