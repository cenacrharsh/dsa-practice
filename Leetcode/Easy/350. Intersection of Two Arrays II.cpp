#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=6YqavhaTQLc

//! 2 Pointers

/*
> Time Complexity: O(N * Log(N) + M * Log(M))
> Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> ans;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            } else if(nums1[i] < nums2[j]) {
                i++;
            } else if(nums1[i] > nums2[j]) {
                j++;
            }
        }
        return ans;
    }
};

//! Hashmap

/*
> Time Complexity: O(N + M)
> Space Complexity: O(N + M)
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> freq1;
        map<int, int> freq2;
        for(int i : nums1)
        {
            freq1[i]++;
        }
        for(int i : nums2)
        {
            freq2[i]++;
        }
        vector<int> ans;
        for(auto i : freq1)
        {
            if(freq2.find(i.first) != freq2.end())
            {
                int count1 = i.second;
                int count2 = freq2[i.first];
                int count = min(count1, count2);
                while(count--)
                {
                    ans.push_back(i.first);
                }
            }
        }
        return ans;
    }
};