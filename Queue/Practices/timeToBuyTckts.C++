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

int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int time = 0;
    queue<int> q;
    for(int i = 0; i < tickets.size(); i ++)
    {
        q.push(i);
    }

    while(!q.empty() && !(tickets[k] == 0))
    {
        tickets[q.front()] --;
        if(tickets[q.front()] > 0) 
        {
            q.push(q.front());
        }

        q.pop();
        time++;
    }
}


int main()
{
    int n;
    vector <int> arr;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }


    int k, ans;
    cin >> k;
    ans = timeRequiredToBuy(arr, k);
    cout<<ans;
}