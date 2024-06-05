#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=lPx-Yz2_gIA

/*
> Time Complexity: O(N * 26)
> Space Complexity: O(26 + 26)
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> finalFreq(26, INT_MAX);

        for(int i = 0; i < words.size(); i++) {
            //* calculate freq of current word
            vector<int> currFreq(26, 0);
            for(int j = 0; j < words[i].size(); j++) {
                currFreq[words[i][j] - 'a']++;
            }

            //* adjust the final freq by taking minimum of freq in final vs current array
            for(int k = 0; k < 26; k++) {
                finalFreq[k] = min(finalFreq[k], currFreq[k]);
            }
        }

        vector<string> ans;
        for(int i = 0; i < 26; i++) {
            while(finalFreq[i]--) {
                ans.push_back(string(1, i + 'a'));
            }
        }
        return ans;
    }
};
