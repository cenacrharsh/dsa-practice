#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial:https://www.youtube.com/watch?v=R_Mfw4ew-Vo&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=20

/*
> Time Complexity: O(N log(N)) + O(log (max - min)) * O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int canWePlace(vector<int> &stalls, int k, int minDistance)
    {
        int cows = 1, last = stalls[0];
        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - last >= minDistance)
            {
                cows++;
                last = stalls[i];
            }

            if (cows >= k)
            {
                return 1;
            }
        }
        return 0;
    }

    //* low starts from possible values, high starts from not possible values
    int solve(int n, int k, vector<int> &stalls)
    {
        //* min distance b/w 2 cows is 1
        //* max distance b/w 2 cows is (max - min)

        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls[n - 1] - stalls[0];
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int isPossible = canWePlace(stalls, k, mid);
            if (isPossible == 1)
            {
                low = mid + 1; //* we need max possible value
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }
};
