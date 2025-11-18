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

int removeMatch (string s)
{
    vector<int> acount(s.length());
    acount[0] = s[0] == 'a' ? 1 : 0;
    for(int i = 1; i < s.length(); i++)
    {
        acount[i] = acount[i - 1] + (s[i] == 'a' ? 1 : 0);
    }

    cout << "acount view: \n";

    for(int i = 0; i < s.length(); i++)
    {
        cout << acount[i] << " ";
    }

    cout << endl;

    int maxL = 0, count = 0;
    for(int i = 0; i < s.length(); i++)
    {
        for(int j = i; j < s.length(); j++)
        {
            int counta = acount[j] - (i - 1 >= 0 ? acount[i - 1] : 0);
            int len = (j - i) + 1;
            int countb = len - counta;

            if (counta == countb)
            {
                if (maxL == len) count++;
                else if(len > maxL)
                {
                    maxL =  len;
                    count = 1;
                }
            } 
            else
            {
                int need = counta - countb;
                need = need < 0 ? need * (-1) : need;
                j += need - 1;
            }
        }
    }

    cout << "Max: " << maxL << " Count: " << count;

    return s.length() - (maxL * count);
}

int minLengthAfterRemovals(string s) 
{
    stack<int> temp;
    temp.push(s[0]);

    for(int i = 1; i < s.length(); i ++)
    {
        if(!temp.empty() && temp.top() != s[i])
        {
            temp.pop();
        }
        else temp.push(s[i]);
    }

    return temp.size();
}




int main()
{
    string s = "abaaab";
    cout << "Current length: " << minLengthAfterRemovals(s);
}