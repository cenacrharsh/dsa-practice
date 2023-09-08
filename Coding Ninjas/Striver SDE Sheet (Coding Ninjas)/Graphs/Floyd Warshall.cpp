#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=YbY8cVwWAvw&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=25

/*
> Time Complexity: O(N^3)
> Space Complexity: O(N^2)
*/

/*
    Floyd Warshall: Multisource Shortest Path Algorith (helps detect negative cycles as well)

    If the value of a node to itself is < 0 then we can say a negative cycle exists
*/

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1, 0));

    //* initialize all diagonals to 0
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                adjMatrix[i][j] = 0;
            }
            else
            {
                adjMatrix[i][j] = 1e9;
            }
        }
    }

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjMatrix[u][v] = w;
    }

    //* try out all paths
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adjMatrix[i][k] != 1e9 && adjMatrix[k][j] != 1e9)
                {
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
    }

    // detect negative cycles
    // if(i = 0; i < n; i++) {
    //     if(adjMatrix[i][i] < 0) {
    //         cout << "Negative cycle detected" << endl;
    //     }
    // }

    return adjMatrix[src][dest];
}