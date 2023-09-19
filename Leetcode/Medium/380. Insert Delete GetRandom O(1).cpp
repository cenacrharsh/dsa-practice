#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=j4KwhBziOpg

class RandomizedSet
{
private:
    unordered_map<int, int> m;
    vector<int> v;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (m.find(val) == m.end())
        {
            v.push_back(val);
            m[val] = v.size() - 1; //* since we are pushing to back of array
            return true;
            /*
            // auto it = find(v.begin(), v.end(), val); -> find iterator of element in vector
            // int index = it - v.begin(); -> convert iterator to index
            */
        }
        return false;
    }

    bool remove(int val)
    {
        if (m.find(val) != m.end())
        {
            //* remove last element from array and place it in the index of element about to be removed
            int index = m[val];
            int lastElement = v.back();
            v[index] = v.back();
            v.pop_back();

            //* update the index of last element in map and erase the element about to be removed
            m[lastElement] = m[val];
            m.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        //* rand() function gives random value in the range of 0 to RAND_MAX(whose value is 32767). x%y gives
        //* remainder when x is divided by y and this remainder is in the range of 0 to y-1.
        //* rand()%a.size() gives random value in the range of (0 to a.size()-1).
        //* a[rand()%a.size()] will give random value of array in the range of a[0] to a[a.size()-1].
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */