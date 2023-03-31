#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Floyd's Cycle-Detection Algorithm (Slow & Fast pointers)
class Solution
{
public:
    int getNextNumber(int n)
    {
        int sumOfSq = 0;
        while (n > 0)
        {
            int lastDigit = n % 10;
            sumOfSq += (lastDigit * lastDigit);
            n = n / 10;
        }
        return sumOfSq;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = getNextNumber(n);
        /*
        If n is a happy number, i.e. there is no cycle, then the fast runner will eventually get to 1 before the slow runner.
        If n is not a happy number, then eventually the fast runner and the slow runner will be on the same number.
        */
        while (fast != 1 && slow != fast)
        {
            slow = getNextNumber(slow);
            fast = getNextNumber(getNextNumber(fast));
        }

        return fast == 1;
    }
};

//! Using Hashmap to detect cycle
class Solution
{
public:
    int getNextNumber(int n)
    {
        int sumOfSq = 0;
        while (n > 0)
        {
            int lastDigit = n % 10;
            sumOfSq += (lastDigit * lastDigit);
            n = n / 10;
        }
        return sumOfSq;
    }

    bool isHappy(int n)
    {
        unordered_set<int> unique;
        // loop until n != 1 and n does'nt exist already
        while (n != 1 && unique.find(n) == unique.end())
        {
            unique.insert(n);
            n = getNextNumber(n);
        }
        return n == 1;
    }
};

//* or

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> unique;
        while (true)
        {
            int sumOfSq = 0;
            while (n > 0)
            {
                int lastDigit = n % 10;
                sumOfSq += (lastDigit * lastDigit);
                n = n / 10;
            }

            if (sumOfSq == 1)
            {
                return true;
            }

            // if number exists in set, cycle detected
            if (unique.find(sumOfSq) != unique.end())
            {
                return false;
            }
            else
            {
                unique.insert(sumOfSq);
                n = sumOfSq;
            }
        }
    }
};