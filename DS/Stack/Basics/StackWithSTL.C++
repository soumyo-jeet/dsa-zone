#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(5);
    s.push(9);
    cout << s.size() << endl;
    cout << s.empty() << endl;

    // Traversing Stack
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}