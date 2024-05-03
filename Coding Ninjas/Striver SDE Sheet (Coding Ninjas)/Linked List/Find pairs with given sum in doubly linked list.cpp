#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=YitR4dQsddE&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=20

/*
> Time Complexity: O(N) + O(N)
> Space Complexity: O(1)
*/

Node* findTail(Node* head) {
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int, int>> ans;
    Node *left = head, *right = findTail(head);
    while(left->data < right->data) {
        if(left->data + right->data == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } else if(left->data + right->data < k) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }
    return ans;
}