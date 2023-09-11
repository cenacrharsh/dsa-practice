#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=j1QDfU21iZk&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=30

/*
    - Articulation Point: Nodes on whose removal, the graph breaks into multiple components

    - tin[]: store the time of insertion during DFS

    - low[]: min of all the adjacent nodes apart from parent and visited nodes
*/

/*
> Time Complexity: O(V + 2E) + O(N)
> Space Complexity: O(3N)
*/

class Solution
{
private:
    int timer = 0;

private:
    void dfs(int node, int parent, vector<int> &visited, vector<int> adj[], vector<int> &tin, vector<int> &low, vector<int> &mark)
    {
        visited[node] = 1;

        tin[node] = low[node] = timer;
        timer++;

        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
            {
                continue;
            }

            if (!visited[it])
            {
                dfs(it, node, visited, adj, tin, low, mark);

                //* once dfs is finished we update the low
                low[node] = min(low[node], low[it]);

                //* check if it's an articulation point
                if (low[it] >= tin[node] && parent != -1)
                {
                    //* we use >= because even if == then no use as node is about to be removed so only if value is less we can reach before it else we can't
                    mark[node] = 1;
                }

                //* count unvisited children
                child++;
            }
            else
            {
                //* if node is already visited then we can't take it's low as we came via that path and once removed we can't go back through the same node to reach it's previous nodes hence we use tin
                low[node] = min(low[node], tin[it]);
            }
        }

        //* for starting nodes they can only become articulation points if they have multiple children
        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> tin(V, 0);
        vector<int> low(V, 0);
        vector<int> mark(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1, visited, adj, tin, low, mark);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (mark[i] == 1)
            {
                ans.push_back(i);
            }
        }

        if (ans.size() == 0)
        {
            return {-1};
        }

        return ans;
    }
};
