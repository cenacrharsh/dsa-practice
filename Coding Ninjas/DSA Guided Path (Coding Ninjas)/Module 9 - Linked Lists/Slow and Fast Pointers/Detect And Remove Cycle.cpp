#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Node
{
public:
 int data;
 Node *next;
 Node(int data)
 {
  this->data = data;
  this->next = NULL;
 }
};

/*
    Time Complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the number of nodes in the linked list.
*/

bool detectAndRemoveCycle(Node *head)
{
 if (head == NULL || head->next == NULL)
 {
  return false;
 }

 //  Slow Pointer - This will be incremented by 1 Nodes
 Node *slow = head->next;

 //  Fast Pointer  - This will be incremented by 2 Nodes
 Node *fast = head->next->next;

 while (slow != fast)
 {
  // We reached the end of the List and haven't found any Cycle
  if (fast == NULL || fast->next == NULL)
  {
   return false;
  }
  slow = slow->next;
  fast = fast->next->next;
 }

 // We found a cycle
 slow = head;

 // If cycle starts from head, i.e. circular LL
 if (slow == fast)
 {
  //* to stop at one node before start point of loop, so we can set it's next to NULL
  while (fast->next != slow)
  {
   fast = fast->next;
  }
 }
 else
 {
  //* to stop at one node before start point of loop, so we can set it's next to NULL
  while (slow->next != fast->next)
  {
   slow = slow->next;
   fast = fast->next;
  }
 }

 fast->next = NULL;

 return true;
}
