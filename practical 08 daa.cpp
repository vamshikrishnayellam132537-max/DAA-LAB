#include <iostream>
using namespace std;

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

// DFS Function
void DFS(int vertex)
{
    cout << vertex << " ";
    visited[vertex] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// BFS Function
void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = 0;

    // Reset visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int vertex = queue[front++];

        cout << vertex << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    // Reset visited array for DFS
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "\nDFS Traversal: ";
    DFS(start);

    cout << "\nBFS Traversal: ";
    BFS(start);

    return 0;
}