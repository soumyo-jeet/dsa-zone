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
    cout << "Enter no of rows: ";
    cin >> n;
    cout << "Enter no of cols: ";
    cin >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            
        }
    }


    // sparse matrix structure
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] != 0)
            {
                sparse[indx][0] = i;
                sparse[indx][1] = j;
                sparse[indx][2] = arr[i][j];
                indx ++;
                count ++;
            }
        }
    }

    sparse[0][0] = n;
    sparse[0][1] = m;
    sparse[0][2] = count;


    cout << "Before transpose and sorting" << endl;
    for(int i = 0; i < indx; i++) {
        for(int j = 0; j < 3 ; j++) {
            cout << sparse[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "After transpose and sorting" << endl;

    // transpose taking
    for(int i = 0; i < indx; i++)
    {
        int temp = sparse[i][0];
        sparse[i][0] = sparse[i][1];
        sparse[i][1] = temp;
    }


    // sorting
    for(int i = 1; i < indx - 1; i++)
    {
        if(sparse[i][0] > sparse[i+1][0])
        {
            // col swapping
            int temp = sparse[i][0];
            sparse[i][0] = sparse[i+1][0];
            sparse[i+1][0] = temp;

            // row swapping
            temp = sparse[i][1];
            sparse[i][1] = sparse[i+1][1];
            sparse[i+1][1] = temp;

            // val swapping 
            temp = sparse[i][2];
            sparse[i][2] = sparse[i+1][2];
            sparse[i+1][2] = temp;

        }    
    }


    

    for(int i = 0; i < indx; i++) {
        for(int j = 0; j < 3 ; j++) {
            cout << sparse[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}