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
public:
    int myAtoi(string A) {
        string numstr = "";
        int got = 0, sign = 1;
        for (int i = 0; i < A.length(); i++) {
            if (A[i] >= '0' && A[i] <= '9') {
                numstr += A[i];
                got = 1;
            } else if (got)
                break;
            else if ((A[i] == '-' || A[i] == '+') &&
                     (A[i + 1] >= '0' && A[i + 1] <= '9')) {
                sign = A[i] == '-' ? 0 : 1;
            }

            else if (A[i] == ' ')
                continue;
            else
                return 0;
        }

        long long num = 0;
        if (sign == 1)
        {
            for (int i = 0; i < numstr.length(); i++) {
                if (num * 10 + (numstr[i] - '0') >= INT_MAX)
                {
                    num = INT_MAX;
                    break;
                }

                num = num * 10 + (numstr[i] - '0');
            }
        }

        else
        {
            for (int i = 0; i < numstr.length(); i++) {
                if (num * 10 - (numstr[i] - '0') <= INT_MIN)
                {
                    num = INT_MIN;
                    break;
                }

                num = num * 10 - (numstr[i] - '0');
            }
        }

        return num;
    }
};