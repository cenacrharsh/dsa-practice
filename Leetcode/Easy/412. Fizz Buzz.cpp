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
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans(n);
        for (int i = 0; i < n; i++)
        {
            int currIndex = i + 1;
            if (currIndex % 3 == 0 && currIndex % 5 == 0)
            {
                ans[i] = "FizzBuzz";
            }
            else if (currIndex % 3 == 0)
            {
                ans[i] = "Fizz";
            }
            else if (currIndex % 5 == 0)
            {
                ans[i] = "Buzz";
            }
            else
            {
                ans[i] = to_string(currIndex);
            }
        }
        return ans;
    }
};