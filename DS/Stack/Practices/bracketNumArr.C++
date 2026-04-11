#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<int> bracketNumbers(string s)
{
    stack<int> fbs;
    vector<int> ans;
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        char cur = s[i];
        if (cur == '(')
        {
            count ++;
            fbs.push(count);
            ans.push_back(fbs.top());
        }

        else
        {
            if (fbs.empty() || cur != ')')
                continue;
            else
            {
                ans.push_back(fbs.top());
                fbs.pop();
            }
        }
    }

    return ans;
}

int main()
{
    string s;
    cout << "Bracket string: ";
    cin >> s;

    vector<int> ans = bracketNumbers(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}