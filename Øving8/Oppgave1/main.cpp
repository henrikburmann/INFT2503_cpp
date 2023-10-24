#include <iostream>

using namespace std;
template <typename Type>
bool equalFunc(Type a, Type b) {
  if (a == b) {
    return true;
  } else {
    return false;
  }
}

bool equalFunc(double a, double b) {
  if (abs(a - b) < 0.00001) {
    return true;
  } else {
    return false;
  }
}
int main() {
  cout << equalFunc(23, 23) << endl;
  cout << equalFunc(2.2, 2.9) << endl;
}
