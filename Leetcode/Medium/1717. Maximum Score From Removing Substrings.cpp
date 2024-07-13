#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=jxng2IcJyCk&t=365s

//! Stack + Greedy

/*
> Time Complexity: O(3 * N) * 2
> Space Complexity: O(2 * N) * 2
*/

class Solution {
public:
    int pointsForString(string &s, string targetString, int point) {
        int totalPoints = 0;
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            if(st.size() == 0) {
                st.push(s[i]);
            } else {
                if(s[i] == targetString[1] && st.top() == targetString[0]) {
                    st.pop();
                    totalPoints += point;
                } else {
                    st.push(s[i]);
                }
            }
        }

        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());

        return totalPoints;
    }

    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";

        //* make sure s1 and x always carry max value substring
        if(x < y) {
            swap(s1, s2);
            swap(x, y);
        }

        //* in first iteration remove all higher valued substrings, then remove lower valued substrings in next iteration
        return pointsForString(s, s1, x) + pointsForString(s, s2, y);
    }
};