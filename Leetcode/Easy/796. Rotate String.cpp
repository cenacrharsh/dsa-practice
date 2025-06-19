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
> Time Complexity: O(N) + O(2N) => Adding 2 String + Search in string of size 2N
> Space Complexity: O(N) => String size inc by N
*/

class Solution
{
public:
  bool rotateString(string s, string goal)
  {
    if (s.size() != goal.size())
    {
      return false;
    }
    return (s + s).find(goal) != string::npos; //* internally .find() uses Rabin Karp Algorithm
  }
};