#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//@ Topological Sort - Liner ordering of elements such that if there is an edge between u and v, u appears before v in that ordering - Only possible in DIRECTED ACYCLIC GRAPH

// # Tutorial: https://www.youtube.com/watch?v=73sneFXuTEg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=14

//! BFS - Kahn's Algorithm

/*
> Time Complexity: O(V + E)
> Space Complexity: O(2V)
*/

#include <bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{
    vector<vector<int>> adj(nodes);
    for (int i = 0; i < graph.size(); i++)
    {
        adj[graph[i][0]].push_back(graph[i][1]);
    }

    //* make a vector of indegree of each node
    vector<int> indegree(nodes);
    for (int i = 0; i < nodes; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < nodes; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();

        ans.push_back(currNode);

        for (auto it : adj[currNode])
        {
            //* remove the link of currNode from each of it's connected node
            indegree[it]--;

            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return ans;
}

// # Tutorial: https://www.youtube.com/watch?v=5lZ0iJMrUMk&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=15

//! DFS

/*
> Time Complexity: O(V + E)
> Space Complexity: O(2V)
*/

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
