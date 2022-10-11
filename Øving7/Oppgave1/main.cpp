#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}
int main() {

  // a
  Fraction a(6, 2);
  Fraction b(4, 2);
  print("Output a - 5 = ", a - 5); // Får -2/1
  print("Output 5 - a = ", 5 - a); // Får 2/1

  // B
  // 5 -3 vil beregnes først med standar bruk a "-".
  // Så vil a trekkes fra -2, og vi vil da bruke metoden som ikke er medlemfunksjon.
  // Deretter vil den andre medlemsfunksjonen vi lagde brukes for å trekke fra 7.
  // Siste operasjon er differansen mellom to typer av klassen "Fraction",
  // og dermed vil Fraction &operator-=(const Fraction &other) - brukes.
  cout << "Oppgave B" << endl;
  Fraction d = 5 - 3 - a - 7 - b; // Får - 10/1
  print("D: ", d);
}
