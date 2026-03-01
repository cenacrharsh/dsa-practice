#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimal

/*
> Time Complexity: O(N * Log(N)) + O(N^2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        //* use 4 pointers, fix 2 i and j, and use 2 pointers to move
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k] + nums[l];
                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else if (sum > target)
                    {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};

//! Better

/*
> Time Complexity: O(N^3 * Log(M)) => M is size of hashset
> Space Complexity: O(N) + O(quads) * 2
*/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                set<int> hashSet;
                for (int k = j + 1; k < nums.size(); k++)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long targetLeft = target - sum;
                    if (hashSet.find(targetLeft) != hashSet.end())
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)targetLeft};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//! Brute Force

/*
> Time Complexity: O(N^4)
> Space Complexity: O()
*/