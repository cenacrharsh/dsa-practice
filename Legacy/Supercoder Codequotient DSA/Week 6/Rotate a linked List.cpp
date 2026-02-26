#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

struct node
{
 int data;
 node *next;
};

class LinkedList
{
public:
 node *head, *tail;

 LinkedList()
 {
  head = NULL;
  tail = NULL;
 }

 void createnode(int value)
 {
  node *temp = new node;
  temp->data = value;
  temp->next = NULL;
  if (head == NULL)
  {
   head = temp;
   tail = temp;
   temp = NULL;
  }
  else
  {
   tail->next = temp;
   tail = temp;
  }
 }

 void display()
 {
  node *temp = new node;
  temp = head;
  while (temp != NULL)
  {
   cout << temp->data << " ";
   temp = temp->next;
  }
 }

 void rotateList(int k);
};

// node *head, *tail; already created in class LinkedList
void LinkedList ::rotateList(int k)
{
 if (head == NULL || k < 1)
 {
  return;
 }

 node *curr = head;
 node *prev = NULL;

 int i = 1;
 while (i <= k && curr != NULL)
 {
  prev = curr;
  curr = curr->next;
  i++;
 }

 // if k is greater or equal to the size of the list, then it will remain unchanged
 if (curr == NULL || curr->next == NULL)
 {
  return;
 }
 else
 {
  // last node of LL will now point to the head of the original list
  tail->next = head; //* 6 -> 1

  // (k+1)th node will become the head node of the rotated list, & kth node becomes the new tail of LL
  head = curr; //* head -> 5
  tail = prev; //* tail -> 4

  // kth node will become the last node of the rotated list
  prev->next = NULL; //* 4 -> NULL
 }
}

int main()
{
 int t, n, m, k;
 LinkedList head, t1, t2;
 cin >> n;
 while (n > 0)
 {
  cin >> m;
  head.createnode(m);
  n--;
 }
 cin >> k;
 head.rotateList(k);
 head.display();
 cout << endl;
 return 0;
}