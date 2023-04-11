#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using 2 Pointers

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    string removeStars(string s)
    {
        int j = 0;
        string ans = "";
        while (j < s.size())
        {
            if (s[j] != '*')
            {
                ans.push_back(s[j]);
            }
            else
            {
                if (ans.size() > 0)
                {
                    ans.pop_back();
                }
            }
            j++;
        }
        return ans;
    }
};

//! Using Stack

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

/*
The reason why using ans.push_back(st.top()) and reversing the string before returning it works fine, while using ans = st.top() + ans results in TLE, is because the + operator for strings is an expensive operation.

When you use ans = st.top() + ans, for every iteration of the while loop, you are creating a new string by concatenating the current character with the existing string. This new string is then assigned to the ans variable. As the size of the string increases, this operation becomes increasingly expensive, resulting in a TLE for larger inputs.

On the other hand, using ans.push_back(st.top()) simply adds the current character to the end of the existing string without creating a new one. This operation is much faster and efficient, as it only modifies the existing string and does not create a new one.

By reversing the string before returning it, you get the same result as using ans = st.top() + ans, but with better performance. Reversing the string can also be done efficiently using the reverse function from the algorithm library, as you did in your updated code.

Therefore, using ans.push_back(st.top()) and reversing the string before returning it is a better approach than using ans = st.top() + ans.
*/

class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '*')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans.push_back(st.top()); //* ans = st.top() + ans gave TLE
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};