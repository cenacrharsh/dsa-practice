#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=-vu34sct1g8&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=11

class Solution
{
public:
    bool check(int start, vector<vector<int>> &graph, vector<int> &color)
    {
        queue<int> nodesLeft;
        nodesLeft.push(start);
        color[start] = 0;

        while (!nodesLeft.empty())
        {
            int currNode = nodesLeft.front();
            nodesLeft.pop();

            for (auto it : graph[currNode])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[currNode];
                    nodesLeft.push(it);
                }
                else if (color[it] == color[currNode])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> color(V, -1);

        //* check for each graph component
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (check(i, graph, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};