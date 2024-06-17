#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

/*
> Time Complexity: O(Log(N))
> Space Complexity: O(1)
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) {
            return 0;
        }
        
        int low = 1, high = x;
        int sqRoot = 1;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;

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
};