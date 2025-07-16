#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int maxWater (vector<int> arr)
{
    stack<int> temp; int max = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        while(!temp.empty() && temp.top() < arr[i])
        {
            int h = temp.top();
            temp.pop();

            int w;
            if(temp.empty() || temp.top() == h) w = i - h -1;
            else w = i - temp.top() - 1;

            max = max < h * w ? h * w : max;
        }

        temp.push(arr[i]);
    }

    return max;
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

    cout << maxWater(arr);
}