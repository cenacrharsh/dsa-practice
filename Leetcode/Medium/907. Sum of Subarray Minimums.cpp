#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Ulb3ixSpE4Y

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

//! Monotonic Stack
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<pair<int, int>> s1, s2;
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            while (!s1.empty() && (s1.top().first) > arr[i])
            {
                count += s1.top().second;
                s1.pop();
            }
            s1.push({arr[i], count});
            left[i] = count;
        }
        //* to handle duplicate we use = in either left or right
        for (int i = n - 1; i >= 0; i--)
        {
            int count = 1;
            while (!s2.empty() && (s2.top().first) >= arr[i])
            {
                count += s2.top().second;
                s2.pop();
            }
            s2.push({arr[i], count});
            right[i] = count;
        }
        long sum = 0;
        for (int i = 0; i < n; i++)
        {
            long temp = (left[i] * right[i]) % 1000000007;
            sum += arr[i] * temp;
        }
        return (int)(sum % 1000000007);
    }
};

// # TLE
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int mod = 1000000007;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int minimum = INT_MAX;
            for (int j = i; j < arr.size(); j++)
            {
                if (arr[j] < minimum)
                {
                    minimum = arr[j];
                }
                // minimum = min(minimum, arr[j]);
                sum = (sum + minimum) % mod;
                // for(int k = i; k <= j; k++) {
                //     cout << arr[k] << " ";
                // }
                // cout << " = " << minimum << endl;
            }
        }
        return sum;
    }
};