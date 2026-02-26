#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimal

/*
> Time Complexity: O(N)
> Space Complexity: O(3)
*/

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        //* we know that at every character there is a substring that ends at it, so for every character we figure out what is the least no. of character we have to go to the left to achive all 3 chars, then from there and for every character before it we know we have a valid substring
        //* eg. b b a c b a -> at index 4 we know a c b is the min substring so we can say all char at 0 1 2 till index 4 are also valid

        int count = 0;
        vector<int> lastSeenIndex = {-1, -1, -1};
        for (int i = 0; i < s.size(); i++)
        {
            lastSeenIndex[s[i] - 'a'] = i;

            if (lastSeenIndex[0] != -1 && lastSeenIndex[1] != -1 && lastSeenIndex[2] != -1)
            {
                int leastIndex = min(lastSeenIndex[0], min(lastSeenIndex[1], lastSeenIndex[2]));
                count += leastIndex + 1;
            }
        }
        return count;
    }
};

//! Optimized Brute Force, if a substring already has the 3 char then all that come after it will have it automatically so no need to go till the end

/*
> Time Complexity: O(N^2)
> Space Complexity: O(3)
*/

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> freq(3, 0);
            for (int j = i; j < s.size(); j++)
            {
                freq[s[j] - 'a'] = 1;
                if (freq[0] + freq[1] + freq[2] == 3)
                {
                    count += (s.size() - j);
                    break;
                }
            }
        }
        return count;
    }
};

//! Brute Force

/*
> Time Complexity: O(N^2)
> Space Complexity: O(3)
*/

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> freq(3, 0);
            for (int j = i; j < s.size(); j++)
            {
                freq[s[j] - 'a'] = 1;
                if (freq[0] + freq[1] + freq[2] == 3)
                {
                    count++;
                }
            }
        }
        return count;
    }
};