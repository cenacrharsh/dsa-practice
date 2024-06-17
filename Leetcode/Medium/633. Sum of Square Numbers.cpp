#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=fRK4jGPmblc

//! 2 Pointers

/*
> Time Complexity: O(Log(N) + √N) => One Time Sqrt + Loop
> Space Complexity: O(1)
*/

#define ll long long int
class Solution {
public:
    bool judgeSquareSum(int c) {
        ll a = 0, b = sqrt(c);
        while(a <= b) {
            ll res = (a * a) + (b * b);
            
            if(res == c) {
                return true;
            } else if(res < c) {
                a++;
            } else {
                b--;
            }
        }
        return false;
    }
};

//! Using Binary Search/Sqrt Function

/*
> Time Complexity: O(√N * Log(N)) => Loop + Sqrt Function
> Space Complexity: O(1)
*/

#define ll long long int
class Solution {
public:
    ll mySqrt(ll x) {
        if(x == 0) {
            return 0;
        }
        
        ll low = 1, high = x;
        ll sqRoot = 1;
        
        while(low <= high)
        {
            ll mid = low + (high - low) / 2;

            //* not using mid * mid <= x to prevent integer overflow
            if(mid <= x / mid) {
                low = mid + 1;
                sqRoot = mid;
            }
            else {
                high = mid - 1;
            }
            
        }
        return sqRoot;
    }

    bool judgeSquareSum(int c) {
        //* the max value of a and b in the equation a² + b² = c is √c
        //* √n returns a double, we typecast it into int and if on multiplying with itself we get the same number we can say it's a perfect square number

        for(ll a = 0; a * a <= c; a++) {
            ll b = mySqrt(c - (a * a));

            if(b * b == c - (a * a)) {
                return true;
            }
        }
        return false;
    }
};