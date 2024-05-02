#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Mh0NH_SD92k&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=19

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

Node * deleteAllOccurrences(Node* head, int k) {
    Node *temp = head;
    while(temp != NULL) {
        if(temp->data == k) {
            //* check if node is head, if yes we move it ahead
            if(temp == head) {
                head = temp->next;
            }
            Node *prevNode = temp->prev;
            Node *nextNode = temp->next;
            if(prevNode) {
                prevNode->next = nextNode;
            }
            if(nextNode) {
                nextNode->prev = prevNode;
            }
            free(temp);
            temp = nextNode;
        } else {
            temp = temp->next;
        }
    }
    return head;
}