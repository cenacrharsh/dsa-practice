#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=upgnDo9eA-k

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int flips = 0;
        while (a > 0 || b > 0 || c > 0)
        {
            int bitA = a & 1;
            int bitB = b & 1;
            int bitC = c & 1;

            if ((bitA | bitB) != bitC)
            {
                if (bitC == 1)
                {
                    flips++;
                }
                else
                {
                    flips += (bitA + bitB); //* in case of 1 and 0, we need one flip, in case of 1 and 1 we need 2 flips, so basically we add 1 + 0 = 1 and 1 + 1 = 2
                }
            }

            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return flips;
    }
};