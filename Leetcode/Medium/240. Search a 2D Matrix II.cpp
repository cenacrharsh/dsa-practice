#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=9ZbB397jU4k&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=27

/*
> Time Complexity: O(n + m) -> to reach from one end to the other we have to travel m steps in vertical direction and n steps in horizontal direction
> Space Complexity: O(1)
*/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        //* elements at (0, 0) and (n-1,m-1) can't be our starting points as for (0, 0) elements are inc along the row and col and for (n-1, n-1) elements are dec along the row and col, since it's either inc or dec in both the directions we can't eliminate one half

        //* elements at (0, m - 1) and (n - 1, 0) can be our starting elements, for (0, m - 1) value is dec along the row and inc along the row, for (n - 1, 0) elements are dec along the col and inc along the row hence we can easily eliminate one half of it

        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m - 1; //* choosing (0, m -1) as our starting point
        while (row < n && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (target > matrix[row][col])
            {
                row++; //* value dec along the row for (0, m-1)
            }
            else
            {
                col--; //* value inc along the col for (0, m-1)
            }
        }
        return false;
    }
};