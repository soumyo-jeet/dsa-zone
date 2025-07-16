#include<iostream>
#include<stack>
using namespace std;

void reverseArr(int arr[1000], int n) 
{
    stack<int> temp;
    for(int i = 0; i < n; i++)
    {
        temp.push(arr[i]);
    }

    int i = 0;
    while(!temp.empty()) 
    {
        arr[i++] = temp.top();
        temp.pop();
    }
}

int main () 
{
    int arr[1000], n;
    cout << "Size of array: ";
    cin >> n;

    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    reverseArr(arr, n);

    for(int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }

    return 0;
}