#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > ans.back())
        {
            ans.push_back(arr[i]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }
    return ans.size();
}
