#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=WDStNufBUQ8

//! Space Optimized

/*
> Time Complexity: O(N) + O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int minimumDeletions(string s)
    {
        //* end goal is to divide the array in such a way all the a's are on the left and all the b's are on the right
        //* one by one we'll assume each element to be the middle value and the count how many b's are on it's left and how many a's are on it's right from which we'll know how many elements we have to delete for this to be our middle element and the one which would give min number would be our answer

        int totalNumberOfAs = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
            {
                totalNumberOfAs++;
            }
        }

        int minDeletions = INT_MAX;
        int bToTheLeft = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
            {
                totalNumberOfAs--;
            }
            int deletions = bToTheLeft + totalNumberOfAs;
            minDeletions = min(minDeletions, deletions);
            if (s[i] == 'b')
            {
                bToTheLeft += 1;
            }
        }
        return minDeletions;
    }
};

//! Extra Space

/*
> Time Complexity: O(N) + O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int minimumDeletions(string s)
    {
        //* end goal is to divide the array in such a way all the a's are on the left and all the b's are on the right
        //* one by one we'll assume each element to be the middle value and the count how many b's are on it's left and how many a's are on it's right from which we'll know how many elements we have to delete for this to be our middle element and the one which would give min number would be our answer

        vector<int> aToTheRight(s.size(), 0);
        for (int i = s.size() - 2; i >= 0; i--)
        {
            aToTheRight[i] = aToTheRight[i + 1];
            if (s[i + 1] == 'a')
            {
                aToTheRight[i] += 1;
            }
        }

        int minDeletions = INT_MAX;
        int bToTheLeft = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int deletions = bToTheLeft + aToTheRight[i];
            minDeletions = min(minDeletions, deletions);
            if (s[i] == 'b')
            {
                bToTheLeft += 1;
            }
        }
        return minDeletions;
    }
};