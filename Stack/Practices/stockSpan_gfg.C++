#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateSpan(vector<int> &arr)
{
    // write code here
    vector<int>span(arr.size(), 1); stack<int> temp;
    for(int i = 0; i < arr.size(); i++)
    {
        while (!temp.empty() && arr[temp.top()] <= arr[i])
        {
            span[i] += span[temp.top()];
            temp.pop();
        }
        temp.push(i);
    }
    return span;
}


int main ()
{
        vector<int> arr;
    int n;
    cout << "Sequence length: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    vector<int> ans = calculateSpan(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
