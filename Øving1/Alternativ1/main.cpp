#include <iostream>

//Løsing ved bruk av input fra bruker
using namespace std;
int main() {
  const int length = 5;
  int low = 0;
  int middle = 0;
  int high = 0;
  cout << "Skriv inn 5 temperaturer: " << endl;

  for (int i = 0; i < length; i++) {
    cout << "Skriv inn tall nummer " << i + 1 << " ";
    double temprature = 0;
    cin >> temprature;
    12 cout << endl;
    if (temprature < 10) {
      low++;
    } else if (temprature >= 10 && temprature <= 20) {
      middle++;
    } else {
      high++;
    }
  }

  cout << "Antall under 10: " << low << endl;
  cout << "Antall mellom 10 og 20: " << middle << endl;
  cout << "Antall over 20: " << high << endl;
}
