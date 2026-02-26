#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Bsv3FPUX_BA&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=17

/*
> Time Complexity: O(log (n) base 2)
> Space Complexity: O(1)
*/

//! Intuition: Range of answers already know and min/max asked

int floorSqrt(int n)
{
    int low = 1, high = n;
    int ans = 1;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        //* if mid * mid <= n then it might be a possible ans, but we need largest integer so we move right
        if ((mid * mid) <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
