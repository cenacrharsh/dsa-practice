#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=YJKVTnOJXSY&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=21

//! Approach 1

Node * removeDuplicates(Node *head)
{
    Node *temp = head;
    while(temp != NULL && temp->next != NULL) {
        //* find first node which is not equal to current node
        Node *nextNode = temp->next;
        while(nextNode != NULL && nextNode->data == temp->data) {
            Node *duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if(nextNode != NULL) {
            nextNode->prev = temp;
        }
        temp = temp->next;
    }
    return head;
}

//! Approach 2

Node * removeDuplicates(Node *head)
{
    Node *temp = head;
    while(temp->next != NULL) {
        if(temp->data == temp->next->data) {
            Node *deleteNode = temp->next;
            temp->next = temp->next->next;
            free(deleteNode);
        } else {
            temp = temp->next;
        }
    }
    return head;
}