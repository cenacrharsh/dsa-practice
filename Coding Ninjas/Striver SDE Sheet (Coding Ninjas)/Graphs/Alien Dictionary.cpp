#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=U3N_je7tWAs&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=17

class Solution
{
public:
    vector<int> topologicalSort(vector<int> adj[], int V)
    {
        // make a vector of indegree of each node
        vector<int> indegree(V);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int currNode = q.front();
            q.pop();

            topo.push_back(currNode);

            for (auto it : adj[currNode])
            {
                // remove the link of currNode from each of it's connected node
                indegree[it]--;

                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return topo;
    }

    string findOrder(string dictionary[], int N, int K)
    {
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dictionary[i];
            string s2 = dictionary[i + 1];
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topoSort = topologicalSort(adj, K);
        string ans = "";
        for (auto it : topoSort)
        {
            ans = ans + char(it + 'a');
        }
        return ans;
    }
};