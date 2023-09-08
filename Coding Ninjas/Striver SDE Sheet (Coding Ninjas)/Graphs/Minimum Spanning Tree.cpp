#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Prim's Algorithm

// # Tutorial: https://www.youtube.com/watch?v=mJcZjjKzeqk&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=28

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