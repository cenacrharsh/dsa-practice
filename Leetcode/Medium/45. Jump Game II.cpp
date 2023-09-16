#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N^2)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int minJumpsReq[n];
        minJumpsReq[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            int leastOfAllPossibleChoices = INT_MAX;
            if (nums[i] != 0)
            {
                for (int j = 1; j <= nums[i]; j++)
                {
                    if (i + j < n)
                    {
                        leastOfAllPossibleChoices =
                            min(leastOfAllPossibleChoices, minJumpsReq[i + j]);
                    }
                }
            }
            if (leastOfAllPossibleChoices == INT_MAX)
            {
                minJumpsReq[i] = INT_MAX;
            }
            else
            {
                minJumpsReq[i] = leastOfAllPossibleChoices + 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << minJumpsReq[i] << " ";
        }
        cout << endl;
        return minJumpsReq[0];
    }
};