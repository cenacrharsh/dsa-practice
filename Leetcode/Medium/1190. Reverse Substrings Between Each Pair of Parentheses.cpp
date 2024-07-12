#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=65wVufni3tg

//! Wormhole Teleportaion

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> oppositeIndex(s.size(), -1);
        stack<int> st;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                int openingBracketIndex = st.top();
                st.pop();

                oppositeIndex[i] = openingBracketIndex;
                oppositeIndex[openingBracketIndex] = i;
            }
        }

        string ans = "";
        int direction = 1;
        for(int i = 0; i < s.size(); i += direction) {
            //* if bracket is encountered then switch directions and move to opposite index
            if(s[i] == '(' || s[i] == ')') {
                i = oppositeIndex[i];
                direction *= -1;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};

//! Stack

/*
> Time Complexity: O(N^2)
> Space Complexity: O(N)
*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char ch : s) {
            if(ch == ')') {
                //* pop characters until ')' found
                string temp = "";
                while(!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for(char c : temp) {
                    st.push(c);
                }
            } else {    
                st.push(ch);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};