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

int LPS(string str)
{
    // create an array having size = size of the string to record how much part of the prefix is equal to the suffix
    vector<int> recordLPS(str.length(), 0);

    // two pointers
    int prefix = 0 // carries the length of the prefix matched with suffix
    , suffix = 1;   // carries the current position of the string

    while (suffix < str.length())
    {
        if (str[prefix] == str[suffix])
        {
            recordLPS[suffix] = prefix + 1; // the index stored in the suffix index of the record says prefix before that index is matched with the suffix
            prefix++;
        }
        
        else
        {
            // find the last match
            while(prefix > 0 && str[prefix] != str[suffix])
            {
                prefix = recordLPS[prefix - 1]; // it brings prefix to the past pre=suff len
            }
            
            // check match
            if(str[prefix] == str[suffix])
            {
                recordLPS[suffix] = prefix + 1;
                prefix ++;
            }
        }

        suffix++;
    }

    for(int i = 0; i < recordLPS.size(); i++)
    {
        cout << recordLPS[i] << "  ";
    }
    cout << endl;

    // last index value of record tells the largest matched pre suff len
    return recordLPS[recordLPS.size() - 1];

}


int main ()
{
    string inp;
    cout << "Enter string: ";
    cin >> inp;
    cout << "Ans: " << LPS(inp);
}