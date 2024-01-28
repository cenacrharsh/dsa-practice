#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=elADMOC_hDI

/*
> Time Complexity: O(row * col * col)
> Space Complexity: O(row)
*/

class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size(), col = matrix[0].size();

        // calculate prefix sum for each row
        for (int i = 0; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        //* for each pair of column (from c1 to c2), find the subarrays sum equal to target
        int count = 0;
        for (int c1 = 0; c1 < col; c1++)
        {
            for (int c2 = c1; c2 < col; c2++)
            {
                unordered_map<int, int> freq;
                freq[0] = 1; //* insert initial sum 0 in hashmap
                int sum = 0;
                for (int r = 0; r < row; r++)
                {
                    //* if c1 is > 0 we have to subtract the prefix sum value upto (c1 - 1)th column, also matrix[r][c2] will give us the prefix sum value upto c2th col, so with this we have the sum total of values in between col c1 and col c2
                    sum += matrix[r][c2] - (c1 > 0 ? matrix[r][c1 - 1] : 0);

                    count += freq[sum - target]; //* check if (sum - target) already exists in hashmap

                    freq[sum]++; //* insert sum in hashmap
                }
            }
        }
        return count;
    }
};