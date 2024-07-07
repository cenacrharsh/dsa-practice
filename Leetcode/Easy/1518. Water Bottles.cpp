#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(Log(NumBottles) Base (NumExchange))
> Space Complexity: O(1)
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptyBottles = numBottles;
        while(emptyBottles >= numExchange) {
            ans += emptyBottles / numExchange;
            emptyBottles = (emptyBottles / numExchange) + (emptyBottles % numExchange);
        }
        return ans;
    }
};