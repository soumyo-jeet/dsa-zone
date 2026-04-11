#include <iostream>
#include <vector>
using namespace std;

void swapGreater(vector<int> &arr1, vector<int> &arr2, int id1, int id2)
{
    if (arr1[id1] > arr2[id2])
    {
        int temp = arr1[id1];
        arr1[id1] = arr2[id2];
        arr2[id2] = temp;
    }
    else
        return;
}

void merge(vector<int> &arr1, vector<int> &arr2)
{
    int len = arr1.size() + arr2.size(), gap = (len / 2) + (len % 2);
    while (gap > 0)
    {
        int l = 0, r = l + gap;
        while (r < len)
        {
            // arr1 and arr2
            if (l < arr1.size() && r >= arr1.size())
            {
                swapGreater(arr1, arr2, l, r-arr1.size());
                
            }

            // arr1 and arr1
            else if (l < arr1.size() && r <= arr1.size())
            {
                swapGreater(arr1, arr1, l, r);
            }

            // arr2 and arr2
            else if (l >= arr1.size())
            {
                swapGreater(arr2, arr2, l-arr1.size(), r-arr1.size());
            }

            
            r++; l++;
        }
        if (gap == 1)
            break;

        gap = (gap / 2) + (gap % 2);
    }
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

    cout << "B" << endl;

    for(int i = 0; i < arr1.size() + arr2.size(); i++)
    {
        if(i >= arr1.size()) cout << arr2[i - arr1.size()] << " ";
        else cout << arr1[i] << " ";
    }

    merge(arr1, arr2);

    cout << endl << "a" << endl;

    for(int i = 0; i < arr1.size() + arr2.size(); i++)
    {
        if(i >= arr1.size()) cout << arr2[i - arr1.size()] << " ";
        else cout << arr1[i] << " ";
    }


    return 0;
}