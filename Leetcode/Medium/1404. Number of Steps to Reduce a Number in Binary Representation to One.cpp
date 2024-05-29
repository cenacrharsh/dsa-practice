#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=dGXlfGI9DvQ

//! Bit Manipulation

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution {
public:
    int numSteps(string s) {
        //* if rightmost bit is 1 -> odd, if rightmost bit is 0 -> even
        int carry = 0, ans = 0;

        //* we leave the last bit as it is as we have to stop as soon as we reach 1, else we'll see 1 and start again by adding 1 and getting 0 with carry 1 and so on but if we skip last digit we might have a leftover carry so what we do is ans + carry => if carry = 0 then we add 0 to ans because 1 + 0 = 1 and hence no change, but if carry = 1 then 1 + 1 = 10 which will give same result as else block i.e do right shift and get 1 which now acts as last digit
        for(int i = s.size() - 1; i >= 1; i--) {
            //* if rightmost set bit is 1 i.e odd number, we have to add 1 (Step 1), and when we do 1 + 1 we always get 0 with a carry = 1, and since last digit 0 means even we have to divide by 2 or right shift (Step 2)
            if((s[i] - '0' + carry) % 2 == 1) {
                ans += 2;
                carry = 1;
            } else {
                //* in case of even, rightmost bit is 0 and 0 + carry => 0 + 1 = 1 and 0 + 0 = 0, so basically carry remains whatever it was either 0/1 and just have to do a divide by 2 or right shift (Step 1) in this case
                ans += 1;
            }
        }
        return ans + carry;
    }
};