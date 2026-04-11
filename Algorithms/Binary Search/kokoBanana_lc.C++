#include<iostream>
using namespace std;

int maxPile(int n, int arr[])
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        max = max < arr[i] ? arr[i] : max;
    }
    return max;
}

int minPile(int n, int arr[])
{
     int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        min = min > arr[i] ? arr[i] : min;
    }
    return min;
}

int minSpeed(int n, int arr[], int h, int s, int e) {
    int ans;
    while( s <= e) {
        int mid = s + (e - s) / 2;

        int p = 0, t = 0; 
        while(p < n) {
            int time = (arr[p] % mid == 0) ? arr[p] / mid : (arr[p] / mid) + 1;
            t += time;
            p++;
        }

        if(t > h) s = mid + 1;
        else {
            ans = mid;
            e = mid - 1;
        }

    }
    return ans;
}

int main() {
     int n, arr[1000], h;
    cout << "Number of piles: ";
    cin >> n;
    cout << "Hours: ";
    cin >> h;
    cout << "Bananas in piles: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s = minPile(n, arr);
    cout << "s " << s << endl;
    int e = maxPile(n, arr);
    cout << "e " << e << endl;
    
    int ans = minSpeed(n, arr, h, s, e);
    cout << "ans " << ans << endl;


    return 0;
}