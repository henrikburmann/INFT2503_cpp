#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

//Løsning for å lese fra fil

void read_temperatures(double temperatures[], int length);

int main() {
  int low = 0;
  int middle = 0;
  int high = 0;
  const int length = 5;
  double temperatures[length];
  read_temperatures(temperatures, length);
  for (int i = 0; i < length; i++) {
    if (temperatures[i] < 10) {
      low++;
    } else if (temperatures[i] >= 10 && temperatures[i] <= 20) {
      middle++;
    } else {
      high++;
    }
  }
  cout << "Antall under 10: " << low << endl;
  cout << "Antall mellom 10 og 20: " << middle << endl;
  cout << "Antall over 20: " << high << endl;
};

void read_temperatures(double temperatures[], int length) {
  const char filename[] = "Temperaturer.dat";
  ifstream file;
  file.open(filename);
  if (!file) {
    cout << "Funker ikke" << endl;
    exit(EXIT_FAILURE);
  }
  int number;

  for (int i = 0; i < length; i++) {
    file >> number;
    temperatures[i] = number;
  }
  file.close();
}
