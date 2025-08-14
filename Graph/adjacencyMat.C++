#include <iostream>
using namespace std;

int main ()
{

    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int arr[100][100];

    for(int u = 0; u < n; u++) {
        for(int v = 0; v < n; v++) {
            if(u <= v)
            {
                int edge;
                cout << "Edge between " << u << " and " << v << ": " << flush;
                cin >> edge;
                arr[u][v] = edge;
                arr[v][u] = edge;
            }
        }
    }

    cout << "\nAdjacency Matrix:\n";
    for(int u = 0; u < n; u++) {
        for(int v = 0; v < n; v++) {
            cout << arr[u][v] << " ";
        }
        cout << endl;
    }
}
