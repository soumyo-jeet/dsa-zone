#include <iostream>
using namespace std;

int maxW(int n, int arr[])
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        max = max < arr[i] ? arr[i] : max;
    }
    return max;
}

int totalW(int n, int arr[])
{
    int sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int minCap(int n, int arr[], int s, int e, int k)
{
    int ans;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        int load = 0, d = 1;
        for(int i = 0; i < n; i++) {
            if(load + arr[i] > mid) {
                d++;
                load = 0;
            }
            load += arr[i];
        }

        if(d > k) s = mid + 1;
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
    cout << "Number of package: ";
    cin >> n;
    cout << "Number of days: ";
    cin >> k;
    cout << "Give the weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s = maxW(n, arr);
    cout << "s " << s << endl;
    int e = totalW(n, arr);
    cout << "e " << e << endl;
    int ans = minCap(n, arr, s, e, k);
    cout << "ans " << ans << endl;


    return 0;
}