#include <cstring>
#include <iostream>

using namespace std;
int main() {
  // Oppgave a
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;
  cout << "Oppgave A: " << endl;
  cout << "Adresse i: " << &i << ". Verdi i: " << i << endl;
  cout << "Adresse j: " << &j << ". Verdi j: " << j << endl;
  cout << "Adresse p: " << *p << ". Verdi p: " << p << endl;
  cout << "Adresse q: " << &q << ". Verdi q: " << q << endl;

  // p og q peker på adressene til henholdsvis i og j. Derfor vil verdien av p og q være adressene til i og j

  // Oppgave b
  *p = 7;
  *q += 4;
  *q = *p + 1;
  p = q;
  cout << *p << " " << *q << endl;
  // Verdien p peker på settes til 7, mens den q peker på økes med 4.
  // Verdien q peker på settes så lik  det p peker på pluss 1, altså 7 + 1.
  // p peker så på adressen som q peker på og de får samme verdi.
}
