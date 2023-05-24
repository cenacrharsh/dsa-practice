#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=wOiDbypgER8

/*
> Time Complexity: O(N)
> Space Complexity: O(N * log(N))
*/

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({nums2[i], nums1[i]});
        }

        // sort the vector in desc order
        sort(v.rbegin(), v.rend());

        long long currSum = 0;
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        // consider first k - 1 elements
        for(int i = 0; i < k - 1; i++) {
            currSum += v[i].second;
            pq.push(v[i].second);
        }

        // consider the rest elements, always keep k elements in currSum and pq
        for(int i = k - 1; i < n; i++) {
            // consider the Kth element
            currSum += v[i].second;
            pq.push(v[i].second);

            ans = max(ans, currSum * v[i].first);

            // remove the smallest element
            currSum -= pq.top();
            pq.pop();
        }

        return ans;
    }
};