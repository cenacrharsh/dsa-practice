#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        long long sum = 0;
        long long maxSum = LONG_MIN; // maximum sum

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (sum > maxSum)
            {
                maxSum = sum;
            }

            // if if sum < 0, discard the sum calculated
            if (sum < 0)
            {
                sum = 0;
            }
        }
        // if ques says to consider empty subarray, i.e when all array elements are negative, depends on ques if negative sum is asked or empty subarray i.e 0 sum is to be considered
        // if(maxSum < 0) {
        //     maxSum = 0;
        // }

        return maxSum;
    }
};

//! Print max subarray elements
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        long long sum = 0;
        long long maxSum = LONG_MIN; // maximum sum

        int start = 0;
        int ansStart = -1, ansEnd = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (sum == 0)
            {
                start = i; // starting index
            }

            if (sum > maxSum)
            {
                maxSum = sum;

                ansStart = start;
                ansEnd = i;
            }

            // if if sum < 0, discard the sum calculated
            if (sum < 0)
            {
                sum = 0;
            }
        }

        //* printing the subarray:
        cout << "The subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++)
        {
            cout << nums[i] << " ";
        }
        cout << "]" << endl;

        // if ques says to consider empty subarray, i.e when all array elements are negative, depends on ques if negative sum is asked or empty subarray i.e 0 sum is to be considered
        // if(maxSum < 0) {
        //     maxSum = 0;
        // }

        return maxSum;
    }
};