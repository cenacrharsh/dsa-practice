#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> The problem can be divided into three subproblems:

* Find the middle of the list, and divide it into two equal parts.

* Reverse the second half of the linked list.

* Check if the first and second half are similar. If the linked list contains an odd number of nodes, then ignore the middle element.

* Get the original linked list back by reversing the second half again.
*/

struct Node
{
  int data;
  struct Node *next;
};

void forwardPrint(struct Node *head)
{
  if (head == NULL)
    return;

  struct Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

int compare(struct Node *head1, struct Node *head2)
{
  struct Node *curr1 = head1;
  struct Node *curr2 = head2;

  while (curr1 && curr2)
  {
    if (curr1->data == curr2->data)
    {
      curr1 = curr1->next;
      curr2 = curr2->next;
    }
    else
      return 0;
  }

  if (curr1 == NULL && curr2 == NULL)
    return 1;

  return 0;
}

void reverse(struct Node *&head)
{
  Node *result = NULL;
  Node *current = head;

  while (current != NULL)
  {
    Node *next = current->next;

    current->next = result;
    result = current;

    current = next;
  }

  head = result;
}

struct Node *findMiddle(struct Node *head, bool &odd)
{
  struct Node *prev = NULL;
  struct Node *slow = head, *fast = head;

  while (fast && fast->next)
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  if (fast)
    odd = true;

  prev->next = NULL;
  return slow;
}

int checkPalindrome(struct Node *head)
{
  if (head == NULL)
  {
    return 0;
  }

  if (head->next == NULL)
  {
    return 1;
  }

  bool odd = false;

  struct Node *mid = findMiddle(head, odd);

  if (odd)
    mid = mid->next;

  reverse(mid);

  int result = compare(head, mid);

  reverse(mid);

  return result;
}
