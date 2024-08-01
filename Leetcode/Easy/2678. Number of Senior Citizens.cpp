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
    int countSeniors(vector<string> &details)
    {
        int ans = 0;
        for (string passenger : details)
        {
            string ageInString = passenger.substr(11, 2);
            if (stoi(ageInString) > 60)
            {
                ans++;
            }
        }
        return ans;
    }
};