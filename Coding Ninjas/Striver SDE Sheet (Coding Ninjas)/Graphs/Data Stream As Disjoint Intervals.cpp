#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=aBxjDBC4M1U&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=29

/*
> Time Complexity: O(4 alpha)
> Space Complexity: O()
*/

/*
    - Disjoint Set: Helps us to find whether 2 nodes are connected to each other in constant time, where as if we use normal BFS/DFS it will take O(E + V) time
*/

//! Union By Size

class DisjointSetSize
{
    vector<int> size, parent;

public:
    DisjointSetSize(int n)
    {
        size.resize(n + 1, 1);

        parent.resize(n);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        //* attach smaller rank to larger one, it keeps the rank same and hence overall time decreases to find ultimate parent
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

//! Union By Rank

class DisjointSetRank
{
    vector<int> rank, parent;

public:
    DisjointSetRank(int n)
    {
        rank.resize(n + 1, 0);

        parent.resize(n);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        //* attach smaller rank to larger one, it keeps the rank same and hence overall time decreases to find ultimate parent
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main()
{
    DisjointSetRank ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // if 3 and 7 same parent or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not same\n";
    }

    ds.unionByRank(3, 7);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not same\n";
    }

    /*******************************/

    DisjointSetSize ds2(7);
    ds2.unionBySize(1, 2);
    ds2.unionBySize(2, 3);
    ds2.unionBySize(4, 5);
    ds2.unionBySize(6, 7);
    ds2.unionBySize(5, 6);

    // if 3 and 7 same parent or not
    if (ds2.findUltimateParent(3) == ds2.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not same\n";
    }

    ds2.unionBySize(3, 7);

    if (ds2.findUltimateParent(3) == ds2.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not same\n";
    }

    return 0;
}
