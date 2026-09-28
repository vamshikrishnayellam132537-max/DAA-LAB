#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int n = 5;
    int selected[5] = {0};

    selected[0] = 1;

    int edges = 0;
    int totalCost = 0;

    cout << "Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        int min = INT_MAX;
        int x = -1, y = -1;

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j] != 0)
                    {
                        if (graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y
             << " = " << graph[x][y] << endl;

        totalCost += graph[x][y];
        selected[y] = 1;
        edges++;
    }

    cout << "Total Minimum Cost = " << totalCost << endl;

    return 0;
}