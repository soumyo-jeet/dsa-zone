#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

double median(vector<int> arr1, vector<int> arr2)
{
    int s = 0, e = arr1.size(), t = (arr1.size() + arr2.size()) / 2, medIndx1, medIndx2;

    while(s <= e)
    {
        int mid1 = s + (e - s) / 2, mid2 = t - mid1;
        int l1 = INT_MIN, r1= INT_MAX, r2 = INT_MAX, l2 = INT_MIN;
        if(mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = arr2[mid2 - 1];
        if(mid1 < arr1.size()) r1 = arr1[mid1];
        if(mid2 < arr2.size()) r2 = arr2[mid2];

        if(l1 > r2) e = mid1 - 1;
        else if(l2 > r1) s = s + 1;
        else
        {
            medIndx1 = mid1;
            medIndx2 = mid2;
            break;
        }
    }

    if((arr1.size() + arr2.size()) % 2 != 0)
    {
        return min(arr1[medIndx1], arr2[medIndx2]);
    }

    else
    return ((max(arr1[medIndx1 - 1], arr2[medIndx2 - 1]) + min(arr1[medIndx1], arr2[medIndx2])) / 2.0);
}


int main() 
{
    int n1, n2;
    vector<int> arr1, arr2;
    cout << "Size of the array1: ";
    cin >> n1;
    cout << "Elements of the array1: ";
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        arr1.push_back(x);
    }

    cout << "Size of the array2: ";
    cin >> n2;
    cout << "Elements of the array2: ";
    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        arr2.push_back(x);
    }

    cout<<"Med: " << median(arr1, arr2);
}