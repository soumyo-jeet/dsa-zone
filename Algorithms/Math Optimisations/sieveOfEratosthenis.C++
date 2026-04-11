// Prime numbers printing from 1 to n
//      ordinary approach -> TC = O(n*n)
//          prime checking -> O(n)
//      by this approch -> TC = O(n)
//          prime checking -> O(1)
//              1. take an array of size n and initialise it with 1 (= every number bw 1-n is prime)
//              2. enter the first prime room (2) and convert all the rooms divisible by 2 to 0 (= those numbers are not prime anymore)
//              3. continue step 2 for all the rooms have 1 after each step
//              4. loop through the rooms of the array and check the value, if it's 1 print it out


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