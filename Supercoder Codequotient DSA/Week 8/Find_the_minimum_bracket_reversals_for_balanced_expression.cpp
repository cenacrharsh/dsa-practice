#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#define MAX_LEN 100000

int minReversal(char *expr)
{
  // Write your code here
  stack<char> st;
  int i = 0;
  while (expr[i] != '\0')
  {
    char current_char = expr[i];
    if (expr[i] == '[')
    {
      st.push(expr[i]);
    }
    else if (expr[i] == ']')
    {
      if (!st.empty() && st.top() == '[')
      {
        st.pop();
      }
      else
      {
        st.push(expr[i]);
      }
    }
    i++;
  }
  int m = 0, n = 0;
  while (!st.empty())
  {
    char current_char = st.top();
    if (current_char == ']')
    {
      m++;
    }
    else if (current_char == '[')
    {
      n++;
    }
    st.pop();
  }
  if ((m + n) % 2 != 0)
  {
    return -1;
  }
  if (m % 2 == 0 && n % 2 == 0)
  {
    return m / 2 + n / 2;
  }
  else if (m % 2 != 0 && n % 2 != 0)
  {
    return ((m - 1) / 2) + ((n - 1) / 2) + 2;
  }
}

int main()
{
  int t, ans;
  cin >> t;
  while (t--)
  {
    char expr[MAX_LEN + 1];
    cin >> expr;
    ans = minReversal(expr);
    cout << ans << endl;
  }
  return 0;
}