#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=pBD4B1tzgVc&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=9

/*
> Time Complexity: O(Log(N)) * O(Log(N))
> Space Complexity: O(1)
*/

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        //* to divide a number is basically keep adding the divisor until we can't anymore and whatever times we had to add is the quotient while leftover becomes remainder
        //* but since traditional adding can cause TLE we'll use binary representation of number where in, 22 / 3 => 7 * 3 + 1 = (2^2 + 2^1 + 2^0) * 3 = (2^2 * 3) + (2^1 * 3) + (2^0 * 3), and the number of 3's we can add will be known from here, 2^2 + 2^1 + 2^0 = 7

        if (dividend == divisor)
        {
            return 1;
        }

        //* figure out the sign of the result
        bool sign = true; //* indicates positive
        if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        {
            sign = false;
        }

        unsigned int numerator = abs(dividend);
        unsigned int denominator = abs(divisor);

        unsigned int ans = 0;
        while (numerator >= denominator)
        {
            int powerOf2 = 0;
            //* divisor * 2^(powerOf2 + 1) === divisor << powerOf2 + 1
            while (numerator > (denominator << (powerOf2 + 1)))
            {
                powerOf2++;
            }
            ans += (1 << powerOf2); //* ans += 2^(powerOf2)
            numerator = numerator - (denominator * (1 << powerOf2));
        }

        if ((ans >= (1 << 31)) && (sign == true))
        {
            return INT_MAX;
        }
        if ((ans >= (1 << 31)) && (sign == false))
        {
            return INT_MIN;
        }
        return sign ? ans : (0 - ans); //* we have to avoid multiplication
    }
};