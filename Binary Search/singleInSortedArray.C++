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


// The left of the single element ->  even indx - 1 occ  odd indx - 2 occ
// The right of the single element -> odd indx - 1 occ  even indx - 2 occ

int singleInSortedArr(vector<int> &arr) {
    int s= 1, e = arr.size() - 2, ans = arr[0];
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(mid % 2 == 0)
        {
            if(arr[mid + 1] == arr[mid]) s = mid + 1;
            else if(arr[mid - 1] == arr[mid]) e = mid - 1;
            else
            {
                ans = arr[mid];
                break;
            }
        }
        else
        {
            if(arr[mid + 1] == arr[mid]) e = mid - 1; 
            else if(arr[mid - 1] == arr[mid]) s = mid + 1;
        }
    }
    return ans;     
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


    cout << endl << "The single element in the array is " << singleInSortedArr(arr1);
}