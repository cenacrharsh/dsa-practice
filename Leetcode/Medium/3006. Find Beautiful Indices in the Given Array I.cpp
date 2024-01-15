#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using .find() and npos
class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        vector<int> ans;
        vector<int> occ1;
        vector<int> occ2;

        int index = 0;
        while ((index = s.find(a, index)) != std::string::npos)
        {
            occ1.push_back(index);
            ++index;
        }
        index = 0;
        while ((index = s.find(b, index)) != std::string::npos)
        {
            occ2.push_back(index);
            ++index;
        }

        /* or
        // Step 2: Find indices of occurrences of string 'a'
        for (int i = 0; i <= x - y; i++) {
            if (s.substr(i, y) == a) {
                indices_a.push_back(i);
            }
        }
        */

        for (int i = 0; i < occ1.size(); i++)
        {
            for (int j = 0; j < occ2.size(); j++)
            {
                if (abs(occ1[i] - occ2[j]) <= k)
                {
                    ans.push_back(occ1[i]);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};