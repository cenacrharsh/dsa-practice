#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Hashmap

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> freq; //* num->freq
        for (int num : target)
        {
            freq[num]++;
        }
        for (int num : arr)
        {
            freq[num]--;
            if (freq[num] == 0)
            {
                freq.erase(num);
            }
        }
        if (freq.size() > 0)
        {
            return false;
        }
        return true;
    }
};