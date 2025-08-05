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

int exponent(int a, int b)
{
    int ans = 1;
    for(int i = 1; i <= b; i ++)
    {
        ans *= a;
    }
    return ans;
}

int evaluate (int a, int b, char oprtr)
{
    if(oprtr == '^') return exponent(a, b);
    else if(oprtr == '/') return a / b;
    else if(oprtr == '*') return a * b;
    else if(oprtr == '+') return a + b;
    else if(oprtr == '-') return a - b;
}


int main ()
{
    stack<int> operands;
    string exp;
    cout << "Enter the expression: ";
    cin >> exp;

    for(int i = 0; i < exp.length(); i++)
    {
        if(eval_char(exp[i]) == -1)
        {
            int temp = exp[i] - '0';
            operands.push(temp);
        }

        else
        {
            int A = operands.top();
            operands.pop();
            int B = operands.top();
            operands.pop();

            int res = evaluate(B, A, exp[i]);
            operands.push(res);
        }
    }

    cout << "Required ans: " << operands.top();
    operands.pop();
    return 0;
}