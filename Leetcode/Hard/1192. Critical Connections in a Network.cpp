#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=qrAub5z8FeA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=29

/*
> Time Complexity: O(V + 2E) => time complexity of DFS
> Space Complexity: O(V + 2E) + O(3N)
*/

class Solution
{
private:
    int timer = 0;

private:
    void dfs(int node, int parent, vector<int> &visited, vector<vector<int>> &adj, vector<int> &timeIn, vector<int> &lowestReachableNode, vector<vector<int>> &bridges)
    {
        visited[node] = 1;

        timeIn[node] = lowestReachableNode[node] = timer;
        timer++;

        for (auto it : adj[node])
        {
            if (it == parent)
            {
                continue;
            }

            if (visited[it] == 0)
            {
                dfs(it, node, visited, adj, timeIn, lowestReachableNode, bridges);
                lowestReachableNode[node] = min(lowestReachableNode[node], lowestReachableNode[it]);

                //* check if the connection can be a bridge
                if (lowestReachableNode[it] > timeIn[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                lowestReachableNode[node] = min(lowestReachableNode[node], lowestReachableNode[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        vector<int> timeIn(n, 0);
        vector<int> lowestReachableNode(n, 0);
        vector<vector<int>> bridges;

        dfs(0, -1, visited, adj, timeIn, lowestReachableNode, bridges);
        return bridges;
    }
};