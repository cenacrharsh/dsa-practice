#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=ZUFQfFaU-8U&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=21

/*
> Time Complexity: O(N+M) {for the topological sort} + O(N+M) {for relaxation of vertices, each node and its adjacent nodes get traversed} ~ O(N+M)

> Space Complexity: O( N) {for the stack storing the topological sort} + O(N) {for storing the shortest distance for each node} + O(N) {for the visited array} + O( N+2M) {for the adjacency list} ~ O(N+M)
*/

void topoSortDfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &visited, stack<int> &st)
{
    visited[node] = 1;

    for (auto it : adj[node])
    {
        int v = it.first;
        if (visited[v] == 0)
        {
            topoSortDfs(v, adj, visited, st);
        }
    }

    st.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    //* create adj list
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v, w});
    }

    //* find the topo sort
    vector<int> visited(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            topoSortDfs(i, adj, visited, st);
        }
    }

    //* calc the distances
    vector<int> distances(n, 1e9);
    distances[0] = 0;
    while (!st.empty())
    {
        int currNode = st.top();
        st.pop();

        for (auto it : adj[currNode])
        {
            int v = it.first;
            int w = it.second;

            if (distances[currNode] + w < distances[v])
            {
                distances[v] = distances[currNode] + w;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (distances[i] == 1e9)
        {
            distances[i] = -1;
        }
    }

    return distances;
}
