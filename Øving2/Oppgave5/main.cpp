#include <iostream>
using namespace std;
int main() {
  double number;
  double *a = &number;
  double &b = number;

  //Tilordning av verdi gjennom  verdioverføring
  number = 5;
  cout << "Metode 1. Verdi: " << number << endl;

  //Tilordning av verdi ved bruk av referanse
  b = 10;
  cout << "Metode 2. Verdi: " << number << endl;

  //Tilordning av verdi ved peker
  *a = 20;
  cout << "Metode 3. Verdi: " << number << endl;
}
