#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Max Heap

/*
> Time Complexity: O(N * Log(N)) + O(N^2 * Log(K))
> Space Complexity: O(K)
*/

class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<pair<double, pair<int, int>>> pq; //* max heap of fraction -> [i, j]
        sort(arr.begin(), arr.end());
        //* O(N^2 * Log(K)) -> each operation on PQ takes Log(K) time
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                pq.push({(double)arr[i] / (double)arr[j], {i, j}});
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
        }
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};