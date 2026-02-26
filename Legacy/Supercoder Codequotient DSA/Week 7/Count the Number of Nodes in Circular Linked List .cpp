#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct Node
{
 int data;
 Node *next;
};

int countNodes(Node *head)
{
 // Write your code here
 if (head == NULL)
 {
  return 0;
 }
 Node *temp = head;
 int count = 0;
 do
 {
  count++;
  temp = temp->next;
 } while (temp != head);
 return count;
}