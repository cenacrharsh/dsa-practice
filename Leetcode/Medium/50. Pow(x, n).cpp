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

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long power = n;

        if(power < 0) {
            power = -1 * power;
        }

        while(power != 0) {
            if(power % 2 == 0) {
                x = x * x;
                power = power / 2;
            } else {
                ans = ans * x;
                power = power - 1;
            }
        }

        if(n < 0) {
            ans = (double)(1.0) / (double)(ans);
        }
        return ans;
    }
};