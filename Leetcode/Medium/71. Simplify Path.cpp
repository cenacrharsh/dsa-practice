#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
EXPLANATION :-

Create a Stack of String with following condition.

Iterate the loop till you doesn't reaches the end of string.

If you encounter a "/" then ignore it.

Create a temp String & Iterate the while loop till you doesn't find "/" and append it to temp.

Now check if temp == "." , then ignore it.

If temp == ".." then pop the element from the stack if it exists.

If no of the above 2 matches push temp to stack as you find a valid path.

Check out temp string on basis of above conditions till you doesn't find "/".

Now add all stack elements to result as res = "/" + st.top() + res

If res.size() is 0 then return "/" if no directory or file is present.

At last return res.
*/

/*
ALGORITHM :-

By looking at examples we can see that the above simplification process just behaves like a stack.

Whenever we encounter any file’s name, we simply push it into the stack.

when we come across ” . ” we do nothing

When we find “..” in our path, we simply pop the topmost element as we have to jump back to parent’s directory.

When we see multiple “////” we just ignore them as they are equivalent to one single “/”.

After iterating through the whole string the elements remaining in the stack is our simplified absolute path.
*/

class Solution
{
public:
    string simplifyPath(string path)
    {
        // approach is to find words in between 2 / and if they are . or .. we need to stay in the same directory or move up 1 directory respectively

        stack<string> st;
        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == '/') // ignore all extra /
            {
                continue;
            }

            // contruct the word in between 2 /
            string temp;
            while (i < path.size() && path[i] != '/')
            {
                temp += path[i]; // make a string of all char in b/w two /
                i++;
            }

            // now match temp string with . .. or a word
            if (temp == ".") // . indicates stay in the current directory
            {
                continue;
            }
            else if (temp == "..")
            {
                if (!st.empty())
                {
                    st.pop(); // .. indicates move up one directory
                }
            }
            else
            {
                st.push(temp); // anything else is a dir name, so push it
            }
        }

        // adding all stack elements to ans
        string ans;
        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        // if no directory or file is present
        if (ans.size() == 0)
            return "/";

        return ans;
    }
};