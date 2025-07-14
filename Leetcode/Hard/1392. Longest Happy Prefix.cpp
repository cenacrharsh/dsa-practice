#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

/*
- Compute the Longest Prefix Suffix (LPS) array using the KMP preprocessing technique.
- The LPS array stores the length of the longest proper prefix which is also a suffix for each prefix of the string.
- The final value in the LPS array indicates the length of the longest happy prefix.
- Extract the substring from the start of the string up to this length and return it.
- If the length is zero, return an empty string.
*/

class Solution
{
public:
  vector<int> computeLPS(string str)
  {
    vector<int> LPS(str.size(), 0);
    int i = 1, j = 0;
    while (i < str.size())
    {
      if (str[i] == str[j])
      {
        LPS[i] = j + 1;
        i++;
        j++;
      }
      else
      {
        while (j > 0 && str[i] != str[j])
        {
          j = LPS[j - 1];
        }

        if (str[i] == str[j])
        {
          LPS[i] = j + 1;
          j++;
        }

        i++;
      }
    }
    return LPS;
  }

  string longestPrefix(string s)
  {
    vector<int> LPS = computeLPS(s);
    return s.substr(0, LPS.back());
  }
};