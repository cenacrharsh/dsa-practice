#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimal, XOR

/*
> Time Complexity: ~O(N^2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        //* (XOR of all numbers in grid) ^ (XOR of all numbers from 1 -> N) = X ^ Y
        //* find the first differentiating bit in X and Y, we'll pick the first one from right
        //* find the first differentiating bit in X and Y, we'll pick the first one from right
        //* seggregate all the numbers in grid and from 1->N into one of the 2 groups, one having 1 at the  bit while the other having 0 at the differentiating bit, now xor each group independently to get x and y, since after using all numbers form grid and 1->N each no. occurs twice except repeating one which comes thrice and missing which comes once i.e odd occurences all other no. are cancelled out and since both x and y were in separate groups what we have left is the ans

        int n = grid.size() * grid.size();
        int xr = 0;
        for (int i = 1; i <= n; i++)
        {
            xr ^= i;
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                xr ^= grid[i][j];
            }
        }

        int differentiatingBitNo = 0;
        while (1)
        {
            if ((xr & (1 << differentiatingBitNo)) != 0)
            {
                break;
            }
            differentiatingBitNo++;
        }

        int zeroGroup = 0, oneGroup = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((i & (1 << differentiatingBitNo)) != 0)
            {
                oneGroup ^= i;
            }
            else
            {
                zeroGroup ^= i;
            }
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if ((grid[i][j] & (1 << differentiatingBitNo)) != 0)
                {
                    oneGroup ^= grid[i][j];
                }
                else
                {
                    zeroGroup ^= grid[i][j];
                }
            }
        }

        int cntZeroGroup = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == zeroGroup)
                {
                    cntZeroGroup++;
                }
            }
        }
        if (cntZeroGroup == 2)
            return {zeroGroup, oneGroup};
        else
            return {oneGroup, zeroGroup};
    }
};

//! Optimal, Mathematics

/*
> Time Complexity: O(N^2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        //* S - Sn = (X - Y)
        //* S^2 - S^2n => (X^2 - Y^2) = (X + Y)(X - Y) => X + Y = (S^2 - S^2n) / (X - Y)
        //* 2X = (S - Sn) + (S^2 - S^2n) / (X - Y)

        int n = grid.size() * grid.size();
        long long S = 0, Sn = 0, S2 = 0, S2n = 0;

        Sn = (n * (n + 1)) / 2;
        S2n = ((long long)n * (long long)(n + 1) * (long long)(2 * n + 1)) / 6;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                S += grid[i][j];
                S2 += (long long)grid[i][j] * (long long)grid[i][j];
            }
        }

        int val1 = S - Sn;
        int val2 = S2 - S2n;
        val2 = val2 / val1;

        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};

//! Better, Hashmap

/*
> Time Complexity: O(N^2) + O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> freq((n * n) + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                freq[grid[i][j]]++;
            }
        }

        int repeating = -1, missing = -1;
        for (int i = 1; i <= n * n; i++)
        {
            if (freq[i] == 2)
            {
                repeating = i;
            }
            if (freq[i] == 0)
            {
                missing = i;
            }
        }

        vector<int> ans;
        ans.push_back(repeating);
        ans.push_back(missing);
        return ans;
    }
};

//! Brute Force, Double for loop

/*
> Time Complexity: O(N^2)
> Space Complexity: O(1)
*/