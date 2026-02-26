#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=rjEJeYCasHs&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=12

/*
> Time Complexity: O(log (m) base 2) * O(log (n) base 2) => loop for m numbers * multiplication for n times using binary exponentiation
> Space Complexity: O()
*/

//* multiply mid n times
int func(int mid, int n, int m)
{
    //* return 1 if == m
    //* return 0 if < m
    //* return 2 if > m
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= mid;
        if (ans > m)
            return 2; //* to prevent overflow
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midPowerN = func(mid, n, m);
        if (midPowerN == 1)
            return mid;
        else if (midPowerN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}