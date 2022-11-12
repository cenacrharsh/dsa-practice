#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
 int characterReplacement(string s, int k)
 {
  int windowStart = 0, maxLength = 0, maxCharCount = 0, freq[26] = {0};
  for (int windowEnd = 0; windowEnd < s.length(); windowEnd++)
  {
   freq[s[windowEnd] - 'A']++;
   int currCharCount = freq[s[windowEnd] - 'A'];
   maxCharCount = max(maxCharCount, currCharCount);

   if (windowEnd - windowStart - maxCharCount + 1 > k)
   {
    freq[s[windowStart] - 'A']--;
    windowStart++;
   }

   maxLength = max(maxLength, windowEnd - windowStart + 1);
  }
  return maxLength;
 }
};