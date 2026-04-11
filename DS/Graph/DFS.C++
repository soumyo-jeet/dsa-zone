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

vector<vector<pair<int, int>>> createGraph(int v)
{
    vector<vector<pair<int, int>>> undirgr(v);
    for (int i = 0; i < v; i++)
    {
        for (int j = i; j < v; j++)
        {
            if (i <= j)
            {
                int e;
                cout << "Edge between " << i << " and " << j << ": ";
                cin >> e;
                if (e > 0)
                {
                    undirgr[i].push_back({j, e});
                    undirgr[j].push_back({i, e});
                }
            }
        }
    }

    return undirgr;
}

void displayGraphList(vector<vector<pair<int, int>>> undirgr)
{
    cout << "\nDisplay: \n";
    int v = undirgr.size();
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < undirgr[i].size(); j++)
        {
            cout << "(" << undirgr[i][j].first << " , " << undirgr[i][j].second << ") | ";
        }
        cout << "\n";
    }
}

void DFS(vector<vector<pair<int, int>>> undirgr, vector<int> &visited, vector<int> &ans, int elm)
{
    // push the node to the ans and update the visit status
    ans.push_back(elm);
    visited[elm] = 1;

    // loop through all of its neighbers 
    for(int i = 0; i < undirgr[elm].size(); i ++)
    {
        int neigh = undirgr[elm][i].first;

        // traverse to all the unvisited neighbers of the neighber
        if(visited[neigh] == 0) DFS(undirgr, visited, ans, neigh);
    }

}

vector <int> DFSS (vector<vector<pair<int, int>>> undirgr)
{
    int v = undirgr.size();
    vector<int> ans, visited(v, 0);
    stack<int> nodes;

    // push the starting point into the nodes stack
    nodes.push(0);

    while(!nodes.empty())
    {
        // pop out the top element and push to ans make visited true also (iff it's not visited already) 
        int top = nodes.top();
        nodes.pop();
        if(visited[top] == 0)
        {
            ans.push_back(top);
            visited[top] = 1;
        }

        // push all the neighbers in the stack but don't flag them as visited so that the later insertion can get major preference (as later insertion implies faster reach)
        for(int i = undirgr[top].size() - 1; i >= 0; i --)
        {
            int neigh = undirgr[top][i].first;
            if(visited[neigh] == 0) nodes.push(neigh);
        }
    }

    return ans;
}


void displayDFS(vector<int> dfs)
{
    cout << "\nDFS Display: \n";
    for (int i = 0; i < dfs.size(); i++)
    {
        cout << dfs[i] << " ";
    }
}

int main()
{
    int v;
    cout << "Number of vertices: ";
    cin >> v;

    vector<vector<pair<int, int>>> undirgr(v);
    undirgr = createGraph(v);
    displayGraphList(undirgr);

    vector<int> dfs(v), visited(v,0), ans;
    DFS(undirgr, visited, ans, 0);
    displayDFS(ans);
    cout << endl;
    ans = DFSS(undirgr);
    displayDFS(ans);
}