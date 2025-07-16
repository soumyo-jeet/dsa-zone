#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> leftSmaller(vector<int> arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        if (!st.empty() && st.top() < arr[i])
        {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }
    return ans;
}

int main()
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

    vector<int> ans = leftSmaller(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}