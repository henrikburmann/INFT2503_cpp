#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
  for (auto &e : table)
    out << e << " ";
  return out;
}

int main() {
  vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  cout << "v1: " << v1 << endl;

  vector<int> v2 = {2, 3, 12, 14, 24};
  cout << "v2: " << v2 << endl;

  // a
  vector<int>::iterator it = find_if(v1.begin(), v1.end(),
                                     [](auto i) {
                                       return i > 15;
                                     });
  cout << "Første element over 15 er " << *it << endl;

  // b
  if (equal(v1.begin(), v1.begin() + 5, v2.begin(), [](int i, int j) {
        return abs(i - j) < 2;
      })) {
    cout << "Tabellene er like\n";
  } else {
    cout << "Tabellene er ikke like.\n";
  }

  if (equal(v1.begin(), v1.begin() + 4, v2.begin(), [](int i, int j) {
        return abs(i - j) < 2;
      })) {
    cout << "Tabellene er like\n";
  } else {
    cout << "Tabellene er ikke like.\n";
  }

  // c
  vector<int> copy_vector = {};
  copy_vector.resize(v1.size());
  replace_copy_if(
      v1.begin(), v1.end(), copy_vector.begin(), [](auto i) {
        return (i % 2) != 0;
      },
      100);
  cout << "V1 hvor oddetall er satt til 100: " << copy_vector << endl;
}
