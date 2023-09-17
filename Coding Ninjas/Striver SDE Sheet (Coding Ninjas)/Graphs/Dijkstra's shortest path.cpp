#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
    - Dijkstra's Algorithm won't work for negative edge weights as in case of negative edge weights the values of paths keeps decreasing every time and infinite loop occurs in such a case
*/

// # Tutorial: https://www.youtube.com/watch?v=PATgNiuTP20

//! Using Set

/*
    in PQ we don't have erase operation but in sets we do so we can erase already existing paths which we know are going to take longer for eg. if {8, 5} is about to be inserted but a {10, 5} already exists so we know that when {10, 5} is going to come later it won't effect the results as a lower distance of {8, 5} has already come so we can easily remove it from set and save some iterations but set.erase() also in logarithmic time so overall time complexity can be said to be same
*/

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    vector<vector<pair<int, int>>> adj(vertices);
    for (int i = 0; i < edge.size(); i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> distances(vertices, 1e9);
    distances[source] = 0;

    //* declare a set
    set<pair<int, int>> s;
    s.insert({0, source});

    while (!s.empty())
    {
        auto it = *(s.begin());
        int dist = it.first;
        int currNode = it.second;
        s.erase(it);

        for (auto it : adj[currNode])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (dist + edgeWeight < distances[adjNode])
            {
                //* erase previously existing weigth if any
                if (distances[adjNode] != 1e9)
                {
                    s.erase({distances[adjNode], adjNode});
                }
                distances[adjNode] = dist + edgeWeight;
                s.insert({distances[adjNode], adjNode});
            }
        }
    }

    return distances;
}

// # Tutorial: https://www.youtube.com/watch?v=V6H1qAeB-l4&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=21

//! Using Priority Queue

/*
    won't work for negative edge weights as in case of negative edge weights
    the values of paths keeps decreasing every time and infinite loop occurs
*/

/*
> Time Complexity: O(E * Log(V))
> Space Complexity: O()
*/

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    vector<vector<pair<int, int>>> adj(vertices);
    for (int i = 0; i < edge.size(); i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> distances(vertices, 1e9);
    distances[source] = 0;

    //* declare a min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        for (auto it : adj[currNode])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (dist + edgeWeight < distances[adjNode])
            {
                distances[adjNode] = dist + edgeWeight;
                pq.push({distances[adjNode], adjNode});
            }
        }
    }

    return distances;
}