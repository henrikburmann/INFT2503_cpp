#include <iostream>
using namespace std;
int main() {
  int a = 5;
  //Prøvde å opprette en referanse uten at den ble initisert
  int &b = a;
  int *c;
  c = &b;
  //A er en variabel, og B er også samme variabel under et annet alias. Skal derfor ikke dereferes for å addere verdien av c.
  a = b + *c;
  //&b er en adresse. Kan dermed ikke tilegnes en int-verdi. Må dermed dereferes.
  b = 2;
}
