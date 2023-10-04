#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=qyfekrNni90&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=13

/*
> Time Complexity: O(log (max Element) base 2) * O(N) => search space lies in b/w 1 and maxElement * every time we traverse the piles array given of size N
> Space Complexity: O(1)
*/

//* how to figure out whether low/high is containing the ans -> low starts at not possible values while high starts at possible values and when BS ends both end up at opposite polarity hence low contains the answer
class Solution
{
public:
    int findMax(vector<int> &piles)
    {
        int maxElement = INT_MIN;
        for (int i = 0; i < piles.size(); i++)
        {
            maxElement = max(maxElement, piles[i]);
        }
        return maxElement;
    }

    int calcHours(vector<int> &piles, int speed, int h)
    {
        //* return 1 if <= h else return 0 to handle overflow
        long long timeRequired = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            timeRequired += ceil((double)piles[i] / (double)speed);
            if (timeRequired > h)
            {
                return 0;
            }
        }
        return 1;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        //* min I can eat is 1 banana/hr
        //* max I need to eat is max(piles) banana/hr as any higher number won't make any difference to our answer

        sort(piles.begin(), piles.end());
        int low = 1, high = findMax(piles);
        int ans = high;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int isPossible = calcHours(piles, mid, h);
            if (isPossible == 1)
            {
                ans = mid;
                high = mid - 1; //* since we need lowest possible value
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
