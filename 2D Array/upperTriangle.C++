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

int main()
{
    int n, m;
    float arr[100][100];
    cout << "Enter no of rows: ";
    cin >> n;
    cout << "Enter no of cols: ";
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 

    int k = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int piv = arr[i][k];
        for (int j = k; j < m; j++)
        {
            arr[i][j] = arr[i][j] / piv;
        }

        for (int r = i + 1; r < n; r++)
        {
            for (int j = k; j < m; j++)
            {
                arr[r][j] -= arr[i][j] * arr[r][k];
            }
        }  

        k++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%.2f ", arr[i][j]);
        }
        cout << endl;
    }
}