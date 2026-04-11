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

class UnionFind {
    vector<int> componentOf; // the label of its parent set
    vector<vector<int>> members; // members in each parent set
    public:
    UnionFind(int V) {
        componentOf.resize(V);
        members.resize(V);

        for(int i = 0; i < V; i++) {
            componentOf[i] = i;
            members[i].push_back(i);
        }
    }

    void merge(int k, int k_) {
        int minset = members[k].size() < members[k_].size() ? k : k_;
        int maxset = minset == k ? k_ : k;

        // insert all the members of minset to maxset 
        // and update the label of each member of the minset with the maxset
        for(int mem: members[minset]) {
            members[maxset].push_back(mem);
            componentOf[mem] = maxset;
        } 
    } 

    int find(int n) {
        // return the set label n is member of
        return componentOf[n];
    }
};

vector<pair<int, pair<int, int>>> createGraph (int v) {
    vector<pair<int, pair<int, int>>> graph;
    for(int i = 0; i < v; i++)
    {
        for(int j = i; j < v; j ++)
        {
            if (i <= j)
            {
                int e;
                cout << "Edge between " << i << " and " << j << ": ";
                cin >> e;
                if(e > 0) 
                {
                    graph.push_back({e, {i, j}});
                }
            }
        }
    }


    cout << "\nYour graph\n";
    for(auto e: graph) {
        cout << e.first << ": " << "{ " << e.second.first << ", " << e.second.second << " }" << endl;
    }

    return graph;
}

vector<pair<int, pair<int, int>>> kruskalMST (vector<pair<int, pair<int, int>>>& graph, int V) {
    sort(graph.begin(), graph.end()); // sort the edges by costs
    cout << "\nYour graph\n";
    for(auto e: graph) {
        cout << e.first << ": " << "{ " << e.second.first << ", " << e.second.second << " }" << endl;
    }

    vector<pair<int, pair<int, int>>> MST;
    int i = 0;

    UnionFind *UF = new UnionFind(V);

    while(MST.size() != V - 1) {
        auto edge = graph[i++];
        int cost = edge.first, u = edge.second.first, v = edge.second.second;

        if(UF->find(u) != UF->find(v)) {
            // both are part of different set
            UF->merge(UF->find(u), UF->find(v)); // merge by parents
            MST.push_back({cost, {u, v}});
        }
    }

    cout << "\nYour MST\n";
    for(auto e: MST) {
        cout << e.first << ": " << "{ " << e.second.first << ", " << e.second.second << " }" << endl;
    }
}

int main () {
    int v;
    cin >> v;
    vector<pair<int, pair<int, int>>> graph = createGraph(v);
    kruskalMST(graph, v);
}