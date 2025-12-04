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

class LRU
{
public:
    int size;
    stack<pair<int, int>> memo;

    LRU(int s)
    {
        size = s;
    }

    int get(int key)
    {
        // find the key
        stack<pair<int, int>> temp;
        int val = -1;
        while (!memo.empty())
        {
            if (memo.top().first == key)
            {
                val = memo.top().second;
                memo.pop();
                break;
            }
            // to restore the keys
            temp.push(memo.top());
            memo.pop();
        }

        // restore the memory
        while (!temp.empty())
        {
            memo.push(temp.top());
            temp.pop();
        }

        // if key is not found
        if (val == -1)
            return val;
        // if key is found
        // store back to the top of the memory and return the value
        memo.push({key, val});
        return val;
    }

    void put(int key, int val)
    {
        // update if exists
        if (get(key) != -1)
        {
            // remove the prev entry of the key
            memo.pop();
            // isert the new one
            memo.push({key, val});
            return;
        }

        // insert if memo is not full
        if (memo.size() < size)
        {
            memo.push({key, val});
            return;
        }

        // memo is full => remove the least recently used key => key at the bottom of the stack / memo

        // clean the memo stack
        stack<pair<int, int>> temp;
        while (!memo.empty())
        {
            // to restore the keys
            temp.push(memo.top());
            memo.pop();
        }

        // top of the temp has the lru key => has to be removed
        temp.pop();

        // restore the remaining keys
        while (!temp.empty())
        {
            memo.push(temp.top());
            temp.pop();
        }

        // push the new entry
        memo.push({key, val});
        return;
    }

    
};

void display(stack<pair<int, int>> memory)
{
    while (!memory.empty())
    {
        cout << memory.top().first << " -> " << memory.top().second << endl;
        memory.pop();
    }
}

int main()
{
    int s;
    cout << "Size of the LRU: ";
    cin >> s;
    LRU myLRU = LRU(s);

    string menu = "1. Put, 2. Get, 3. Display\nChoose one: ";
    int opt;
    cout << menu;
    cin >> opt;

    while (opt < 7)
    {
        switch (opt)
        {
        case 1:
            int k, v;
            cout << "Key: ";
            cin >> k;
            cout << "Value: ";
            cin >> v;
            myLRU.put(k, v);
            break;

        case 2:
            int key, res;
            cout << "Key: ";
            cin >> key;
            res = myLRU.get(key);
            cout << res << endl;
            break;

        case 3:
            display(myLRU.memo);
            break;

        default:
            break;
        }

        cout << menu;
        cin >> opt;
    }
}