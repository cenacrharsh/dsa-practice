#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=nGGp5XBzC4g&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=28

/*
> Time Complexity: O(log (col) base 2) * O(n) => BS on columns and search for max element in each column taken O(n) time
> Space Complexity: O(1)
*/

class Solution
{
public:
    int findMaxRowIndex(vector<vector<int>> &mat, int col)
    {
        int maxValue = -1;
        int index = -1;
        for (int row = 0; row < mat.size(); row++)
        {
            if (mat[row][col] > maxValue)
            {
                maxValue = mat[row][col];
                index = row;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        //* we can do BS on either rows or cols

        //* suppose we chose cols, then in curr col by choosing the max element we achive 1D behaviour as the max element in col is automatically > than it's top and bottom element hence only left and right remains

        //* also if any element on left or right > curr ele we move in that direction but it might be possible that the new col has some element > the one we moved to, but in that case also since the element we moved to was > the prev col max element and hence the entire prev col, so it automatically means that in curr col the element > our element, will also be > the entire prev col so by eliminating that half we are not missing anything

        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1; //* BS on cols
        while (low <= high)
        {
            int mid = (low + high) / 2;

            int maxRowIndex = findMaxRowIndex(mat, mid);

            int left = mid - 1 > 0 ? mat[maxRowIndex][mid - 1] : -1;
            int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : -1;

            if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
            {
                return {maxRowIndex, mid};
            }
            else if (mat[maxRowIndex][mid] < left)
            {
                high = mid - 1; //* element of left is higher
            }
            else
            {
                low = mid + 1; //* element on right is higher
            }
        }
        return {-1, -1};
    }
};