#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=MG-Ac4TAvTY&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=16

/*
> Time Complexity: O(log (sum - max + 1)) * O(N) => range is sum - max + 1
> Space Complexity: O(1)
*/

class Solution
{
public:
    // pair<int, int> totalSumAndMaxWeight(vector<int> &weights) {
    //     int sum = 0;
    //     int maxWt = INT_MIN;
    //     for(int i = 0; i < weights.size(); i++) {
    //         sum += weights[i];
    //         maxWt = max(maxWt, weights[i]);
    //     }
    //     return make_pair(maxWt, sum);
    // }

    int calcDays(vector<int> &weights, int capacity)
    {
        int days = 1;
        int load = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (load + weights[i] > capacity)
            {
                days++;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }

    //* low starts from not possible values while high starts from possible values
    int shipWithinDays(vector<int> &weights, int days)
    {
        //* min capcaity = max(weights) as anything lesser and we won't be able to ship the container of max wt
        //* max capacity = sum total of all weights so that we can ship them all at once

        // pair<int, int> val = totalSumAndMaxWeight(weights);
        // int low = val.first, high = val.second;

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int daysReq = calcDays(weights, mid);
            if (daysReq <= days)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};