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
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int commonDifference = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] != commonDifference)
            {
                return false;
            }
        }
        return true;
    }
};