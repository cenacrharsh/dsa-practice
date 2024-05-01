#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution {
public:
    string reverseWord(string &word, int startIndex, int endIndex) {
        while(startIndex <= endIndex) {
            swap(word[startIndex++], word[endIndex--]);
        }
        return word;
    }

    string reversePrefix(string word, char ch) {
        int index = -1;
        for(int i = 0; i < word.size(); i++) {
            if(word[i] == ch) {
                index = i;
                break;
            }
        }
        if(index != -1) {
            reverseWord(word, 0, index);
        }
        return word;
    }
};