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
#include <sstream>

using namespace std;

int main()
{
    string s = "hello broyther.";
    string token;
    stringstream ss(s);
    while(getline(ss, token, ' '))
    {
        cout << token;
    }
    token[0];
}