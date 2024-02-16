#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Priority Queue

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < arr.size(); i++)
        {
            freq[arr[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto [num, count] : freq)
        {
            pq.push({count, num});
        }
        while (k > 0)
        {
            pair<int, int> top = pq.top();
            pq.pop();
            if (k >= top.first)
            {
                k = k - top.first;
            }
            else
            {
                k = 0;
                pq.push({top.first - k, top.second});
            }
            /*
                if(k < top.first) {
                    pq.push({top.first - k, top.second});
                }
                k = k - top.first;
            */
        }
        return pq.size();
    }
};