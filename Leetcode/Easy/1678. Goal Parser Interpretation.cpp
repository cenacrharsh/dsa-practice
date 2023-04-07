#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    string interpret(string command)
    {
        int n = command.size();
        int i = 0;
        string ans = "";
        while (i < n)
        {
            if (command[i] == 'G')
            {
                ans += "G";
                // i++;
            }
            else if (command[i] == '(')
            {
                if (command[i + 1] == ')')
                {
                    ans += "o";
                    // i += 2;
                }
                else
                {
                    ans += "al";
                    // i += 4;
                }
            }
            i++;
        }
        return ans;
    }
};

//* or

class Solution
{
public:
    string interpret(string command)
    {
        int n = command.size();
        int i = 0;
        string ans = "";
        while (i < n)
        {
            if (command[i] == 'G')
            {
                ans += "G";
                i++;
            }
            else if (command[i] == '(')
            {
                if (command[i + 1] == ')')
                {
                    ans += "o";
                    i += 2;
                }
                else
                {
                    ans += "al";
                    i += 4;
                }
            }
        }
        return ans;
    }
};