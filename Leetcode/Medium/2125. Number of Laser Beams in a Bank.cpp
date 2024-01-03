#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(M * N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int prev = 0, ans = 0;
        for (string row : bank)
        {
            int curr = 0;
            for (char col : row)
            {
                if (col == '1')
                {
                    curr++;
                }
            }
            ans += (prev * curr);
            if (curr > 0)
            {
                prev = curr;
            }
            curr = 0;
        }
        return ans;
    }
};