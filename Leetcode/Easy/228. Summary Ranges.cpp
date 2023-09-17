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
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            int start = nums[i];

            //* Keep iterating until the next element is one more than the current element
            while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1])
            {
                i++;
            }

            if (start != nums[i])
            {
                ans.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
            else
            {
                ans.push_back(to_string(start));
            }
        }
        return ans;
    }
};