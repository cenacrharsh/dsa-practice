#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=WAOfKpxYHR8&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=17

/*
> Time Complexity: O()
> Space Complexity: O()
*/

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        //* prerequisites[i] = [ai, bi] => bi -> ai
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
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
                indegree[it]--;

                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        if (ans.size() == numCourses)
        {
            return ans;
        }

        // ans.resize(0);
        return {};
    }
};