#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial (Explanation) - https://www.youtube.com/watch?v=xDEuM5qa0zg
// # Tutorial (Code) - https://www.youtube.com/watch?v=Xc4sICC8m4M

//! Self Implemented Doubly LL & Unordered Map

/*
> Time Complexity: O(1) for get() and put()
> Space Complexity: O(1)
*/

class Node
{
public:
  int key;
  int val;
  Node *next;
  Node *prev;

  Node(int key, int val)
  {
    this->key = key;
    this->val = val;
    this->next = NULL;
    this->prev = NULL;
  }
};

class LRUCache
{
public:
  int capacity;
  Node *head;
  Node *tail;
  unordered_map<int, Node *> mp;

  LRUCache(int capacity)
  {
    this->capacity = capacity;
    mp.clear();
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  void deleteNode(Node *node)
  {
    Node *prevNode = node->prev;
    Node *nextNode = node->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;
  }

  void insertAfterHead(Node *newNode)
  {
    Node *nextNode = head->next;

    newNode->next = nextNode;
    newNode->prev = head;

    head->next = newNode;
    nextNode->prev = newNode;
  }

  int get(int key)
  {
    if (mp.find(key) == mp.end())
    {
      return -1;
    }

    Node *node = mp[key];

    //* put the accessed key to the front of the list
    deleteNode(node);
    insertAfterHead(node);

    return node->val;
  }

  void put(int key, int value)
  {
    //* if element is already present
    if (mp.find(key) != mp.end())
    {
      Node *node = mp[key];
      node->val = value;

      //* since it is recently accessed, put it in the front
      deleteNode(node);
      insertAfterHead(node);
    }
    else
    {
      //* if size == capacity, remove least recently used element
      if (mp.size() == capacity)
      {
        Node *node = tail->prev;
        mp.erase(node->key);
        deleteNode(node);
      }

      Node *newNode = new Node(key, value);
      mp[key] = newNode;
      insertAfterHead(newNode);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */