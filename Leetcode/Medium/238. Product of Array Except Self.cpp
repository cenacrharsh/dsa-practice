#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        int prod = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            prefix[i] = prod;
            prod = prod * nums[i];
        }
        prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            suffix[i] = prod;
            prod = prod * nums[i];
        }
        vector<int> ans(n);
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};