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
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        vector<int> ans;
        int carry = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            int num = digits[i] + carry;
            if (num > 9)
            {
                carry = num / 10;
                num = num % 10;
            }
            else
            {
                carry = 0;
            }
            ans.insert(ans.begin(), num);
        }
        if (carry != 0)
        {
            ans.insert(ans.begin(), carry);
        }
        return ans;
    }
};