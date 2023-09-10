#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Minimum Spanning Tree

// # Tutorial: https://www.youtube.com/watch?v=DMnDM_sxVig&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=29

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1);
        parent.resize(n + 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        //* attach smaller rank to larger one, it keeps the rank same and hence overall time decreases to find ultimate parent
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int node = i;
                int adjNode = it[0];
                int wt = it[1];

                edges.push_back({wt, {node, adjNode}});
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(V);
        int mstWt = 0;

        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUltimateParent(u) != ds.findUltimateParent(v))
            {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};

//! Prim's Algorithm (Uses Greedy Approach)

// # Tutorial: https://www.youtube.com/watch?v=mJcZjjKzeqk&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=28

/*
> Time Complexity: O(E * Log(E)) + O(E * Log(E)) => E * Log(E) (traversal of all edges + traversing all of it's adj nodes)
> Space Complexity: O(E + V)
*/

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int mstSum = 0;

        vector<int> visited(V, 0);

        //* we don't need to store parent node if we only need the sum of MST
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {distance, node}
        pq.push({0, 0});

        while (!pq.empty())
        {
            pair<int, int> curr = pq.top();
            pq.pop();

            int node = curr.second;
            int wt = curr.first;

            if (visited[node] == 1)
            {
                continue;
            }

            //* add not to MST and mark it as visited
            visited[node] = 1;
            mstSum += wt;

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWt = it[1];
                if (visited[adjNode] == 0)
                {
                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return mstSum;
    }
};