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

class Solution {
// If direction is R => no collision with prevCars is possible => push it to the record
// else collision due to prevCars may be posiible
//          collision iff prevCars are not at same dir
//          while collides the prevCar with which the current car collides can be deleted from the record as it becomes static 
//          make current car also static
// record the prevCar status ultimately

public:
    int countCollisions(string directions) {
        stack<char> prevCars;
        int colls = 0;
        prevCars.push(directions[0]);
        for(int i = 1; i < directions.length(); i++)
        {
            char currDir = directions[i]; 
            if(prevCars.empty() || currDir == 'R') prevCars.push(directions[i]);
            else
            {
                while(!prevCars.empty() && currDir != prevCars.top())
                {
                    if(prevCars.top() == 'L') break;
                    else if(prevCars.top() == 'R' && currDir == 'L')
                    {
                        colls += 2;
                    } 
                    else {
                        colls++;
                    }
                    
                    currDir = 'S';
                    prevCars.pop();
                }

                prevCars.push(currDir);
            }
        }

        return colls;

    }
};


// https://leetcode.com/problems/count-collisions-on-a-road/