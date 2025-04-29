#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(3N + K)
> Space Complexity: O(N) + (N) => Stack + ans
*/

class Solution
{
public:
  string removeKdigits(string num, int k)
  {
    //* we have to remove k larger digits but to get the minimum value we need the smaller digits at the start, so we traverse form left to right and if we encounter bigger elements than what is in stack we simply push and keep moving forward, when we find a smaller element we know we'll benefit from this being at the front so we'll pop until we have a smaller element in stack or we have exhausted k, if we are unable to remove k digits eg(12345) then simply remove k digits from the end as they will be the bigger ones

    stack<char> st;
    //* O(N)
    for (int i = 0; i < num.size(); i++)
    {
      //* keep popping until current element is < than top element
      while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0'))
      {
        st.pop();
        k--;
      }
      st.push(num[i]);
    }
    //* O(K)
    while (k--)
    {
      st.pop();
    }

    if (st.empty())
    {
      return "0";
    }

    string res = "";
    //* O(N)
    while (!st.empty())
    {
      res += st.top();
      st.pop();
    }

    //* O(N) => we'll pop half and reverse whatever remains so combined worst case gives N
    while (res.size() != 0 && res.back() == '0')
    {
      res.pop_back();
    }
    reverse(res.begin(), res.end());

    //* check important, if all elements in the stack were 0 then res would become empty
    if (res.size() == 0)
    {
      return "0";
    }
    return res;
  }
};