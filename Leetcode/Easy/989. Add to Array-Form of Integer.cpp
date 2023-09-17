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
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int carry = 0;
        int n = num.size();
        int i = n - 1;
        while (i >= 0)
        {
            int sum = i == n - 1 ? num[i] + carry + k : num[i] + carry;
            num[i] = sum % 10;
            carry = sum / 10;
            i--;
        }
        while (carry)
        {
            num.insert(num.begin(), carry % 10);
            carry /= 10;
        }
        return num;
    }
};