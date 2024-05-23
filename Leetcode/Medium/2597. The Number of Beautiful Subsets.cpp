#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=014NzNPJNbY

//! Using Unordered Map
class Solution {
public:
    int dfs(vector<int>& nums, int k, int index, unordered_map<int, int> &mp) {
        if(index == nums.size()) {
            return 1;
        }

        int taken = 0;
        //* check if we can take that element, ques says that only those elements whose absolute difference isn't = k are allowed to be in the set so we check if (num +/- k) already exists in the hashmap, if it doesn't we can include that element in the subset else we can't
        if(mp[nums[index] - k] == 0 && mp[nums[index] + k] == 0) {
            //* add the element to the map
            mp[nums[index]]++;
            taken = dfs(nums, k, index + 1, mp);

            //* remove the element from the map for not taken cases
            mp[nums[index]]--;
        }
        int notTaken = dfs(nums, k, index + 1, mp);
        return taken + notTaken;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = dfs(nums, k, 0, mp);
        return ans - 1; //* to exclude empty subset
    }
};