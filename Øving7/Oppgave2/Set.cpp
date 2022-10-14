#include "Set.hpp"
#include <iostream>
#include <string>

using namespace std;

Set::Set() : array(vector<int>()) {}
Set::Set(vector<int> array_) : array(array_){};

// Finner unionen.
Set Set::operator<<(const Set &other) {
  Set union_vector;
  for (size_t i = 0; i < other.array.size(); i++) {
    for (size_t j = 0; j <= this->array.size(); j++) {
      if (other.array[i] == this->array[j]) {
        union_vector.array.push_back(other.array[i]);
      }
    }
  }

  return union_vector;
};

bool Set::operator+=(const int &number) {
  for (size_t i = 0; i < this->array.size(); i++) {
    if (this->array[i] == number) {
      return false;
    }
  }
  this->array.push_back(number);
  return true;
}

Set &Set::operator=(const Set &other) {
  this->array = other.array;
  return *this;
}

void Set::printMengde() {
  for (size_t i = 0; i < this->array.size(); i++) {
    cout << this->array[i] << "  ";
  }
  cout << endl;
}
