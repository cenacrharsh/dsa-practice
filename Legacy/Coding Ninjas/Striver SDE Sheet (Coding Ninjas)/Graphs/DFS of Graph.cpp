#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Qzf1a--rhp8&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=5

/*
> Time Complexity: O(N) + O(2E)
> Space Complexity: O(3N) => dfs, visited and recursion stack space
*/

void helper(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &temp)
{
    visited[node] = 1;
    temp.push_back(node);

    // traverse all it's neighbours
    for (auto it : adj[node])
    {
        if (visited[it] != 1)
        {
            helper(it, adj, visited, temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<vector<int>> dfs;
    vector<int> visited(V, 0);

    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] != 1)
        {
            vector<int> temp;
            helper(i, adj, visited, temp);
            dfs.push_back(temp);
        }
    }

    return dfs;
}