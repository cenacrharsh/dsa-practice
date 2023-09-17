#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class MyHashSet
{
public:
    vector<int> arr;

    MyHashSet()
    {
        arr.resize(1000001, false);
    }

    void add(int key)
    {
        arr[key] = true;
    }

    void remove(int key)
    {
        arr[key] = false;
    }

    bool contains(int key)
    {
        return arr[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */