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



string shortestPalindrome(string s)
{
    // reverse the string
    string org = s;
    reverse(s.begin(), s.end());

    // merge the org and rev string
    string merged = org + '+' + s;
    
    
    // the last value of the lps array of the merged string will tell untill which id of the org string is matched with rev one => the longest prefix palindrome
    // to make the whole string palindrome atleast the remaining part of the org str has to be added infront of the str
    // if we merge the str in reverse order of that has been done here we will get the id before which the rev string is matched with the original str => the remaining part of the rev str should to be added to the front of the rev str ie, last of org str

    int lpp = LPS(merged);
    string ans = "";
    for(int i = lpp; i < org.length(); i++)
    {
        ans += org[i];
    }
    ans+=org;
    return ans;
}

int main()
{
    string inp;
    cout << "Enter string: ";
    cin >> inp;
    cout << "Ans: " << shortestPalindrome(inp);
}
