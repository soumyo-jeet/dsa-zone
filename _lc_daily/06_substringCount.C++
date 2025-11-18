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

int countZeros (string str, int s, int e)
{
    int zeros = 0;
    for(int i = s; i <=e; i++)
    {
        if(str[i] == '0') zeros ++;
    }

    return zeros;
}

int subString(string str)
{
    int strC = 0;
    for(int i = 0; i < str.length(); i++)
    {
        for(int j = i; j < str.length(); j++)
        {
            int s = (j - i) + 1;
            int zeros = countZeros(str, i, j);
            int ones = s - zeros;

            if(zeros * zeros <= ones) strC++;
        }
    }

    return strC;
}


int main ()
{
    string str = "101101";
    cout << subString(str);

    cout << endl << (sqrt(2) - 1);
}