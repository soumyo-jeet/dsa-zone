#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> beautifulArr (vector<int> arr)
{
    stack<int> modifiedArr;
    for(int i = 0; i < arr.size(); i++)
    {
        if(modifiedArr.empty()) 
        {
            modifiedArr.push(arr[i]);
        }

        else
        {
            if((modifiedArr.top() > 0 && arr[i] < 0) || (modifiedArr.top() < 0 && arr[i] > 0))
            {
                modifiedArr.pop();
            }
            else
            {
                modifiedArr.push(arr[i]);
            }
        }
    }

    vector<int> ans(modifiedArr.size());
    int i = modifiedArr.size() - 1;
    while (!modifiedArr.empty())
    {
        ans[i--] = modifiedArr.top();
        modifiedArr.pop();
    }
    return ans;

}

int main()
{
    vector<int> arr; 
    int n;
    cout << "Size of array: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    vector<int> ans = beautifulArr(arr);
    for(int i = 0; i < ans.size(); i++) 
    {
        cout << ans[i] << " ";
    }

return 0;
}