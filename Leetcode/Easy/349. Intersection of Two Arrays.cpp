#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1(begin(nums1), end(nums1));
        unordered_set<int> set2(begin(nums2), end(nums2));
        vector<int> ans;
        for (auto i : set1)
        {
            if (set2.find(i) != set2.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};