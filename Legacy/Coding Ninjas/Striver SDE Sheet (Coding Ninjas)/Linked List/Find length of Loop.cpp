#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int findLength(Node *slow, Node *fast) {
    int count = 1;
    slow = slow->next;
    while(slow != fast) {
        count++;
        slow = slow->next;
    }
    return count;
}

int lengthOfLoop(Node *head) {
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return findLength(slow, fast);
        }
    }
    return 0;
}