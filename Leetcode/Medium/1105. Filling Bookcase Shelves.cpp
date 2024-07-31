#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Memoization

class Solution
{
public:
    int helper(vector<vector<int>> &books, int shelfWidth, int currIndex, int remainingShelfWidth, int currShelfHeight, vector<vector<int>> &dp)
    {
        if (currIndex >= books.size())
        {
            return currShelfHeight;
        }

        if (dp[currIndex][remainingShelfWidth] != -1)
        {
            return dp[currIndex][remainingShelfWidth];
        }

        int currBookWidth = books[currIndex][0];
        int currBookHeight = books[currIndex][1];

        //* put book in old shelf
        int oldShelf = INT_MAX;
        if (remainingShelfWidth >= currBookWidth)
        {
            oldShelf = helper(books, shelfWidth, currIndex + 1, remainingShelfWidth - currBookWidth, max(currShelfHeight, currBookHeight), dp);
        }

        //* put book in new shelf
        int newShelf = currShelfHeight + helper(books, shelfWidth, currIndex + 1, shelfWidth - currBookWidth, currBookHeight, dp);

        return dp[currIndex][remainingShelfWidth] = min(oldShelf, newShelf);
    }

    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        vector<vector<int>> dp(books.size(), vector<int>(shelfWidth + 1, -1));
        return helper(books, shelfWidth, 0, shelfWidth, 0, dp);
    }
};