#include <iostream>
using namespace std;

template <typename TypeA, typename TypeB>
class Pair {
public:
  Pair(TypeA first, TypeB second) : first(first), second(second) {}

  TypeA first;
  TypeB second;

  Pair operator+(const Pair &other) {
    double firstSum = this->first + other.first;
    double secondSum = this->second + other.second;
    Pair newPair(firstSum, secondSum);
    return newPair;
  }

  bool operator>(const Pair &other) {
    double sumThis = this->first + this->second;
    double sumOther = other.first + other.second;
    if (sumThis > sumOther) {
      return true;
    } else {
      return false;
    }
  }
};
int main() {
  Pair<double, int> p1(3.5, 14);
  Pair<double, int> p2(2.1, 7);
  cout << "p1: " << p1.first << ", " << p1.second << endl;
  cout << "p2: " << p2.first << ", " << p2.second << endl;

  if (p1 > p2)
    cout << "p1 er størst" << endl;
  else
    cout << "p2 er størst" << endl;

  auto sum = p1 + p2;
  cout << "Sum: " << sum.first << ", " << sum.second << endl;
}
// Forutsett at det du måtte trenge av ytterligere versjoner av operatorene + og > eksisterer. Hvilke forutsetninger gjør du?::
// Kronglete spørsmålsstilling, men om jeg forstår korrekt:
// Men metode for å sjekke om par er like eller større /mindre i tillegg til kun større mindre, aka >= og <=.
// En metode for å legge et par direkte til et annet: altså +=
