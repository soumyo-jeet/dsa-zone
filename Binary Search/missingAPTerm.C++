// right of the missing term -> all terms are greater than the acc term
// left of the missing term -> all terms are equal to the acc term

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

void reverseArr(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
}

int missingApTerm(vector<int> arr)
{
    int n = arr.size(), ans = n;
    if (arr[0] > arr[1])
    {
        reverseArr(arr);
        ans = -1;
    }

    int s = 0, e = n - 1, d = min(arr[1] - arr[0], arr[n - 1] - arr[n - 2]), a = arr[0];
    cout << endl
         << d << endl
         << a << endl;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int accTerm = a + d * mid;
        cout << accTerm << endl;

        if (arr[mid] != accTerm)
        {
            ans = mid;
            e = mid - 1;
        }

        else
            s = mid + 1;
    }
    return a + d * ans;
}

int main()
{
    int n1;
    vector<int> arr1;
    cout << "Size of the array: ";
    cin >> n1;
    cout << "Elements of the array: ";
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        arr1.push_back(x);
    }

    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << endl
         << "The single term is missing in the array is " << missingApTerm(arr1);
}