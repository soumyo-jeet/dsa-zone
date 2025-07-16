#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> maxOfMinsOn2(vector<int> &arr)
{
    // Your code here
    vector<int> ans(arr.size(), 0);
    stack<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!temp.empty() && arr[temp.top()] > arr[i])
        {
            int t = temp.top();
            temp.pop();

            int span;
            if (temp.empty())
                span = i;
            else
                span = i - temp.top() - 1;

            for (int i = 0; i < span; i++)
            {
                ans[i] = max(ans[i], arr[t]);
            }
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

        for (int i = 0; i < span; i++)
        {
            ans[i] = max(ans[i], arr[t]);
        }
    }

    return ans;
}

vector<int> maxOfMinsOn(vector<int> &arr)
{
    // Your code here
    vector<int> ans(arr.size(), 0);
    stack<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!temp.empty() && arr[temp.top()] > arr[i])
        {
            int t = temp.top();
            temp.pop();

            int span;
            if (temp.empty())
                span = i;
            else
                span = i - temp.top() - 1;

            ans[span - 1] = max(ans[span - 1], arr[t]);
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

        ans[span - 1] = max(ans[span - 1], arr[t]);
    }

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}