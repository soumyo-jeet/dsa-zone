#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    vector<int> area(heights.size(), -1);
    stack<int> temp;

    // finding nsr and nsl
    for (int i = 0; i < heights.size(); i++)
    {
        while (!temp.empty() && heights[temp.top()] > heights[i])
        {
            int th = temp.top();
            int h = heights[temp.top()];
            temp.pop();
            // nsl finding
            int w;
            if (temp.empty())
                w = i;
            else if (temp.top() >= h)
                w = i - th - 1;
            else
                w = i - temp.top() - 1;

            area[th] = h * w;
        }
        temp.push(i);
    }

    while (!temp.empty())
    {
        int th = temp.top();
        int h = heights[temp.top()];
        temp.pop();
        // nsl finding
        int w;
        if (temp.empty())
            w = heights.size() - th;
        else if (temp.top() >= h)
           w = heights.size() - th -1;
        else
            w = heights.size() - temp.top() -1;

        area[th] = h * w;
    }

    int max = area[0];
    for(int i = 0; i < area.size(); i++)
    {
        cout << area[i] << " ";
        if(area[i] > max) max = area[i];
    }
    return max;
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

    cout << endl << largestRectangleArea(arr);
    return 0;
}