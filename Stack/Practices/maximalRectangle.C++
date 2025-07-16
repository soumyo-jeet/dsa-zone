#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> temp;
    int max = 0;

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
            else
                w = i - temp.top() - 1;

            max = max < h * w ? h * w : max;
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
        else
            w = heights.size() - temp.top() - 1;

        max = max < h * w ? h * w : max;
    }
    return max;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int max;
    vector<int> step(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == '0') step[j] = 0;
            else step[j] ++;
        }
        int largest = largestRectangleArea(step) ;
        max = max < largest ? largest : max; 
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

    cout << endl
         << largestRectangleArea(arr);
    return 0;
}