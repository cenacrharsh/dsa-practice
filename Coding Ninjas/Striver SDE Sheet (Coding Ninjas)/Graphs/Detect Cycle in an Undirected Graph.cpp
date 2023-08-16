#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=BPlrALf1LDU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12

//@ Summation of adj Nodes = Summation of degrees = 2E

//! DFS

/*
> Time Complexity: O(N + 2E) + O(N) -> (traverse all nodes + for loop for visited array)
> Space Complexity: O(N) + O(N) -> (visited array + recursive stack space)
*/

class Graph
{
private:
    bool detect(int source, int parent, vector<int> adj[], int visited[])
    {
        visited[source] = 1;

        for (int adjacentNode : adj[source])
        {
            if (visited[adjacentNode] == 0)
            {
                if (detect(adjacentNode, source, adj, visited) == true)
                {
                    return true;
                }
            }
            else if (adjacentNode != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    bool detectCycle(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (visited[i] != 1)
            {
                if (detect(i, -1, adj, visited) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//! BFS

/*
> Time Complexity: O(N + 2E) + O(N)
> Space Complexity: O(N) + O(N)
*/
class Graph
{
private:
    bool detect(int source, vector<int> adj[], int visited[])
    {
        visited[source] = 1;
        queue<pair<int, int>> nodesLeft;
        nodesLeft.push({source, -1});

        while (!nodesLeft.empty())
        {
            int currNode = nodesLeft.front().first;
            int parentNode = nodesLeft.front().second;
            nodesLeft.pop();

            //* traverse all connected nodes
            for (auto adjacentNodes : adj[currNode])
            {
                //* if node is not visited we mark it and push it into queue, else if it's visited already and not the parentNode we have found our cycle
                if (!visited[adjacentNodes])
                {
                    visited[adjacentNodes] = 1;
                    nodesLeft.push({adjacentNodes, currNode});
                }
                else if (adjacentNodes != parentNode)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool detectCycle(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (detect(i, adj, visited) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};