#include <iostream>
using namespace std;

int maxLen(int n, int arr[])
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        max = max < arr[i] ? arr[i] : max;
    }
    return max;
}

int totalLen(int n, int arr[])
{
    int sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int minTime(int n, int arr[], int s, int e, int k)
{
    int ans;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        int p = 1, time = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (time + arr[i] > mid)
            {
                p++;
                time = 0;
            }
            time += arr[i];
        }

        if(p > k) s = mid + 1;
        else {
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n, arr[1000], k;
    cout << "Number of boards: ";
    cin >> n;
    cout << "Number of painters: ";
    cin >> k;
    cout << "Give the sizes of the boards: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s = maxLen(n, arr);
    cout << "s " << s << endl;
    int e = totalLen(n, arr);
    cout << "e " << e << endl;
    int ans = minTime(n, arr, s, e, k);
    cout << "ans " << ans << endl;


    return 0;
}