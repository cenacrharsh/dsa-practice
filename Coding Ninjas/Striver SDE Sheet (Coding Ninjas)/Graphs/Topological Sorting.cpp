#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=5lZ0iJMrUMk&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=15

//@ Topological Sort - Liner ordering of elements such that if there is an edge between u and v, u appears before v in that ordering - Only possible in DIRECTED ACYCLIC GRAPH

void dfsCheck(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st)
{
    visited[node] = 1;

    for (auto it : adj[node])
    {
        if (visited[it] == 0)
        {
            dfsCheck(it, adj, visited, st);
        }
    }

    //* we push in stack only after the dfs of all nodes after it is completed
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{
    vector<vector<int>> adj(nodes);
    for (int i = 0; i < graph.size(); i++)
    {
        adj[graph[i][0]].push_back(graph[i][1]);
    }

    vector<int> visited(nodes, 0);
    stack<int> st;
    for (int i = 0; i < nodes; i++)
    {
        if (visited[i] == 0)
        {
            dfsCheck(i, adj, visited, st);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}
