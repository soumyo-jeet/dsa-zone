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
    int ans = arr[0];

    int s = 0, e = n - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] < arr[0]) {
            ans = arr[mid];
            e = mid - 1;
        }
        else s = mid + 1;
    }

    cout << ans;
}