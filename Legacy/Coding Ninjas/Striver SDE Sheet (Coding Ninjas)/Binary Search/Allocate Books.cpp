#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Z0hwjftStI4&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=19

/*
> Time Complexity: O(log (sum - max) base 2) * O(N)
> Space Complexity: O(1)
*/

int countStudents(vector<int> &arr, int maxPages)
{
    int students = 1;
    int totalPages = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (totalPages + arr[i] > maxPages)
        {
            students++;
            totalPages = arr[i];
        }
        else
        {
            totalPages += arr[i];
        }
    }
    return students;
}

//* low starts from not possible values as we need to go higher to be able to distribute books among m children, while high starts from possible values
int findPages(vector<int> &arr, int n, int m)
{
    //* min pages one can get is max(arr), any lower and that book can't be held by anyone
    //* max pages one can get is sum(arr), as if only 1 student is there he'll get all the books

    //* if num of students > num of books
    if (m > n)
    {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int noOfStudents = countStudents(arr, mid);
        if (noOfStudents <= m)
        {
            high = mid - 1; //* we need to minimise the maxPages allocated
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}