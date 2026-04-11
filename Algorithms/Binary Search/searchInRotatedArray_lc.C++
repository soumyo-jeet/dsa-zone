#include <iostream>
using namespace std;

int main()
{
    int n, arr[1000], target;
    cout << "Size of the array: ";
    cin >> n;
    cout << "Elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Target to find: ";
    cin >> target;

    int s = 0, e = n - 1, ans;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] == target)
        {
            cout << "Present at " << mid << endl;
            return 0;
        }

        if (arr[mid] < arr[0])
        {
            if (target >= arr[mid] && target <= arr[e])
            {
                s = mid + 1;
            }

            else
                e = mid - 1;
        }

        else
        {
            if (target >= arr[0] && target <= arr[mid])
            {
                e = mid - 1;
            }

            else
                s = mid + 1;
        }
    }

    cout << "Not Present" ;

    return 0;
}