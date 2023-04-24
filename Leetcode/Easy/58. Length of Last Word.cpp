#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Traverse From Back, O(1) Space Complexity
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int length = 0;
        int i = s.size() - 1;
        // find first non-space character
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }
        // find first space character after word is started
        while (i >= 0 && s[i] != ' ')
        {
            length++;
            i--;
        }
        return length;
    }
};

//! My Solution
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        string prevWord = "";
        string currWord = "";
        bool isWord = false;
        s = s + " ";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                isWord = true;
                currWord += s[i];
            }
            else if (s[i] == ' ' && isWord)
            {
                cout << "word: " << currWord << endl;
                prevWord = currWord;
                currWord = "";
                isWord = false;
            }
        }
        return prevWord.size();
    }
};