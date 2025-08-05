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

int eval_char(char cc)
{
    if(cc == '^') return 0;
    else if(cc == '/' || cc == '*') return 1;
    else if(cc == '+' || cc == '-') return 2;
    else return -1;
}

int main()
{
    stack<string> operands;
    string exp;
    cout << "Enter a postfix expression: ";
    cin >> exp;

    for(int i = 0; i < exp.length(); i++)
    {
        if(eval_char(exp[i]) == -1)
        {
            string temp = "";
            temp += exp[i];
            operands.push(temp);
        }

        else
        {
            string A = operands.top();
            operands.pop();
            string B = operands.top();
            operands.pop();

            string res = '(' + B + exp[i] + A + ')';
            operands.push(res);
        }
    }

    cout << "Required infix expression is: " << operands.top();
    operands.pop();
    return 0;
}