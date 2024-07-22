#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Map (Descending Order)

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string, greater<int>> mp;
        for(int i = 0; i < heights.size(); i++) {
            mp[heights[i]] = names[i];
        }
        vector<string> ans;
        for(auto [height, name] : mp) {
            ans.push_back(name);
        }
        return ans;
    }
};