#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
    •~num: Flips all the bits, including the leading zeros that represent the number in a 32-bit (or other) system. This can lead to unexpected results if you just want the bitwise complement of the number’s natural binary representation.

    •num ^ mask: Flips only the bits that are part of the number’s actual binary representation, ensuring the result is as expected for the size of the number.
*/

/*
    The expression 1U << mask_length involves shifting the bit 1 to the left by mask_length positions.

    Without U (just 1):
        •The literal 1 is treated as a signed integer (int) by default.
        •The left shift operation could potentially overflow if mask_length is large enough (e.g., when shifting by 31 positions on a 32-bit system).
        •For large inputs like 2147483647 (which is 2^31 - 1), the calculation of mask without the U suffix can result in undefined behavior because the resulting value might not fit into a signed integer.

    With 1U:
        •1U is treated as an unsigned integer (unsigned int).
        •The left shift operation now works within the bounds of an unsigned integer, which can handle larger values without overflow issues.
        •This ensures that the calculation of mask is correct, even for large values like 2147483647.

    Example:
    For an input num = 2147483647:
        •mask_length = log2(2147483647) + 1 = 31.
        •1U << 31 shifts 1 to the 31st bit position, resulting in 10000000000000000000000000000000 (which is 2147483648 in decimal).
        •Subtracting 1 gives 01111111111111111111111111111111 (which is 2147483647 in decimal), creating the correct mask.

    Without the U, the left shift might cause overflow, leading to incorrect results or even runtime errors.

    Summary:
        •1: Treated as int, which can overflow if shifted too far.
        •1U: Treated as unsigned int, which safely handles larger shifts and avoids overflow.

    Using 1U ensures that the shift operation produces a value that can be correctly stored and used in subsequent bitwise operations, especially when dealing with the maximum possible values for a 32-bit integer.
*/

class Solution
{
public:
    int findComplement(int num)
    {
        // Step 1: Calculate the bit length of num
        int maskLength = log2(num) + 1;

        // Step 2: Create a mask with all bits set to 1 of the bit length
        int mask = (1U << maskLength) - 1;

        // Step 3: XOR the number with the mask to flip the bits
        return num ^ mask;
    }
};