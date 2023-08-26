#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=iTBaI90lpDQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=15

//! BFS - Kahn's Algorithm

bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    vector<vector<int>> adj(v);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    //* make a vector of indegree of each node
    vector<int> indegree(v);
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();

        count++;

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

    if (count == v)
    {
        return false;
    }

    return true;
}

// # Tutorial: https://www.youtube.com/watch?v=9twcmtQj4DU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=13

//! DFS

/*
> Time Complexity: O(V + E)
> Space Complexity: O(2E)
*/

bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited)
{
    visited[node] = 1;
    pathVisited[node] = 1;

    //* traverse for adjacent nodes
    for (auto it : adj[node])
    {
        //* when the node is not visited
        if (visited[it] == 0)
        {
            if (dfsCheck(it, adj, visited, pathVisited) == true)
            {
                return true;
            }
        }
        //* the node has been previously visited but it has to be on the same path
        else if (pathVisited[it] == 1)
        {
            return true;
        }
    }

    pathVisited[node] = 0;
    return false;
}

bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    vector<vector<int>> adj(v);
    for (int i = 0; i < edges.size(); i++)
    {
        //* it's a directed graph A -> B
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<int> visited(v, 0);
    vector<int> pathVisited(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            if (dfsCheck(i, adj, visited, pathVisited) == true)
            {
                return true;
            }
        }
    }
    return false;
}
