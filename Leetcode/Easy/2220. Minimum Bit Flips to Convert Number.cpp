#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=OOdrmcfZXd8&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=11

/*
> Time Complexity: O(Number of Set Bits) / O(Log(A ^ B)) for division approach by traversing on 31 bits and checking if each bit is 1 or not and break if 0 reached
> Space Complexity: O(1)
*/

class Solution {
public:
    int countSetBits(int num) {
        int count = 0;
        while(num != 0) {
            num = num & (num - 1); //* upon doing num & (num - 1) the rightmost set bit is turned off so until num becomes 0 the number of steps required is basically the count of 1's present in the number
            count++;
        }
        return count;
    }

    int minBitFlips(int start, int goal) {
        //* we'll use XOR, because it gives 1 when the bits are different and 0 when bits are same, so after XOR the number of set bits in start ^ goal would be our answer

        int temp = start ^ goal;
        int count = countSetBits(temp);
        return count;
    }
};