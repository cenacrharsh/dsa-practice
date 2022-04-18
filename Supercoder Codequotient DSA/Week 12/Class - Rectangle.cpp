#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Rectangle
{
 int x, y, width, height;

public:
 Rectangle(int x, int y, int width, int height)
 {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
 }
 int getHeight()
 {
  return height;
 }
 int getWidth()
 {
  return width;
 }
 int getX()
 {
  return x;
 }
 int getY()
 {
  return y;
 }
 string toString()
 {
  string X = to_string(x);
  string Y = to_string(y);
  string W = to_string(width);
  string H = to_string(height);
  return ("Rectangle[x=" + X + ",y=" + Y + ",width=" + W + ",height=" + H + "]");
 }
};
