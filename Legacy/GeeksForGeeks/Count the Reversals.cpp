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
> Space Complexity: O(1)
*/

class Solution
{
public:
  int countMinReversals(string s)
  {
    if (s.size() % 2 != 0)
      return -1;
    int opening = 0, closing = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '{')
      {
        opening++;
      }
      else if (s[i] == '}')
      {
        if (opening > 0)
        {
          opening--;
        }
        else
        {
          closing++;
        }
      }
    }
    int ans = (opening / 2) + (opening % 2) + (closing / 2) + (closing % 2);
    return ans;
  }
};