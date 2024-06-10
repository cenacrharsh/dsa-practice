#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=QM0klnvTQzk | https://www.youtube.com/watch?v=C0okNE_tt14

/*
> Time Complexity: O(N)
> Space Complexity: O(K) => Modulo K ensures we won't have numbers > K
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //* prefix sum b/w index i & j = prefixSum(j) - prefixSum(i) & if this is divisible by k then we have our good subarray
        //* prefixSum(j) - prefixSum(i) == rangeSum => [prefixSum(j) - prefixSum(i)] % k == rangeSum % k, and we know rangeSum % k should be 0
        //* [prefixSum(j) - prefixSum(i)] % k == 0 => prefixSum(i) % k == prefixSum(j) % k
        //* we'll maintain a prefixSumRemainder map and whereever we have same values we may conclude that the sum of range b/w these 2 occurrences will give, sum % k == 0, also to maintain len >= 2 we'll always look for first and last occurence of that remainder in the map

        //* problem almost same as Leetcode: 523. Continuous Subarray Sum, except remainders can be negative as well
        //* we have to convert the negative remainders to their positive couterparts
        //* if we have negative remainder say after dividing K by n => Kn - y, we can convert it into +ve by +/- by K
        //* Kn - y == Kn - y + K - K == K(n - 1) + (K - y) which is a number divisible by K + Positive Remainder == Kn' - y + K, so by adding K to the -ve remainder we get it's +ve counterpart

        int prefixSumRemainder = 0;
        int count = 0;
        unordered_map<int, int> prefixSumRemainderMap; //* prefixSumRemainder->freq
        prefixSumRemainderMap[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            prefixSumRemainder = (prefixSumRemainder + (nums[i] % k) + k) % k; //* we can do + K even in case of +ve remainders as it makes no difference, so we don't need to check if it's negative before adding + k, eg. 2 % 6 = 2, 2 % 6 + 6 == 8 % 6 is also = 2 as we are doing an overall modulus as well to the entire sum
            count += prefixSumRemainderMap[prefixSumRemainder]; //* if the current prefixSumRemainder is already present in out hashmap we'll add the freq of it's occurence to our ans else freq == 0, so sum remains same, no need of checking if remainder exists in hashmap
            prefixSumRemainderMap[prefixSumRemainder]++;
        }
        return count;
    }
};