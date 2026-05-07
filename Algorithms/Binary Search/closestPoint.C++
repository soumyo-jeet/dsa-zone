#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

int findDist (int x1, int y1, int x2, int y2) {
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int closestPoint (int xt, int yt, int n, int arr[100][2]) {
    int s = 0, e = n - 1, ans = -1;
    while(s <= e) {
        int mid = s + (e - s) / 2;
        ans = mid;

        int leftD = INT_MAX, rightD = INT_MAX,
        currD = findDist(xt, yt, arr[mid][0], arr[mid][1]);
        if(mid != 0) leftD =  findDist(xt, yt, arr[mid - 1][0], arr[mid - 1][1]);
        if(mid != n - 1) rightD = findDist(xt, yt, arr[mid + 1][0], arr[mid + 1][1]);

        if(leftD <= currD) e = mid - 1;
        else s = mid + 1;
    }

    return ans;
}

int main () {
    int n;
    cout << "Number of points: ";
    cin >> n;

    int arr[n][2];
    for(int i = 0; i < n; i++) {
        int x, y;
        cout << "Point " << i + 1 << "x : ";
        cin >> x;
        cout << "y: ";
        cin >> y;
        arr[i][0] = x;
        arr[i][1] = y;
    }

    int xt, yt;
    cout << "Target: x: ";
    cin >> xt;
    cout << "y: ";
    cin >> yt;

    int cp = closestPoint(xt, yt, n, arr);
    cout << arr[cp][0] << "  " << arr[cp][1];
}