#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Reverse (to avoid vector)

/*
> Time Complexity: O(N) + O(N) + O(N) => Overall Reverse + Traverse + Individual Words Reverse
> Space Complexity: O(1)
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        int i = 0, j = 0, start = 0, end = 0;
        while (i < s.size())
        {
            //* skip over empty spaces
            while (i < s.size() && s[i] == ' ')
            {
                i++;
            }

            if (i >= s.size())
            {
                continue;
            }

            //* move the entire string to the left to remove empty spaces
            start = j;
            while (i < s.size() && s[i] != ' ')
            {
                s[j] = s[i];
                j++;
                i++;
            }
            end = j - 1;

            //* reverse the word obtained within the original string
            reverse(s.begin() + start, s.begin() + end + 1);

            //* add a space
            s[j] = ' ';
            j++;
        }
        return s.substr(0, j - 1);
    }
};

//! Using a Vector to store individual words

/*
> Time Complexity: O(N) + O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;
        string ans = "";
        int i = 0;
        while (i < s.size())
        {
            while (i < s.size() && s[i] == ' ')
            {
                i++;
            }
            string temp = "";
            while (i < s.size() && s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            if (temp != "")
            {
                words.push_back(temp);
            }
        }
        for (int i = words.size() - 1; i >= 0; i--)
        {
            ans += i == 0 ? words[i] : words[i] + ' ';
        }
        return ans;
    }
};

//! Using Prepend During String Concatenation

/*
> Time Complexity: O(N^2) => Cost of creating new string grows over time
> Space Complexity: O(1)
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        string ans = "";
        int i = 0;
        while (i < s.size())
        {
            while (i < s.size() && s[i] == ' ')
            {
                i++;
            }
            string temp = "";
            while (i < s.size() && s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            if (temp != "")
            {
                ans = ans == "" ? temp : temp + ' ' + ans;
            }
        }
        return ans;
    }
};