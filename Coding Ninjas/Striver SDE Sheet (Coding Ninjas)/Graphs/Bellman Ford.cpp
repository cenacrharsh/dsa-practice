#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=0vVofAhAYjc&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=23

/*
    - Why (N - 1) iterations ?
    @ Since in a graph of N nodes, in worst case you will take N - 1 edges to reach from the first to the last, thereby we iterate for N - 1 iterations

    - How to detect a negative cycle (a cycle in which overall path sum keeps decreasing)
    @ If after N - 1 iterations we are still getting paths with lesser value it will indicate we are in a negative cycle
*/

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> distances(V, 1e8);
    distances[S] = 0;

    //* do relaxation of edges n - 1 times
    for (int i = 1; i < V; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (distances[u] != 1e8 && distances[u] + w < distances[v])
            {
                distances[v] = distances[u] + w;
            }
        }
    }

    //* Nth relaxation for detecting negative cycles
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];

        if (distances[u] != 1e8 && distances[u] + w < distances[v])
        {
            return {-1};
        }
    }

    return distances;
}