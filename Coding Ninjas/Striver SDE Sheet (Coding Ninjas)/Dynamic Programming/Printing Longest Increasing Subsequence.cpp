#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=21

#include <bits/stdc++.h>
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n)
{
    vector<int> dp(n, 1); //* default maxLen at each index is 1
    vector<int> hash(n);
    int lastIndex = 0;
    int maxLen = 1;
    for (int curr = 0; curr < n; curr++)
    {
        hash[curr] = curr; //* default prevIndex for each index is itself

        for (int prev = 0; prev < curr; prev++)
        {
            if (arr[prev] < arr[curr] && 1 + dp[prev] > dp[curr])
            {
                dp[curr] = 1 + dp[prev];
                hash[curr] = prev;
            }
        }

        if (dp[curr] > maxLen)
        {
            maxLen = dp[curr];
            lastIndex = curr;
        }
    }

    vector<int> ans;
    ans.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
