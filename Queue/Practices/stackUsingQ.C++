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

class MyStack {
    queue<int> q;
    int size;
public:
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        q.push(x);
        size ++;
    }
    
    int pop() {
        while(size > 1)
        {
            q.push(q.front());
            q.pop();
            size--;
        }

        int el = q.front();
        q.pop();
        size=q.size();
        return el;
    }
    
    int top() {
        while(size > 1)
        {
            q.push(q.front());
            q.pop();
            size--;
        }

        int el = q.front();
        q.pop();
        q.push(el);
        size = q.size();
        return el;
    }
    
    bool empty() {
        if(q.empty()) return 1;
        return 0;     
    }
};