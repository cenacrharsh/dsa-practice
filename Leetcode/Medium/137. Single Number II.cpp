#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=5Bb2nqA40JY&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=11

//! Advanced Bit Manipulation Using ^ &

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        //* bitIndexes would take care of all the numbers even if the don't occur in sorted manner sequentially

        //* we'll maintain 3 buckets called ones, twos and threes which would store which number appears onece, twice and thrice respectively
        //* nums[i] would go to ones if the number is not in twos
        //* nums[i] would go to twos if the number is in ones
        //* nums[i] would go to threes if the number is in twos, but we don't really care which numbers appears thrice so we'll skip this, at the third occurent what is more important for us is to remove the number from twos

        int ones = 0, twos = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ones = (ones ^ nums[i]) & (~twos);
            //* add number in ones only if number is not present in twos, ^ and negation takes care of that, if twos is zero then ^ adds that number in ones since ~twos gives all 1's and since it wasn't already in ones, ones ^ nums[i] = nums[i] and then nums[i] & 1's gives nums[i]
            //* XOR is chosen since if number is already in ones, nums[i] ^ nums[i] would give 0 hence number is removed from ones

            twos = (twos ^ nums[i]) & (~ones);
            //* if number is occuring twice ones is already cleared above and now it would get inserted in twos
            //* during first occurence ~ones genrates the opposite sequence of bits of the number present in ones and since twos is empty already twos ^ nums[i] = nums[i] => nums[i] ^ ~nums[i] = 0
            //* in third occurence twos makes sure it doesn't get into ones and then it gets removed from twos as well
        }
        return ones;
    }
};

//! Sorting

/*
> Time Complexity: O(N * Log(N)) => it's better than N * 32 because for Log(N) to be 32 we need 2^32 numbers which won't happens so this sol is better
> Space Complexity: O(1)
*/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        //* if we start iterating from 1st index and move 3 places everytime we hope to reach middle element of cluster of 3 element eg. 1 1 1, 2 2 2, 3 3 3 unless a rogue element comes in b/w element at ith index would always match with element at i-1th index, if rogue element is at first place the algo would still work and if at last place then loop would termiate before reaching it and we know that the rogue element was present at the last index

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 3)
        {
            if (nums[i] != nums[i - 1])
            {
                return nums[i - 1];
            }
        }
        return nums[nums.size() - 1];
    }
};

//! Bit Manipulation

/*
> Time Complexity: O(32 * N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // we'll figure out the number digit by digit, for each place digit we'll count the total number of 1's in that place in all the digits (overall 31 places) and if the count of 1's is a multiple of 3 then we know for sure 1 came from the numbers which appeared thrice so the digit at this place in our number would be 0 and similarly if number of 1's is not a multiple of 3 then it the digit at this place would be 1

        int ans = 0;
        for (int bitIndex = 0; bitIndex < 32; bitIndex++)
        {
            int numOf1s = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if ((nums[j] & (1 << bitIndex)) != 0)
                {
                    numOf1s++;
                }
            }

            // if numOf1s is not a multiple of 3 then set that bit in the ans, to handle negative numbers we'll set the 32nd bit i.e the sign bit to 1 accordingly
            if (numOf1s % 3 != 0)
            {
                ans = ans | (1 << bitIndex);
            }
        }
        return ans;
    }
};