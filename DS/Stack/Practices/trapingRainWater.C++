#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;



int maxWater (vector<int> arr)
{
    // find max height in right and left => if both exist then only water can be stored above that house
    // amount of water => (min(mR, mL) - curr H) * 1 
    stack<int> temp; int sum = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        while(!temp.empty() && arr[temp.top()] < arr[i])
        {
            int h = temp.top();
            temp.pop();

            int w;
            if(temp.empty()) w = 0;
            else
            {
                int minH = min(arr[temp.top()], arr[i]);
                int wid = i - temp.top() - 1;
                w = (minH - arr[h]) * wid;
            }
            sum += w;
        }

        temp.push(i);
    }

    return sum;
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