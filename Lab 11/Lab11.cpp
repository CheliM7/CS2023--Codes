#include <iostream>
#include <climits>

using namespace std;

#define V 6

//obtaining the minimum index
int getMinKeyIndex(int key[], bool included[]) {
    int minKey = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)
        if (!included[v] && key[v] < minKey)
            minKey = key[v], minIndex = v;
    return minIndex;
}


//implementing prims algorithm
void primAlgo(int graph[V][V]) {
    int parent[V], key[V];
    bool included[V];

    //setting all to infinity except starting node
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, included[i] = false;

    //change the node as required
    key[0] = 3;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = getMinKeyIndex(key, included);
        included[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !included[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    cout << "Edge \t \t Weight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " and " << i << "\t" << "\t" << graph[i][parent[i]] << "\n";
}

int main() {
    int graph[V][V] = {{0, 3, 0, 0, 0, 1},
                      {3, 0, 2, 1, 10, 0},
                      {0, 2, 0, 3, 0, 5},
                      {0, 1, 3, 0, 5, 0},
                      {0, 10, 0, 5, 0, 4},
                      {1, 0, 0, 0, 4, 0}};

    primAlgo(graph);

    return 0;
}
