#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr)
{
    stack<int> temp;
    vector<int> ans(arr.size(), -1), tempAns(2 * arr.size(), -1);
    
    for (int i = 0; i < 2 * arr.size(); i++)
    {
        
        while (!temp.empty() && arr[temp.top()] < arr[i % arr.size()])
        {
            tempAns[temp.top()] = arr[i % arr.size()];
            temp.pop();
        }
        temp.push(i % arr.size());
    }

    for(int i = 0; i < arr.size(); i++) 
    {
        ans[i] = tempAns[i];
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

    vector<int> ans = nextLargerElement(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}