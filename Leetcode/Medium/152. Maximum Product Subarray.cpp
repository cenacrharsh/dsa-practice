#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimal

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        //* all +ve -> entire subarray is the answer
        //* even no. of -ves -> entire subarray is the answer
        //* odd no. of -ves exist -> we'll skip one negative no. which seprates the array basically into 2 halves, prefix and suffix, one will be the answer
        //* has 0's -> 0's also divide the array into prefix and suffix, we don't carry over 0's and as soon as 0 comes we start again from 1

        int ans = INT_MIN;
        int prefixProduct = 1, suffixProduct = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (prefixProduct == 0)
                prefixProduct = 1;
            if (suffixProduct == 0)
                suffixProduct = 1;

            prefixProduct *= nums[i];
            suffixProduct *= nums[nums.size() - 1 - i];

            ans = max(ans, max(prefixProduct, suffixProduct));
        }
        return ans;
    }
};

//! Better, 2 for loops

/*
> Time Complexity: O(N^2)
> Space Complexity: O(1)
*/

//! Brute Force, 3 for loops

/*
> Time Complexity: O(N^3)
> Space Complexity: O(1)
*/
