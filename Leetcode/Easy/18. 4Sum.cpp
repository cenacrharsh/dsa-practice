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
> Time Complexity: O()
> Space Complexity: O()
*/

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