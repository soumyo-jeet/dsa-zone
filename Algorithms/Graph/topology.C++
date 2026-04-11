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

vector<vector<int>> createGraph(int v)
{
    vector<vector<int>> dirgr(v);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            int e;
            cout << "Edge between " << i << " to " << j << ": ";
            cin >> e;
            if (e > 0)
            {
                dirgr[i].push_back(j);
            }
        }
    }

    return dirgr;
}

void displayGraph(vector<vector<int>> &graph)
{
    int v = graph.size();
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "(" << graph[i][j] << ") | ";
        }
        cout << " ";
    }
}

vector<int> inDegVec(vector<vector<int>> &graph)
{
    int v = graph.size();
    vector<int> inDeg(v, 0);

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            inDeg[graph[i][j]]++;
        }
    }
    return inDeg;
}


// KAHN'S ALGO
vector<int> topologicalSort(vector<vector<int>> &graph, vector<int> &inDegVec)
{
    int v = graph.size();
    vector<int> topoOrder;
    vector<int> visited(v, 0);
    queue<int> nodes;

    // queue the vertices having 0 indegrees
    for (int i = 0; i < v; i++)
    {
        if (inDegVec[i] == 0)
        {
            nodes.push(i);
            visited[i] = 1;
        }
    }

    while (!nodes.empty())
    {
        // enumarate the front node
        int curr = nodes.front();
        nodes.pop();
        topoOrder.push_back(curr);

        for (int i = 0; i < graph[curr].size(); i++)
        {
            // dlt the visited node, by reducing the connected node's indgree by 1
            inDegVec[graph[curr][i]]--;

            // queue the unvisited nodes having 0 indegree
            if (inDegVec[graph[curr][i]] == 0 && visited[graph[curr][i]] == 0)
            {
                nodes.push(graph[curr][i]);
                visited[graph[curr][i]] = 1;
            }
        }
    }

    return topoOrder;
}


// DFS
int nonVisited (vector<vector<int>> &graph, vector<int> &visited)
{
    for(int i = 0; i < graph.size(); i++)
    {
        if(visited[i] == 0) return i;
    }

    return -1;
}

void DFS (vector<vector<int>> &graph, stack<int> &topoOrder, int node, vector<int> &visited)
{
    visited[node] = 1;

    for(int i = 0; i < graph[node].size(); i++)
    {
        if(visited[graph[node][i]] == 0) 
            DFS(graph, topoOrder, graph[node][i], visited);
    }

    topoOrder.push(node);
}

void topologicalSort_(vector<vector<int>> &graph)
{
    stack<int> topoOrder;
    vector<int> visited(graph.size(), 0);

    int n = 0;
    while(n != -1)
    {
        DFS(graph, topoOrder, n, visited);
        n = nonVisited(graph, visited);
    }


    while(!topoOrder.empty())
    {
        cout << topoOrder.top() << " ";
        topoOrder.pop();
    }
}

int main()
{
    int v;
    cout << "number of vertices: ";
    cin >> v;

    vector<vector<int>> graph = createGraph(v);
    vector<int> inDeg = inDegVec(graph);
    displayGraph(graph);
    cout << endl;
    cout << "Indeg: " ;
    for (int e : inDeg)
    {
        cout << e << " ";
    }

    vector<int> topology = topologicalSort(graph, inDeg);
    cout << endl;
    cout << "Topology BFS: " ;
    for (int e : topology)
    {
        cout << e << " ";
    }

    cout << endl;
    cout << "Topology DFS: " ;
    topologicalSort_(graph);
}