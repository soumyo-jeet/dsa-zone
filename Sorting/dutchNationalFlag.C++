// Array structure --
//      [0 -> low - 1] : all 0s
//      [low -> mid - 1] : all 1s
//      [mid -> high] : unsorted
//      [high + 1 -> n - 1] : all 2s

// Intiution --
//      putting low, mid at 0 and high at n - 1
//      arr[mid] == 0 :
//                      swap(arr[low], arr[mid])
//                      low ++ , mid ++
//      arr[mid] == 1 :
//                      mid ++
//      arr[mid] == 2 :
//                      swap(arr[high], arr[mid])
//                      high --
//      mid > high => unsorted portion has ran out!


#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortColors (vector<int> &arr)
{
    int n = arr.size(), low = 0, mid = 0, high = n - 1;
    while(mid <= high)
    {
        if(arr[mid] == 0) 
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }

        else if(arr[mid] == 1)
        {
            mid ++;
        }

        else
        {
            swap(arr[mid], arr[high]);
            high --;
        }
    }
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

    sortColors(arr1);
    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }

    
}