#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Q9wXgdxJq48&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=29

/*
> Time Complexity: O(log (maxElement - minElement)) + O(n * log (cols) base 2) => BS + findSmallerEquals for every mid element
> Space Complexity: O(1)
*/

int upperBound(vector<int> &arr, int target)
{
    //* smallest index i where arr[i] > target
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

//* find number of elements <= element in the matrix
int findSmallerEquals(vector<vector<int>> &matrix, int target)
{
    //* upper_bound(target) return index of first element > target, hence all elements to the left of the index are < target
    int count = 0;
    for (int row = 0; row < matrix.size(); row++)
    {
        int index = upperBound(matrix[row], target);
        count += index; //* since 0 based indexing, if index 3 we have 3 elements <= target
    }
    return count;
}

int median(vector<vector<int>> &matrix, int rows, int cols)
{
    //* int n = rows * cols, also rows and cols is odd so n is always odd so the median element will always have n/2 elements on it's either side
    //* since duplicate elements can be present we can't say all elements to the left of median will be < median so we'll use <=
    //* since we are using <=, the number of elements <= median will always be greater than n/2, as we are counting the median element as well, with or withour duplicates we'll have n/2 + 1(median) elements anyways
    //* so the first element which has <= element > n/2 in flattened array is our ans
    //* range of BS lies in b/w lowest and highest element of matrix

    int low = INT_MAX;  //* lies in first col
    int high = INT_MIN; //* lies in last col
    for (int row = 0; row < rows; row++)
    {
        low = min(low, matrix[row][0]);
        high = max(high, matrix[row][cols - 1]);
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int numSmallerEquals = findSmallerEquals(matrix, mid);

        if (numSmallerEquals <= (rows * cols) / 2)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}