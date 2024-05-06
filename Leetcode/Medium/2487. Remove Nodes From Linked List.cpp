#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp != NULL) {
            while(!st.empty() && temp->val > st.top()->val) {
                    st.pop();
            }
            st.push(temp);
            temp = temp->next;
        }

        //* build the LL in reverse order
        temp = st.top();
        st.pop();
        while(!st.empty()) {
            ListNode *currNode = st.top();
            st.pop();
            currNode->next = temp;
            temp = currNode;
        }
        return temp;
    }
};