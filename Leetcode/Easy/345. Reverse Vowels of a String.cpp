#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using 2 pointers
class Solution
{
public:
    string reverseVowels(string s)
    {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            if (s[left] != 'a' && s[left] != 'e' && s[left] != 'i' && s[left] != 'o' && s[left] != 'u' && s[left] != 'A' && s[left] != 'E' && s[left] != 'I' && s[left] != 'O' && s[left] != 'U')
            {
                left++;
            }
            else if (s[right] != 'a' && s[right] != 'e' && s[right] != 'i' && s[right] != 'o' && s[right] != 'u' && s[right] != 'A' && s[right] != 'E' && s[right] != 'I' && s[right] != 'O' && s[right] != 'U')
            {
                right--;
            }
            else if ((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z') || (s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z'))
            {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};

//* or

class Solution
{
public:
    string reverseVowels(string s)
    {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            while (left < right && s[left] != 'a' && s[left] != 'e' && s[left] != 'i' && s[left] != 'o' && s[left] != 'u' && s[left] != 'A' && s[left] != 'E' && s[left] != 'I' && s[left] != 'O' && s[left] != 'U')
            {
                left++;
            }

            while (left < right && s[right] != 'a' && s[right] != 'e' && s[right] != 'i' && s[right] != 'o' && s[right] != 'u' && s[right] != 'A' && s[right] != 'E' && s[right] != 'I' && s[right] != 'O' && s[right] != 'U')
            {
                right--;
            }

            cout << "left: " << left << " right: " << right << endl;

            if ((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z') || (s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z'))
            {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};