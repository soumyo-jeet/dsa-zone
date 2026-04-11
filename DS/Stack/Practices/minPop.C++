#include <iostream>
#include <stack>
using namespace std;

stack<int> _push(int arr[], int n) {
    stack<int> st;
    for(int i = 0; i <n; i++) 
    {
        if(i == 0)
        {
            st.push(arr[i]);
        }

        else
        {
            int min = arr[i] < st.top() ? arr[i] : st.top();
            st.push(min);
        }
    }
    return st;
}



void printMinAtPop(stack<int> s) 
{
    while(!s.empty()) 
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    int arr[1000], n;
    cout << "Size of array: ";
    cin >> n;

    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    stack<int> st = _push(arr, n);
    printMinAtPop(st);
    return 0;

}