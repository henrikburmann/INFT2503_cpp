#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> tall;
  tall.emplace_back(1);
  tall.emplace_back(2);
  tall.emplace_back(3);
  tall.emplace_back(4);
  tall.emplace_back(5);
  cout << tall.front() << endl;
  cout << tall.back() << endl;

  tall.emplace(tall.begin() + 1, 100);
  cout << tall.front() << endl;

  const int number_to_find = 3;

  auto svar = find(tall.begin(), tall.end(), number_to_find);

  if (svar == tall.end()) {
    cout << "Verdi ikke funnet" << endl;
  } else {
    cout << number_to_find << " ble funnet." << endl;
  }
}
