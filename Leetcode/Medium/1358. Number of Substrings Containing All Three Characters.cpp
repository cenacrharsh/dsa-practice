#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: 1358. Number of Substrings Containing All Three Characters

//! Sliding Window

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        //* with every character there is a substring that ends on it, and if this substring is valid say b/w index 2->5, then substrings with index 0,1->5 also valid

        //* while traversing from left we maintain out what is the last seen position of each character and as soon as we reach a char where we have all 3 there we figure out the least window size possible which ofcourse starts from min(posA, posB, posC)->index j and hence all substrings starting from 0->min(posA, posB, posC) are now valid = min(posA, posB, posC) + 1 substrings

        vector<int> lastSeen(3, -1);
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            lastSeen[s[i] - 'a'] = i;

            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                count += 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
            }
        }
        return count;
    }
};

//! Brute Force -> TLE

/*
> Time Complexity: O(N^2)
> Space Complexity: O(1)
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        //* if at index j we find that the substring contains all the required characters then all the substrings infront of it would also have the req char, so we can just add all the substrings from index j till end of the string
        
        int count = 0;
        vector<int> hash(3, -1);
        for(int i = 0; i < s.size(); i++) {
            hash.assign(3, -1);   
            for(int j = i; j < s.size(); j++) {
                hash[s[j] - 'a'] = 1;

                if(hash[0] + hash[1] + hash[2] == 3) {
                    count += s.size() - j;
                    break;
                }
            }
        }
        return count;
    }
};