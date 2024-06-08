#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=1W_HYBqvDLw

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //* prefix sum b/w index i & j = prefixSum(j) - prefixSum(i) & if this is divisible by k then we have our good subarray
        //* [prefixSum(j) - prefixSum(i)] % k == 0 => prefixSum(i)] % k == prefixSum(j) % k
        //* we'll maintain a prefixSumRemainder map and whereever we have same values we may conclude that the sum of range b/w these 2 occurrences will give, sum % k == 0, also to maintain len >= 2 we'll always look for first and last occurence of that remainder in the map

        int prefixSumRemainder = 0;
        unordered_map<int, int> prefixSumRemainderMap; //* prefixSum->first occurence index
        prefixSumRemainderMap[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            prefixSumRemainder = (prefixSumRemainder + nums[i]) % k;

            //* if the current prefixSumRemainder is already present in out hashmap we'll see if the length of subarray >= 2 or not
            if(prefixSumRemainderMap.find(prefixSumRemainder) != prefixSumRemainderMap.end()) {
                if(i - prefixSumRemainderMap[prefixSumRemainder] >= 2) {
                    return true;
                }
            } else {
                prefixSumRemainderMap[prefixSumRemainder] = i;
            }
        }
        return false;
    }
};