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

int main ()
{
    int n, m, arr[100][100], sparse[100][3], indx = 1, count = 0;
    cout << "Enter no of rows in sparse mat: ";
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> sparse[i][j]; 
        }
    }

    int r = sparse[0][1], c = sparse[0][0];

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            arr[i][j] = 0;
        }
    }

    for(int i = 1; i < n; i ++) {
        int col = sparse[i][0];
        int row = sparse[i][1];
        int val = sparse[i][2];

        arr[row][col] = val;
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c ; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

}