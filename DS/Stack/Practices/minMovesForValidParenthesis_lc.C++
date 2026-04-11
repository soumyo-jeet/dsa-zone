#include <iostream>
#include <stack>
#include <string>
using namespace std;

int requireMoves(string str)
{
    stack<char> pStr; 
    int fp = 0;
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
                fp++;

            else if (cur == ')')
            {
                if (pStr.top() == '(')
                    pStr.pop();
                else
                    fp++;
            }

            else if (cur == '}')
            {
                if (pStr.top() == '{')
                    pStr.pop();
                else
                    fp++;
            }

            else if (cur == ']')
            {
                if (pStr.top() == '[')
                    pStr.pop();
                else
                    fp++;
            }

            else return 0;
        }

    }
    
    return pStr.size() + fp;
}

int main()
{
    string inp;
    cout << "Entre the parenthesis saga: ";
    cin >> inp;
    cout << requireMoves(inp);
}