#include "Set.hpp"
#include <iostream>
#include <vector>

using namespace std;
int main() {
  vector<int> arr = {1, 2, 3, 4, 6, 9, 5};
  Set a(arr);

  vector<int> arr2 = {1, 3, 5, 7, 8, 9};
  Set b(arr2);

  // Finner unionen
  cout << "\nOperator << " << endl;
  Set c = a << b;
  c.printMengde();

  cout << "\nOperator += " << endl;
  a += 2;  // Legges ikke til da den allerede er y arrayen
  a += 10; // Legges til
  a.printMengde();

  // Setter a sin array lik b sin array
  cout << "\nOperator = " << endl;
  a = b;
  a.printMengde();
}
