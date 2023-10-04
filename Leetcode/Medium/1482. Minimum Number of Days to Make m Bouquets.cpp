#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=TXAuxeYBTdg&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=14

/*
> Time Complexity: O(N) * O(log (max - min + 1) base 2) => possibility check * minBloomingDay -> maxBloomingDay
> Space Complexity: O(1)
*/

class Solution
{
public:
    pair<int, int> findMinMax(vector<int> &bloomDay)
    {
        int minElement = INT_MAX, maxElement = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            minElement = min(minElement, bloomDay[i]);
            maxElement = max(maxElement, bloomDay[i]);
        }
        return make_pair(minElement, maxElement);
    }

    int countBouquets(vector<int> &bloomDay, int m, int k, int currDay)
    {
        int numBouquets = 0;
        int numConsecutive = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            //* flower bloomed
            if (currDay >= bloomDay[i])
            {
                numConsecutive++;
            }
            else
            {
                numBouquets = numBouquets + (numConsecutive / k);
                numConsecutive = 0;
            }

            if (numBouquets >= m)
            {
                return 1;
            }
        }
        numBouquets = numBouquets + (numConsecutive / k);
        return numBouquets >= m;
    }

    //* low starts at not possible values while high starts at possible values
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        //* minimum days required -> min(bloomDay)
        //* maximum days required -> max(bloomDay)

        long long flowersRequired = m * 1LL * k * 1LL;
        if (flowersRequired > bloomDay.size())
        {
            return -1;
        }

        pair<int, int> minMaxElem = findMinMax(bloomDay);
        int low = minMaxElem.first, high = minMaxElem.second;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int isPossible = countBouquets(bloomDay, m, k, mid);
            if (isPossible == 1)
            {
                high = mid - 1; //* as we want min num of days
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
