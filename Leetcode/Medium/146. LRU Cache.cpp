#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial (Explanation) - https://www.youtube.com/watch?v=xDEuM5qa0zg
//# Tutorial (Code) - https://www.youtube.com/watch?v=Xc4sICC8m4M

//! Self Implemented Doubly LL & Unordered Map

/*
> Time Complexity: O(1) for get() and put()
> Space Complexity: O()
*/

class LRUCache
{
public:
 class Node
 {
 public:
  int key;
  int value;
  Node *prev;
  Node *next;

  Node(int key, int value)
  {
   this->key = key;
   this->value = value;
   prev = NULL;
   next = NULL;
  }
 };

 Node *head;
 Node *tail;
 int capacity;
 unordered_map<int, Node *> cache;

 LRUCache(int capacity)
 {
  head = new Node(-1, -1);
  tail = new Node(-1, -1);
  head->next = tail;
  tail->prev = head;
  this->capacity = capacity;
 }

 void addNode(Node *newNode)
 {
  Node *temp = head->next;
  newNode->prev = head;
  newNode->next = temp;
  head->next = newNode;
  temp->prev = newNode;
 }

 void deleteNode(Node *delNode)
 {
  Node *delPrev = delNode->prev;
  Node *delNext = delNode->next;
  delPrev->next = delNext;
  delNext->prev = delPrev;
 }

 int get(int key)
 {
  if (cache.find(key) != cache.end()) //* node found in cache
  {
   Node *currNode = cache[key];
   int value = currNode->value;
   deleteNode(currNode);    //* delete node from list
   addNode(currNode);       //* add the node at head of list
   cache.erase(key);        //* erase previous entry of node is cache
   cache[key] = head->next; //* add new entry of node in cache
   return value;            //* return the value of the node
  }
  return -1;
 }

 void put(int key, int value)
 {
  if (cache.find(key) != cache.end()) //* node found in cache
  {
   Node *existingNode = cache[key];
   deleteNode(existingNode); //* delete node from list
   cache.erase(key);         //*  erase previous entry of node is cache
  }

  if (capacity == cache.size()) //* if cache is full
  {
   cache.erase(tail->prev->key); //* erase entry of LFU NODE from cache
   deleteNode(tail->prev);       //* delete LFU NODE from list
  }

  Node *newNode = new Node(key, value);
  addNode(newNode);        //* insert node with updated value in list
  cache[key] = head->next; //* mark entry of node in cache
 }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//! Inbuilt Doubly Linked List & Unordered Map

class LRUCache
{
 int capacity;
 list<pair<int, int>> li;
 //* li_iter->first: key, li_iter->second: value;
 unordered_map<int, list<pair<int, int>>::iterator> um;
 //* um_iter->first: key, um_iter->second: list iterator;

public:
 LRUCache(int capacity) : capacity{capacity} {}

 int get(int key)
 {
  if (um.find(key) == um.end()) //* key doesn't exist
   return -1;
  li.splice(li.begin(), li, um[key]); //* move the node corresponding to key to front
  return um[key]->second;             //* return value of the node
 }

 void put(int key, int value)
 {
  if (get(key) != -1) //* key exists, get will move node to front as well
  {
   um[key]->second = value; //* update value of the node
   return;
  }

  if (um.size() == capacity) //* reached capacity
  {
   int delKey = li.back().first;
   li.pop_back();    //* remove node in list;
   um.erase(delKey); //* remove key in map
  }

  li.emplace_front(key, value); //* create new node in list
  um[key] = li.begin();         //* create correspondence between key and node
 }
};

class LRUCache
{
 size_t m_capacity;
 unordered_map<int, list<pair<int, int>>::iterator> m_map; //* m_map_iter->first: key, m_map_iter->second: list iterator;
 list<pair<int, int>> m_list;                              //* m_list_iter->first: key, m_list_iter->second: value;
public:
 LRUCache(size_t capacity) : m_capacity(capacity)
 {
 }

 int get(int key)
 {
  auto found_iter = m_map.find(key);
  if (found_iter == m_map.end()) //* key doesn't exist
   return -1;
  m_list.splice(m_list.begin(), m_list, found_iter->second); //* move the node corresponding to key to front
  return found_iter->second->second;                         //* return value of the node
 }

 void set(int key, int value)
 {
  auto found_iter = m_map.find(key);

  if (found_iter != m_map.end()) //* key exists
  {
   m_list.splice(m_list.begin(), m_list, found_iter->second); //* move the node corresponding to key to front
   found_iter->second->second = value;                        //* update value of the node
   return;
  }

  if (m_map.size() == m_capacity) //* reached capacity
  {
   int key_to_del = m_list.back().first;
   m_list.pop_back();       //* remove node in list;
   m_map.erase(key_to_del); //* remove key in map
  }

  m_list.emplace_front(key, value); //* create new node in list
  m_map[key] = m_list.begin();      //* create correspondence between key and node
 }
};