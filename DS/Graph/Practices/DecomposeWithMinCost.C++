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

vector<vector<int>> createCompleteGraph(int v)
{
    vector<vector<int>> graph(v, vector<int>(v, INT_MAX));
    for (int i = 0; i < v; i++)
    {
        for (int j = i + 1; j < v; j++)
        {
            graph[i][j] = (i + 1) * (j + 1);
            graph[j][i] = (i + 1) * (j + 1);
        }
    }

    return graph;
}

int decompose(int limit, vector<vector<int>> &graph)
{
    int u = 1, v = 0, disuv = 0, cost = 0;
    while (cost < limit && u < graph.size())
    {
        // ignore already disconnected

        if (graph[u][v] != INT_MAX)
        {

            // record the edge gonna be removed
            disuv = 10 * u + v;

            // disconnect u--v
            graph[u][v] = INT_MAX;
            graph[v][u] = INT_MAX;

            // add the cost
            cost += (u + 1) * (v + 1);
        }

        v++;
        // jump next vertex while boundary reached
        if (v == graph.size())
        {
            v = 0;
            u++;
        }
    }

    if (cost > limit)
    {
        // restore the last disconnected edge
        int u = disuv / 10, v = disuv % 10;
        graph[u][v] = (u + 1) * (v + 1);
        graph[v][u] = (u + 1) * (v + 1);
        cost -= (u + 1) * (v + 1);
    }
    return cost;
}

void viewGraph(vector<vector<int>> graph, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << graph[i][j] << "   ";
        }
        cout << endl;
    }
}

void DFS (int s, vector<vector<int>> &graph, vector<int> &visited, int &count) 
{
    visited[s] = 1;
    count ++;

    for(int i = 0; i < graph.size(); i++) 
    {
        if(graph[s][i] != INT_MAX && visited[i] != 1) 
        {
            DFS(i, graph, visited, count);
        }
    }
}

int nodesFromCentral (vector<vector<int>> &graph, int v) 
{
    int count = -1;
    vector<int> visited(v, 0);
    DFS(0, graph, visited, count);
    return count;
}

int main()
{
    int v;
    cin >> v;
    vector<vector<int>> graph = createCompleteGraph(v);
    cout << endl
         << "Before Decomposition" << endl;
    viewGraph(graph, v);
    cout << endl << "Minimum nodes can be reached now: " << nodesFromCentral(graph, v) << endl;

    int limit;
    cout << "Budget: ";
    cin >> limit;

    cout << "Decomposed with cost: " << decompose(limit, graph) << "& after decomposition: \n";
    viewGraph(graph, v);

    cout << endl << "Minimum nodes can be reached now: " << nodesFromCentral(graph, v) << endl;
}