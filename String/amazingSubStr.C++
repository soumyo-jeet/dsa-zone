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

int solve(string A) {
    int count = 0;
    for(int i = 0; i < A.length(); i++)
    {
        char c = A[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') 
        // all possible sunstr = len of the remaining str
        count = (count + A.length() - i) % 10003;
    }
    return count;
}
