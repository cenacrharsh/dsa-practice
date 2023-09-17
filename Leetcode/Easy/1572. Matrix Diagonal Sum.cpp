#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int row = mat.size();
        int primaryDiagonalSum = 0, secondaryDiagonalSum = 0;
        for (int i = 0; i < row; i++)
        {
            // Add elements from primary diagonal
            primaryDiagonalSum += mat[i][i];

            // Add elements from secondary diagonal
            secondaryDiagonalSum += mat[row - 1 - i][i];
        }
        int ans = primaryDiagonalSum + secondaryDiagonalSum;
        // If num(rows) is odd, subtract the middle element as its added twice
        if (row % 2 != 0)
        {
            ans -= mat[row / 2][row / 2];
        }
        return ans;
    }
};