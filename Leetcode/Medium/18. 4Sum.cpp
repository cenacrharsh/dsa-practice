#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=eD95WRfh81c&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=36

/*
> Time Complexity: O(N^3)
> Space Complexity: O(1)
*/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1;
                int r = n - 1;
                while (l < r)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[l];
                    sum += nums[r];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[l], nums[r]};
                        ans.push_back(temp);

                        while (l < r && nums[l] == nums[l + 1])
                        {
                            l++;
                        }
                        while (l < r && nums[r] == nums[r - 1])
                        {
                            r--;
                        }
                        l++;
                        r--;
                    }
                    else if (sum < target)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};