#include <iostream>
using namespace std;

#define MAX 100

struct Edge
{
    int u, v, weight;
};

int parent[MAX];

// Find the parent of a vertex
int find(int x)
{
    if (parent[x] == x)
        return x;

    return find(parent[x]);
}

// Union two sets
void unionSets(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    parent[rootA] = rootB;
}

// Sort edges by weight
void sortEdges(Edge edges[], int e)
{
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, e;
    int count = 0, totalCost = 0;

    Edge edges[MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    // Initialize parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by weight
    sortEdges(edges, e);

    cout << "\nEdges in Minimum Spanning Tree:\n";

    // Kruskal's Algorithm
    for (int i = 0; i < e && count < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v))
        {
            cout << u << " -- " << v
                 << "  Weight = " << edges[i].weight << endl;

            totalCost += edges[i].weight;

            unionSets(u, v);

            count++;
        }
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}