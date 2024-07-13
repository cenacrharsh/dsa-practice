#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=kLjAWG1Je-c

/*
> Time Complexity: O(N * Log(N)) => Sorting
> Space Complexity: O(N) => Vector
*/

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> ids;
        for(int i = 0; i < positions.size(); i++) {
            ids.push_back(i);
        }

        auto compare = [&](int id1, int id2) {
            return positions[id1] <= positions[id2];
        };

        //* sort ids based on thier positions
        sort(ids.begin(), ids.end(), compare);

        //* treat R as ( and L as ) then we can solve this problem as opening and closing paranthesis
        stack<int> st;
        for(int idx : ids) {
            cout << "IDX: " << idx << endl;
            if(directions[idx] == 'R') {
                st.push(idx);
            } else {
                while(!st.empty() && healths[idx] > 0) {
                    if(healths[idx] > healths[st.top()]) {
                        healths[idx]--;
                        healths[st.top()] = 0;
                        st.pop();
                    } else if(healths[idx] < healths[st.top()]) {
                        healths[idx] = 0;
                        healths[st.top()]--;
                    } else {
                        healths[st.top()] = 0;
                        healths[idx] = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < healths.size(); i++) {
            if(healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};