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

void lis (vector<pair<char, char>> list, int i, vector<pair<char, char>> &ans, vector<pair<char, char>> &temp) {
    if(i >= list.size()) {
        if(temp.size() > ans.size()) ans = temp;
        return;
    }

    // take
    if(ans.size() == 0 || temp[i - 1].second < list[i].first) {
        temp.push_back(list[i]);
        lis(list, i+1, ans, temp);
        temp.pop_back();
    }

    // skip
    lis(list, i+1, ans, temp);

    return;
}

int main () {
    int s;
    cout << "Size of the array: ";
    cin >> s;
    vector<pair<char, char>> list(s), ans, temp;
    for(int i = 0; i < s; i++) {
        char f, l;
        cout << "first: ";
        cin >> f;
        cout << "second: ";
        cin >> l;
        list[i].first = f;
        list[i].second = l;
    }

    cout << "the list: ";
    for(int i = 0; i < s; i++) {
        cout << "{ " << list[i].first << ", " << list[i].second << " }" << endl;
    }

    lis(list, 0, ans, temp);
    for(int i = 0; i < ans.size(); i++) {
        cout << "{ " << ans[i].first << ", " << ans[i].second << " }" << endl;
    }
}