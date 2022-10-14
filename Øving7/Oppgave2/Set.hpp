#pragma once
#include <vector>

using namespace std;
class Set {

public:
  vector<int> array;
  Set();
  Set(vector<int> array);
  void set(vector<int> array);
  Set operator<<(const Set &other);
  bool operator+=(const int &num);
  Set &operator=(const Set &other);
  void printMengde();
};
