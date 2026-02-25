#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Sliding Window

/*
> Time Complexity: O(2 * K)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int leftSum = 0, rightSum = 0, maxSum = 0;
        for (int i = 0; i < k; i++)
        {
            leftSum += cardPoints[i];
        }
        maxSum = max(maxSum, leftSum);
        int rightIndex = cardPoints.size() - 1;
        for (int i = k - 1; i >= 0; i--)
        {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIndex];
            rightIndex--;
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};