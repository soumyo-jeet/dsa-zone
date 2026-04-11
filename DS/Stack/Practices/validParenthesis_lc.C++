#include <iostream>
#include <stack>
#include <string>
using namespace std;

int isValidParenthesis(string str)
{
    cout << "len: " << str.length();
    stack<char> pStr;
    for (int i = 0; i < str.length(); i++)
    {
        char cur = str[i];

        if (cur == '(' || cur == '{' || cur == '[')
        {
            pStr.push(cur);
        }

        else
        {
            if (pStr.empty())
                return 0;

            if (cur == ')')
            {
                if (pStr.top() == '(')
                    pStr.pop();
                else
                    return 0;
            }

            else if (cur == '}')
            {
                if (pStr.top() == '{')
                    pStr.pop();
                else
                    return 0;
            }

            else if (cur == ']')
            {
                if (pStr.top() == '[')
                    pStr.pop();
                else
                    return 0;
            }

            else return 0;
        }

    }
    
    
    if (pStr.empty())
        return 1;
    return 0;
}

int main()
{
    string inp;
    cout << "Entre the parenthesis saga: ";
    cin >> inp;
    cout << isValidParenthesis(inp);
}