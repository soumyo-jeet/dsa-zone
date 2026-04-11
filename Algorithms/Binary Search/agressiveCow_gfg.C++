#include <iostream>
using namespace std;

void sort(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int maxEl(int n, int arr[])
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        max = max < arr[i] ? arr[i] : max;
    }
    return max;
}

int minEl(int n, int arr[])
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        min = min > arr[i] ? arr[i] : min;
    }
    return min;
}

int minDist(int n, int arr[], int k, int s, int e)
{
    int ans;
    sort(n, arr);

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int stall = arr[0], cow = 1;
        for (int i = 1; i < n; i++)
        {
            int dist = arr[i] - stall;
            if (dist >= mid)
            {
                stall = arr[i];
                cow++;
            }
        }
        if (cow < k)
            e = mid - 1;
        else
        {
            ans = mid;
            s = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n, arr[1000], k;
    cout << "Number of stalls: ";
    cin >> n;
    cout << "Number of cows: ";
    cin >> k;
    cout << "Give the stalls: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    int e = maxEl(n, arr) - minEl(n, arr);
    cout << "e " << e << endl;
    int ans = minDist(n, arr, k, 1, e);
    cout << "ans " << ans;


}