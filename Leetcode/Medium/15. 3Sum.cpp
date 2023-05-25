#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=onLoX6Nhvmg

//! 2 pointers

/*
> Time Complexity: O(N^2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if ((i == 0) || (i > 0 && nums[i] != nums[i - 1]))
            {
                int l = i + 1;
                int r = nums.size() - 1;
                int targetSum = 0 - nums[i];
                while (l < r)
                {
                    vector<int> temp;
                    if (nums[l] + nums[r] == targetSum)
                    {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
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
                    else if (nums[l] + nums[r] < targetSum)
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