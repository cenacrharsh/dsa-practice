#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int negative = 0;
        for (int num : nums)
        {
            // if we find 0, product will always be 0
            if (num == 0)
                return 0;
            if (num < 0)
                negative++;
        }
        if (negative > 0 && negative % 2 != 0)
        {
            // if there are odd number of negative numbers
            return -1;
        }
        else
        {
            // if there are no negative numbers or even number of negative numbers
            return 1;
        }
    }
};