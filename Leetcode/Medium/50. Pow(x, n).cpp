#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://leetcode.com/problems/powx-n/description/

/*
> Time Complexity: O(log(N))
> Space Complexity: O(1)
*/

//! Recursive
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1.0;

        // if power is negative
        if (n < 0)
        {
            x = 1 / x;
            n = abs(n);
        }

        // even power
        if (n % 2 == 0)
        {
            return myPow(x * x, n / 2);
        }

        // odd power
        return x * myPow(x, n - 1);
    }
};

//! Iterative
class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long power = n;

        if (power < 0)
        {
            power = -1 * power;
        }

        while (power != 0)
        {
            if (power % 2 == 0)
            {
                x = x * x;
                power = power / 2;
            }
            else
            {
                ans = ans * x;
                power = power - 1;
            }
        }

        if (n < 0)
        {
            ans = (double)(1.0) / (double)(ans);
        }
        return ans;
    }
};