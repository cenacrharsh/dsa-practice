#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimized Sliding Window, Get rid of rescan to ge maxFreq

/*
> Time Complexity: O(N)
> Space Complexity: O(26)
*/

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        //* no need to go below what max length we have already found, also no point in calculating maxFreq again since (len - maxFreq <= k) already gave us maxLen, now we want higher len value but we know len - maxFreq is already invalid now increasedLen - maxFreq <= k is not possible so we have to inc the value of maxFreq no lower it which the inner loop does so ignore it, reduction never helps in inc the ans

        int left = 0, right = 0, maxLength = 0, maxFreq = 0;
        vector<int> freq(26, 0);
        while (right < s.size())
        {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            if ((right - left + 1) - maxFreq > k)
            {
                freq[s[left] - 'A']--;
                left++;
            }

            if ((right - left + 1) - maxFreq <= k)
            {
                maxLength = max(maxLength, right - left + 1);
            }
            right++;
        }
        return maxLength;
    }
};

//! Sliding Window

/*
> Time Complexity: O(N + N) * 26 => Inner while loop throughout the journey takes N time
> Space Complexity: O(26)
*/

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0, right = 0, maxLength = 0, maxFreq = 0;
        vector<int> freq(26, 0);
        while (right < s.size())
        {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k)
            {
                freq[s[left] - 'A']--;

                //* update the max freq for this window
                maxFreq = 0;
                for (int i = 0; i < 26; i++)
                {
                    maxFreq = max(maxFreq, freq[i]);
                }
                left++;
            }

            if ((right - left + 1) - maxFreq <= k)
            {
                maxLength = max(maxLength, right - left + 1);
            }
            right++;
        }
        return maxLength;
    }
};

//! Brute Force

/*
> Time Complexity: O(N^2)
> Space Complexity: O(26)
*/
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        //* to minimize replacements and maximize the length of substring we'll figure out the max freq character in the substring and leave that and try to convert the others, length - maxfreq

        int maxLength = 0;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> freq(26, 0);
            int maxFreq = 0;
            for (int j = i; j < s.size(); j++)
            {
                freq[s[j] - 'A']++;
                maxFreq = max(maxFreq, freq[s[j] - 'A']);
                int changes = (j - i + 1) - maxFreq;
                if (changes <= k)
                {
                    maxLength = max(maxLength, j - i + 1);
                }
                else
                {
                    break;
                }
            }
        }
        return maxLength;
    }
};
