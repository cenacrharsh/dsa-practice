#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=ZYpYur0znng

//! Approach 1 - Binary Search

/*
> Time Complexity: O(log (n * m) base 2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        //* we can think of it as a flattened array
        //* we have to convert 1D coordinates to 2D coordinates
        //* row -> 1D / total col. -> as every row has say m elements and due to 0 based indexing the first element of each row will be a multiple of m, hence to determine how many rows have passed we divide by m
        //* col -> 1D % total col. -> since every row contains m elements eg. m = 4 and we are on 9, 9 % 4 tells us 2 sets of 4 elements have passed and currently we are 1th coordinate of the curr row, or since first row element is multiple of m the next elements will have coordinate 1, 2, 3... upon % with m

        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = (n * m) - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (target > matrix[row][col])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};

//! Approach 2

//* check if element lies b/w first and last element of row, if yes apply binary search in that row

/*
> Time Complexity: O(n) * O(log (m) base 2)
> Space Complexity: O(1)
*/