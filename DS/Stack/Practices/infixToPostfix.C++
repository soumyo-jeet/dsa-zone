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

int encode_operators (char op)
{
    if(op == '^') return  1;
    else if(op == '*' || op == '/') return  2;
    else if(op == '+' || op == '-') return  3;
    else  return -1;
}


int main()
{
    string inp_exp, ans_exp = " ";
    cout << "Give the infix expression: ";
    cin >> inp_exp;

    inp_exp += '#';
    int ops = 0;
    stack<char> opst;
    opst.push('#');

    for(int i = 0; i < inp_exp.length(); i ++)
    {
        int code = encode_operators(inp_exp[i]);

        if(code >= 1 && code <= 3)
        {
            if(encode_operators(opst.top()) == -1) opst.push(inp_exp[i]);
            else if (encode_operators(opst.top()) < code) 
            {
                while(encode_operators(opst.top()) != -1 && encode_operators(opst.top()) < code)
                {
                    ans_exp+= opst.top();
                    opst.pop();
                }
                opst.push(inp_exp[i]);
            }

            else opst.push(inp_exp[i]);
        }

        else if(inp_exp[i] == '(')
        {
            opst.push(inp_exp[i]);
        }

        else if(inp_exp[i] == ')')
        {
            while(opst.top() != '(')
            {
                ans_exp += opst.top();
                opst.pop();
            }
            opst.pop();
        }

        else if(inp_exp[i] == '#')
        {
            while(opst.top() != '#')
            {
                ans_exp += opst.top();
                opst.pop();
            }
            opst.pop();
        }

        else 
        {
            ans_exp += inp_exp[i];
        }
    }

    cout << endl << "Postfix Expression: " << ans_exp;
}