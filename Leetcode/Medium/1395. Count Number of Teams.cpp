#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=zONHzIqCr-o

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        //* for each element we'll calculate the number of elements that'll go to it's left and to it's right in both asc and desc order then we sum it up

        int n = rating.size();
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            //* asc order
            int leftSmaller = 0, rightLarger = 0;
            for (int j = 0; j < i; j++)
            {
                if (rating[j] < rating[i])
                {
                    leftSmaller++;
                }
            }
            for (int k = i + 1; k < n; k++)
            {
                if (rating[k] > rating[i])
                {
                    rightLarger++;
                }
            }
            ans += leftSmaller * rightLarger;

            //* desc order
            int leftLarger = i - leftSmaller;
            int rightSmaller = (n - i - 1) - rightLarger;
            ans += leftLarger * rightSmaller;
        }
        return ans;
    }
};