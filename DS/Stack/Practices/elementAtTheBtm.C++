#include <iostream>
#include <stack>
using namespace std;

void print(stack<int> s) 
{
    if(s.empty()) return;

    int x = s.top();
    s.pop();
    print(s);
    cout << x << " ";
}

void insertAtBtm (stack<int> s, int x) 
{
    stack<int> temp;
    while(!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }

    s.push(x);

    while(!temp.empty()) 
    {
        s.push(temp.top());
        temp.pop();
    }

    print(s);
}

int main()
{
    stack<int> s; int n, x;
    cout << "Elements: ";

    for(int i = 0; i < n; i++) 
    {
        int e;
        cin >> e;
        s.push(e);
    }

    cout << "Want to insert: ";
    cin >> x;

    insertAtBtm(s, x);

}