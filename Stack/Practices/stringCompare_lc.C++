#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> backspacedString (string s)
{
    stack<char> st;
    for(int i = 0; i < s.size(); i++) 
    {
        if(s[i] == '#') 
        {
            if(!st.empty())
            {
                st.pop();
            } 
        }

        else st.push(s[i]);
    }
    return st;
}

int compareBackspacedString (string s, string t) 
{
    stack<char> bs = backspacedString(s) , bt = backspacedString(t);

    if(bs.size() != bt.size()) return 0;

    while(!bs.empty())
    {
        if(bt.top() == bs.top()) bt.pop();
        bs.pop();
    }

    if(bt.empty()) return 1;
    return 0;
}

int main () 
{
    string s, t;
    cout << "String 1: ";
    cin >> s;
    cout << "String 2: ";
    cin >> t;

    int check = compareBackspacedString(s, t);
    if(check) cout << "Same";
    else cout << "Not Same";
    return 0;
}