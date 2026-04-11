#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> minOfMax(vector<int> arr)
{
    vector<int> ans(arr.size(), 1000);
    stack<int> temp;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!temp.empty() && arr[temp.top()] < arr[i])
        {
            int t = temp.top();
            temp.pop();

            int span;
            if (temp.empty())
                span = i;
            else
                span = i - temp.top() - 1;

            ans[span - 1] = min(ans[span - 1], arr[t]);
        }

        temp.push(i);
    }

    while (!temp.empty())
    {
        int t = temp.top();
        temp.pop();

        int span;
        if (temp.empty())
            span = arr.size();
        else
            span = arr.size() - temp.top() - 1;

        ans[span - 1] = min(ans[span - 1], arr[t]);
    }

    for (int i = ans.size() - 2; i >= 0; i--)
    {
        ans[i] = min(ans[i + 1], ans[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr, ans;
    int n;
    cout << "Size of array: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    ans = minOfMax(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}