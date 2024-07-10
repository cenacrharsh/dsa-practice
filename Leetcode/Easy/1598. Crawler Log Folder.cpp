#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Simple Loop

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0; //* since path not required we can just keep track of number
        for(string log : logs) {
            if(log == "./") {
                continue;
            } else if(log == "../") {
                if(ans > 0) {
                    ans--;
                }
            } else {
                ans++;
            }
        }
        return ans;
    }
};

//! Stack

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(string log : logs) {
            if(log == "./") {
                continue;
            } else if(log == "../") {
                if(!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(log.substr(0, log.size() - 1)); //* helpful if we need to trace the path
            }
        }
        return st.size();
    }
};