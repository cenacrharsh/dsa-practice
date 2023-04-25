#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Multimap

/*
> Time Complexity: O(N * log(N))
> Space Complexity: O(N)
*/

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // multimap is sorted in asc order aq to key
        multimap<int, int> mmap; // key:dist, value:index
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            mmap.insert({x * x + y * y, i});
        }
        vector<vector<int>> ans;
        // store first k points from mmap into ans vector
        int count = 0;
        for (auto it = mmap.begin(); count < k; it++, count++)
        {
            ans.push_back(points[it->second]);
        }
        return ans;
    }
};

//! Using Priority Queue

/*
> Time Complexity: O(N * log(K))
> Space Complexity: O(K) => since only K elements maintained in heap
*/

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        priority_queue<vector<int>> maxHeap; // max heap
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            maxHeap.push({(x * x + y * y), x, y}); // doing sqrt won't change distance
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        while (!maxHeap.empty())
        {
            vector<int> coordinate = maxHeap.top();
            ans.push_back({coordinate[1], coordinate[2]});
            maxHeap.pop();
        }
        return ans;
    }
};

//! Using Vector of Pairs

/*
> Time Complexity: O(N * NlogN)
> Space Complexity: O(N)
*/

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<pair<int, pair<int, int>>> v;

        // find all euclidean distances
        for (auto &it : points)
        {
            int dist = (it[0] * it[0] + it[1] * it[1]);
            v.push_back({dist, {it[0], it[1]}});
        }

        // sort in asc order aq distance
        sort(v.begin(), v.end());

        vector<vector<int>> ans(k);
        for (int i = 0; i < k; i++)
        {
            ans[i].push_back(v[i].second.first);
            ans[i].push_back(v[i].second.second);
        }

        return ans;
    }
};