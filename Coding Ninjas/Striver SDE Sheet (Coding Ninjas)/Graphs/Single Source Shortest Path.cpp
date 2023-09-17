#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=C4gxoTaI71U&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=19

vector<int> shortestPath(int n, vector<vector<int>> &edges, int src)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> distance(n, 1e9);
    distance[src] = 0;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();

        for (auto it : adj[currNode])
        {
            if (distance[currNode] + 1 < distance[it])
            {
                distance[it] = distance[currNode] + 1;
                q.push(it);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (distance[i] == 1e9)
        {
            distance[i] = -1;
        }
    }
    return distance;
}