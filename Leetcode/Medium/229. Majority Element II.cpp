// # Tutorial: https://www.youtube.com/watch?v=yDbkQd9t2ig

//> only two element can be majority element as only two element can occur more than n / 3 times

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

//! Approach 1 - Boyer Moore Voting Algo

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int size = nums.size();
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;

        for (int i = 0; i < size; i++)
        {
            if (nums[i] == num1)
            {
                count1++;
            }
            else if (nums[i] == num2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        // it's not guranteed that there is a majority element present
        vector<int> ans;
        count1 = 0;
        count2 = 0;

        for (int i = 0; i < size; i++)
        {
            if (nums[i] == num1)
            {
                count1++;
            }
            else if (nums[i] == num2)
            {
                count2++;
            }
        }

        if (count1 > size / 3)
        {
            ans.push_back(num1);
        }
        if (count2 > size / 3)
        {
            ans.push_back(num2);
        }
        return ans;
    }
};