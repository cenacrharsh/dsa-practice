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
    string freqAlphabets(string s)
    {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= '1' && s[i] <= '9')
            {
                if (i + 2 < n && s[i + 2] == '#')
                {
                    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    ans += ('a' + num - 1); //* as 1 -> a not 0 -> a
                    i += 2;
                }
                else
                {
                    int num = (s[i] - '0');
                    ans += ('a' + num - 1);
                }
            }
        }
        return ans;
    }
};