#include <iostream>
using namespace std;

int main()
{
    int n, arr[1000];
    cout << "Size of the array: ";
    cin >> n;
    cout << "Elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = -1;

    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
        {
            ans = mid;
            break;
        }
        else if (arr[mid] >= arr[mid + 1])
        {
            e = mid - 1;
        }
        else if (arr[mid] >= arr[mid - 1])
        {
            s = mid + 1;
        }
    }

    cout << ans;
    return 0;
}