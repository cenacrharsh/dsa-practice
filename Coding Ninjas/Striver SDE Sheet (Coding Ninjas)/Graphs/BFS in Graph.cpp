#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=-tgVpUgsQ5k&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=5

/*
> Time Complexity: O(V) + O(2E) => V = Vertices & E = Edges
> Space Complexity: O()
*/

//- Total degree of graph = 2E (as each edge is associated with 2 nodes)
//- V * D = E

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    vector<int> visited(n, 0);
    visited[0] = 1;

    queue<int> nodesLeft;
    nodesLeft.push(0);

    vector<int> bfs;
    while (!nodesLeft.empty())
    {
        int currNode = nodesLeft.front();
        nodesLeft.pop();
        bfs.push_back(currNode);
        for (auto it : adj[currNode])
        {
            if (visited[it] != 1)
            {
                visited[it] = 1;
                nodesLeft.push(it);
            }
        }
    }
    return bfs;
}