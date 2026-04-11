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
    string str;
    queue<char> temp;
    cout << "Enter a string: ";
    cin >> str;

    temp.push(str[0]);
    string ans;
    ans += str[0];

    for (int i = 1; i < str.length(); i++)
    {
        if (temp.empty())
        {
            ans += '#';
            temp.push(str[i]);
        }

        else if (temp.front() == str[i])
        {
            temp.pop();
            if (temp.empty())
            {
                ans += '#';
            }
            else ans += temp.front();
        }

        else
        {
            ans += temp.front();
            temp.push(str[i]);
        }
    }

    cout << ans;
}