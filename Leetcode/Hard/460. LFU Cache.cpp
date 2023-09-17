#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial (Explanation) - https://www.youtube.com/watch?v=0PSB9y8ehbk
//# Tutorial (Code) - https://www.youtube.com/watch?v=mzqHlAW7jeE

//! 2 Hashmap & Doubly Linked List for Each Freq

class Node
{
public:
 int key, value, count;
 Node *prev, *next;

 Node(int key, int value)
 {
  this->key = key;
  this->value = value;
  count = 1;
 }
};

class List
{
public:
 int size;
 Node *head, *tail;

 List()
 {
  head = new Node(0, 0);
  tail = new Node(0, 0);
  head->next = tail;
  tail->prev = head;
  size = 0;
 }

 void addNodeToFront(Node *node)
 {
  Node *temp = head->next;
  node->prev = head;
  node->next = temp;
  head->next = node;
  temp->prev = node;
  size++;
 }

 void removeNode(Node *node)
 {
  Node *delPrev = node->prev;
  Node *delNext = node->next;
  delPrev->next = delNext;
  delNext->prev = delPrev;
  size--;
 }
};

class LFUCache
{
 int maxCacheSize, minFreq, currSize;
 map<int, Node *> keyNodeMap;  //* key -> Node
 map<int, List *> freqListMap; //* freq -> List

public:
 LFUCache(int capacity)
 {
  maxCacheSize = capacity;
  minFreq = 0;
  currSize = 0;
 }

 void updateFreqListMap(Node *node)
 {
  //* remove node from it's curr freq list and erase it's entry in map
  keyNodeMap.erase(node->key);
  freqListMap[node->count]->removeNode(node);

  if (node->count == minFreq && freqListMap[node->count]->size == 0)
  {
   minFreq++;
  }

  List *nextHigherFreqList = new List();
  if (freqListMap.find(node->count + 1) != freqListMap.end())
  {
   nextHigherFreqList = freqListMap[node->count + 1];
  }
  node->count += 1;
  //* add node to it's updated freq list and make new entries of list and node in both maps
  nextHigherFreqList->addNodeToFront(node);

  freqListMap[node->count] = nextHigherFreqList;
  keyNodeMap[node->key] = node;
 }

 int get(int key)
 {
  //* if key already exists in cache
  if (keyNodeMap.find(key) != keyNodeMap.end())
  {
   Node *currNode = keyNodeMap[key];
   int value = currNode->value;
   updateFreqListMap(currNode);
   return value;
  }
  return -1;
 }

 void put(int key, int value)
 {
  if (maxCacheSize == 0)
  {
   return;
  }

  if (keyNodeMap.find(key) != keyNodeMap.end())
  {
   Node *node = keyNodeMap[key];
   node->value = value;
   updateFreqListMap(node);
  }
  else
  {
   //* if cache is full
   if (currSize == maxCacheSize)
   {
    List *list = freqListMap[minFreq];
    keyNodeMap.erase(list->tail->prev->key);
    freqListMap[minFreq]->removeNode(list->tail->prev);
    currSize--;
   }

   currSize++;
   //* new value has to be added which is not there previously, therefore minFreq = 1 now, since freq 1 list would have atleast one node now i.e. the curr node
   minFreq = 1;

   List *listFreq = new List();
   //* if a list with minFreq already exists
   if (freqListMap.find(minFreq) != freqListMap.end())
   {
    listFreq = freqListMap[minFreq];
   }

   Node *newNode = new Node(key, value);

   listFreq->addNodeToFront(newNode);
   keyNodeMap[key] = newNode;
   freqListMap[minFreq] = listFreq;
  }
 }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//! Using Inbuilt List & 3 HashMaps

class LFUCache
{
public:
 int capacity;
 unordered_map<int, pair<int, int>> cache;
 unordered_map<int, list<int>::iterator> listItrMap;
 unordered_map<int, list<int>> freqMap;
 int minFreq = 0;

 LFUCache(int capacity)
 {
  this->capacity = capacity;
 }

 int get(int key)
 {
  if (!cache.count(key))
   return -1;

  updateFrequency(key);
  return cache[key].first;
 }

 void put(int key, int value)
 {
  if (this->capacity <= 0)
   return;
  // if key is already in cache
  if (cache.count(key))
  {
   updateFrequency(key);
   cache[key].first = value; // update value in cache
  }
  else
  {
   if (cache.size() >= this->capacity)
   {
    // remove last-element in the least-frequent-list, from cache
    int leastFrequentKey = freqMap[minFreq].back();
    cache.erase(leastFrequentKey);
    listItrMap.erase(leastFrequentKey);

    // remove least frequent from freqMap
    freqMap[minFreq].pop_back();
   }

   // insert value and initialize frequency
   cache[key] = {value, 0};
   freqMap[0].push_front(key);
   listItrMap[key] = freqMap[0].begin();

   minFreq = 0; // reset min frequency
  }
 }

private:
 void updateFrequency(int key)
 {
  int freq = cache[key].second++;

  // remove from prev frequency list
  freqMap[freq].erase(listItrMap[key]);

  // append to updated frequency list
  freqMap[freq + 1].push_front(key);

  // update list pointer to new list begin
  listItrMap[key] = freqMap[freq + 1].begin();

  // remove empty lists incase minFrequency raises
  if (freqMap[minFreq].size() == 0)
  {
   freqMap.erase(minFreq++);
  }
 }
};