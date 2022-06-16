#include <iostream>
using namespace std;

int find_sum(const int *table, int length);

int main() {
  const int length = 20;
  int table[length];
  for (int i = 0; i < length; i++) {
    table[i] = (i + 1);
  }

  const int *pointer = table;
  //Sum av de første 10 tallene
  int sum = find_sum(pointer, 10);
  cout << sum << endl;

  //Sum av de neste 5 tallene
  pointer += 10;
  sum = find_sum(pointer, 5);
  cout << sum << endl;

  //Sum av de siste 5 tallene
  pointer += 5;
  sum = find_sum(pointer, 5);
  cout << sum << endl;
}

int find_sum(const int *table, int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += *table;
    table++;
  }
  return sum;
}
