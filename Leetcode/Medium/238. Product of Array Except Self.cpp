#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//! No Extra Arrays

/*
> Time Complexity: O(2N)
> Space Complexity: O(1) => not counting extra space
*/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        ans[0] = 1;

        //* first ans[i] would contain product of all numbers from index 0->(i-1)
        for (int i = 1; i < nums.size(); i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        //* now we'll multiply product of all numbers from index (i+1)->(n-1) to ans[i]
        int prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ans[i] = ans[i] * prod;
            prod = prod * nums[i];
        }

        return ans;
    }
};

//! 2 Extra Arrays

/*
> Time Complexity: O(3N)
> Space Complexity: O(2N)
*/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n); //* prefix[i] = product of all number from index 0->(i-1)
        vector<int> suffix(n); //* suffix[i] = product of all number from index (i+1)->(n-1)
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