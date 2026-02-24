#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimal, 2 Pointers + Optimized Sliding Window

/*
> Time Complexity: O(N) + O(1)
> Space Complexity: O(2)
*/

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        //* boils down to longest substring with at most 2 different characters
        unordered_map<int, int> mp;
        int maxLength = 0, left = 0, right = 0;
        while (right < fruits.size())
        {
            mp[fruits[right]]++;

            if (mp.size() > 2)
            {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0)
                {
                    mp.erase(fruits[left]);
                }
                left++;
            }

            if (mp.size() <= 2)
            {
                maxLength = max(maxLength, right - left + 1);
            }
            right++;
        }
        return maxLength;
    }
};

//! Better, 2 Pointers + Sliding Window

/*
> Time Complexity: O(N) + O(N) + O(1), O(Log 256) if ordered map
> Space Complexity: O(2)
*/

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        //* boils down to longest substring with at most 2 different characters
        unordered_map<int, int> mp;
        int maxLength = 0, left = 0, right = 0;
        while (right < fruits.size())
        {
            mp[fruits[right]]++;

            while (mp.size() > 2)
            {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0)
                {
                    mp.erase(fruits[left]);
                }
                left++;
            }

            if (mp.size() <= 2)
            {
                maxLength = max(maxLength, right - left + 1);
            }
            right++;
        }
        return maxLength;
    }
};

//! Brute Force, Generate all substrings

/*
> Time Complexity: O(N^2) * O(Log 256) if map, O(1) if unordered_map
> Space Complexity: O(2)
*/
