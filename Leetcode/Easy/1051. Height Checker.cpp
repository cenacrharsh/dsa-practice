#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp = heights;
        sort(temp.begin(), temp.end());
        int count = 0;
        for(int i = 0 ; i < heights.size() ; i++)
        {
            if(heights[i] != temp[i])
            {
                count++;
            }
        }
        return count;
    }
};