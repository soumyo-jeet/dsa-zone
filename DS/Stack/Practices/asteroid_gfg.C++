#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int> &arr)
{
    stack<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (temp.empty())
        {
            temp.push(arr[i]);
        }

        else
        {
            if ((temp.top() >= 0 && arr[i] < 0))
            {
                int ae = arr[i] * -1;

                if (temp.top() == ae)
                {
                    temp.pop();
                }

                else
                {
                    while (!temp.empty() && temp.top() >= 0 && temp.top() <= ae)
                    {
                        if (temp.top() == ae)
                        {
                            temp.pop();
                        }

                        temp.pop();
                        if (temp.empty() || temp.top() < 0)
                        {
                            temp.push(arr[i]);
                            break;
                        }
                    }
                }
            }
            else
                temp.push(arr[i]);
        }
    }

    vector<int> ans(temp.size());
    int i = temp.size() - 1;
    while (!temp.empty())
    {
        ans[i--] = temp.top();
        temp.pop();
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

    vector<int> ans = asteroidCollision(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}