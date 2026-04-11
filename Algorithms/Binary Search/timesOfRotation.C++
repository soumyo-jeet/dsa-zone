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

int findKRotationLeft(vector<int> &arr) {
    int s= 0, e = arr.size() - 1, indx = 0;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(arr[0] > arr[mid])
        {
            indx = mid;
            e = mid - 1;
        }

        else s = mid + 1;
    }
    return (arr.size() - indx) % arr.size();     
}

int findKRotationRight(vector<int> &arr) {
    int s= 0, e = arr.size() - 1, indx = 0;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(arr[0] > arr[mid])
        {
            indx = mid;
            e = mid - 1;
        }

        else s = mid + 1;
    }
    return indx;     
}

int main ()
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
        cout <<  arr1[i] << " ";
    }


    cout << endl << "The array has been left-roatated for " << findKRotationLeft(arr1) << " times.";
    cout << endl << "The array has been right-roatated for " << findKRotationRight(arr1) << " times.";
}