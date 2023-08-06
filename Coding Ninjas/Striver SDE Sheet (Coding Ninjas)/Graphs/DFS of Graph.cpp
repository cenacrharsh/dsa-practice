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

void helper(int node, vector<int> adj[], vector<int> &visited, vector<int> &dfs)
{
    visited[node] = 1;
    dfs.push_back(node);

    // traverse all it's neighbours
    for (auto it : adj[node])
    {
        if (visited[it] != 1)
        {
            helper(it, adj, visited, dfs);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> dfs;

    int start = 0;
    helper(start, adj, visited, dfs);
    return dfs;
}
