#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Set

/*
> Time Complexity: O(N) => N is the number of elements inserted, or N * log(N) since internally it's sorted due to set
> Space Complexity: O(N)
*/

class SmallestInfiniteSet
{
private:
    set<int> s;

public:
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
        {
            s.insert(i);
        }
    }

    int popSmallest()
    {
        int smallest = *(s.begin()); // * gives value stored at that address
        s.erase(s.begin());
        return smallest;
    }

    void addBack(int num)
    {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */