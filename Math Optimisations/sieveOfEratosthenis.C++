// Prime numbers printing from 1 to n
//      ordinary approach -> TC = O(n*n)
//          prime checking -> O(n)
//      by this approch -> TC = O(n)
//          prime checking -> O(1)
//              1. take an array of size n and initialise it with 1 (= every number bw 1-n is prime)
//              2. enter the prime rooms and convert all the rooms divisible by the entered prime room with 0 (= those numbers are not prime anymore)
//              3. loop through 1 to n and check corresponding room in the array, if it's 1 print it out


#include<iostream>
#include<vector>
using namespace std;

void printPrimes(int n)
{
    vector<int> arr(n, 1);
    for(int i = 2; i < n; i++)
    {
        if(arr[i-1])
        {
            for(int j = i + i - 1 ; j <= n; j += i)
            {
                arr[j] = 0;
            }
        }
    }

    cout << "All prime numbers from 1 to " << n << endl;
    for(int i = 2; i <= n ; i ++)
    {
        if(arr[i-1]) cout << i << " ";
    }
}


int main()
{
    printPrimes(100);
}