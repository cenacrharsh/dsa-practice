#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=CRbDvJorCF0

//! Using 2 Pointers

/*
> Time Complexity: O(max(N,M))
> Space Complexity: O(1)
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while(i < version1.size() || j < version2.size()) {
            int val1 = 0, val2 = 0;
            while(i < version1.size() && version1[i] != '.') {
                val1 = val1 * 10 + (version1[i] - '0');
                i++;
            }
            while(j < version2.size() && version2[j] != '.') {
                val2 = val2 * 10 + (version2[j] - '0');
                j++;
            }

            if(val1 < val2) {
                return -1;
            } else if(val1 > val2) {
                return 1;
            }

            i++;
            j++;
        }
        return 0;
    }
};

//! Using substr Function

/*
> Time Complexity: O(N+M)
> Space Complexity: O(N+M)
*/

class Solution {
public:
    vector<int> splitString(string &s, char delimeter) {
        vector<int> ans;
        int start = 0;
        int end = s.find(delimeter, start);
        while(end != string::npos) {
            string temp = s.substr(start, end - start);
            ans.push_back(stoi(temp));
            start = end + 1;
            end = s.find(delimeter, start);
        }
        //* for last substring as it which is left because no delimeter
        string temp = s.substr(start, end - start);
        ans.push_back(stoi(temp));
        return ans;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = splitString(version1, '.');
        vector<int> v2 = splitString(version2, '.');

        for(int i = 0; i < max(v1.size(), v2.size()); i++) {
            int val1 = i < v1.size() ? v1[i] : 0;
            int val2 = i < v2.size() ? v2[i] : 0;

            if(val1 < val2) {
                return -1;
            } else if(val1 > val2) {
                return 1;
            }
        }
        return 0;
    }
};

