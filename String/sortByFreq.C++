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

string frequencySort(string s)
{
    // map the freqs of each chars
    unordered_map<char, int> charMap;
    for (char c : s)
        charMap[c]++;

    // sort the map using vector pair
    vector<pair<char, int>> tempV;
    for (auto &it : charMap)
    {
        tempV.push_back(it);
    }

    // define customised comparision func for sorting
    auto lambda = [&](pair<char, int> a, pair<char, int> b) {
        // sort same freq chars based on their seq
        if(a.second == b.second) return a.first < a.second;
        return a.second > b.second;
    };

    sort(tempV.begin(), tempV.end(), lambda);

    string ans = "";
    for(auto &it : tempV)
    {
        ans.append(it.second, it.first);
    }
    return ans;
}

int main ()
{
    string inp;
    cout << "Enter string: ";
    cin >> inp;
    cout << "Ans: " << frequencySort(inp);
}