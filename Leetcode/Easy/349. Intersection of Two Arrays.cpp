#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <climits>
#include <unordered_map>
#include <map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(M * N + M log M) where M = length of strs array, N = avg length of each string
> Space Complexity: O(M + N)
*/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<vector<int>, vector<string>> anagramGroups; //* freq map of word -> array of words which match that freq map
        for (string str : strs)
        {
            //* create freq map for the current word
            vector<int> freq(26, 0);
            for (char ch : str)
            {
                freq[ch - 'a']++;
            }

            //* insert the current freq map in hashmap
            anagramGroups[freq].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto it : anagramGroups)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
