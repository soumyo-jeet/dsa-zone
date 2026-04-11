#include <iostream>
using namespace std;

int maxEl(int n, int arr[])
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        max = max < arr[i] ? arr[i] : max;
    }
    return max;
}

int totalEl(int n, int arr[])
{
    int sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int minSum(int n, int arr[], int s, int e, int k)
{
    int ans;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        int sum = 0, count = 1;
        for (int i = 0; i < n; i++)
        {
            if (sum + arr[i] > mid)
            {
                count++;
                sum = 0;
            }
            sum += arr[i];
        }

        if (count > k)
            s = mid + 1;
        else
        {
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n, arr[1000], k;
    cout << "Size of array: ";
    cin >> n;
    cout << "Number of splits: ";
    cin >> k;
    cout << "Give the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s = maxEl(n, arr);
    cout << "s " << s << endl;
    int e = totalEl(n, arr);
    cout << "e " << e << endl;
    int ans = minSum(n, arr, s, e, k);
    cout << "ans " << ans << endl;

    return 0;
}