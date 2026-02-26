#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=WqGb7159h7Q&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=8

/*
> Time Complexity: O(1)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int findXORfrom1ToN(int n)
    {
        if (n % 4 == 1)
            return 1;
        else if (n % 4 == 2)
            return n + 1;
        else if (n % 4 == 3)
            return 0;
        else
            return n;
    }

    int findXOR(int l, int r)
    {
        /*
            by observation we find that:
            N % 4 == 1 => XOR of numbers from 1 -> N is 1
            N % 4 == 2 => XOR of numbers from 1 -> N is N + 1
            N % 4 == 3 => XOR of numbers from 1 -> N is 0
            N % 4 == 0 => XOR of numbers from 1 -> N is N
        */

        return findXORfrom1ToN(l - 1) ^ findXORfrom1ToN(r);
    }
};