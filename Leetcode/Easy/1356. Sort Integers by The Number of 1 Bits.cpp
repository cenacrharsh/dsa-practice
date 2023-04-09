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
    static int countSetBits(int n)
    {
        int count = 0;
        while (n != 0)
        {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
    static bool myComparison(int a, int b)
    {
        int p = countSetBits(a);
        int q = countSetBits(b);
        if (p == q)
        {
            return a <= b;
        }
        else
        {
            return p < q;
        }
    }
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), myComparison);
        return arr;
    }
};