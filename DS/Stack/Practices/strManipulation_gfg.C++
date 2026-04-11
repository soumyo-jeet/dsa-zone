#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int removeConsecutiveSame(vector<string> &arr)
{
    stack<string> str;
    for (int i = 0; i < arr.size(); i++)
    {
        if (str.empty())
        {
            str.push(arr[i]);
        }

        else
        {
            if (str.top() == arr[i])
            {
                str.pop();
            }
            else
            {
                str.push(arr[i]);
            }
        }
    }

    return str.size();
}

int main()
{
    vector<string> arr;
    int n;
    cout << "Sequence length: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "ans: " << removeConsecutiveSame(arr);
}