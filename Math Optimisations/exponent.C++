// Even exponent -->
//      pow(x, n) = pow(x * x, n / 2)
// Odd exponent -->
//      pow(x, n) = x * pow(x , n - 1)

#include<iostream>
using namespace std;

int expo(int x, int n)
{
    if(n == 0) return 1;

    if(n % 2) return x * expo(x, n-1);
    return expo(x * x, n / 2);
}


int main()
{
    int x, n;
    cout << "Enter base: ";
    cin >> x;
    cout << "Enter exponenet: ";
    cin >> n;

    cout << "Required ans: " << expo(x, n);
}