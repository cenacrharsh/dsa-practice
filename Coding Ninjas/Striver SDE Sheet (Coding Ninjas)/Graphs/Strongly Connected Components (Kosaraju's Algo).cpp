#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=R6uoSjZ2imo&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=29

/*
> Time Complexity: O(V+E) + O(V+E) + O(V+E) ~ O(V+E)
> Space Complexity: O(V) + O(V) + O(V+E)
*/

class Solution
{
private:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, stack<int> &st)
    {
        visited[node] = 1;

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, visited, adj, st);
            }
        }

        st.push(node);
    }

private:
    void dfs2(int node, vector<int> &visited, vector<vector<int>> &adjT)
    {
        visited[node] = 1;

        for (auto it : adjT[node])
        {
            if (!visited[it])
            {
                dfs2(it, visited, adjT);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        //* sort all the edges aq to finishing time
        vector<int> visited(V, 0);
        stack<int> st;

        //> O(V + E)
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, adj, st);
            }
        }

        //* reverse the graph
        vector<vector<int>> adjTranspose(V);

        //> O(V + E)
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
            for (auto j : adj[i])
            {
                // currently existing edge b/w i -> j
                adjTranspose[j].push_back(i);
            }
        }

        //* do a dfs on reversed graph
        int scc = 0;

        //> O(V + E)
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!visited[node])
            {
                scc++;
                dfs2(node, visited, adjTranspose);
            }
        }
        return scc;
    }
};
