#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=9GMECGQgWrQ&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=34

int uniqueBinaryTree(int a, int b)
{
    //* we need inorder for unique binary tree construction, with either preordr or postorder
    if ((a == 2 || b == 2) && a != b)
    {
        return 1;
    }
    return 0;
}