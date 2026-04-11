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

string devideBy2(string div, int &rem)
{
    // do division 
    string q = "";
    rem = 0;
    for(char c: div)
    {
        int curr = (rem * 10) + (c - '0');
        q += (curr  / 2) + '0';
        rem = curr % 2;
    }
    
    // removing 0s from front
    int pos = 0;
    while(pos < q.size() - 1 && q[pos] == '0') pos++;
    return q.substr(pos);
}


int power(string A) {
    
    int i = 0;
    while(i < A.size()-1 && A[i] == 0) i++;
    A = A.substr(i);
    
    if(A == "0" || A == "1") return 0;
    
    while(A != "1")
    {
        int rem = 0;
        A = devideBy2(A, rem);
        // number not divisible by 2
        if(rem != 0) return 0;
    }
    return 1;
}
