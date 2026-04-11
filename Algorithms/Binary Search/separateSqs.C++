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
    double min(double a, double b) { return a < b ? a : b; }
    double max(double a, double b) { return a > b ? a : b; }

    // Pass squares by reference to avoid copying the whole array each time
    bool checkBtm(const vector<vector<int>>& squares, double midy, double target)
    {
        double areabtm = 0;

        // Use reference here as well to avoid copying each square
        for (const vector<int>& square : squares)
        {
            double y = square[1];
            double l = square[2];

            // Height of this square below midy:
            // intersection of [y, y+l] with (-inf, midy]
            double hbtm = max(0.0, min(midy, y + l) - y);

            // Area contributed by this square below the line
            areabtm += hbtm * l;
        }

        // We want area below >= half the total area
        return (areabtm >= target);
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        double maxy = -1e18, miny = 1e18;
        double totalarea = 0;

        // Compute global y-range and total area
        for (const vector<int>& square : squares)
        {
            double y = square[1];
            double l = square[2];

            miny = min(miny, y);
            maxy = max(maxy, y + l);
            totalarea += l * l;
        }

        double req = totalarea / 2.0;   // target area below
        double start = miny, end = maxy;
        double ans = 0.0;

        // Binary search on y
        while ((end - start) > 1e-5)
        {
            double mid = start + (end - start) / 2.0;

            if (checkBtm(squares, mid, req))
            {
                ans = mid;     // mid is high enough, try lower
                end = mid;
            }
            else
            {
                start = mid;   // mid is too low, go higher
            }
        }

        return ans;
    }
};


// https://leetcode.com/problems/separate-squares-i