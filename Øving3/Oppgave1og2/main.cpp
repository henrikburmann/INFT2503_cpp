#include <iostream>
using namespace std;
const double pi = 3.141592;

class Circle {
public:
  Circle(double radius_); //Stor C i circle
  int get_area() const;
  double get_circumference() const;

private: //Manglet ":"
  double radius;
}; //Manglet ";"

Circle::Circle(double radius_) : radius(radius_) { //Feil rekkefølge på objektvariablen og parameteren.
}

int Circle::get_area() const { //Manglet const
  return pi * radius * radius;
}

//Både funksjonen og variablen manglet const
double Circle::get_circumference() const {
  double circumference = 2.0 * pi * radius;
  return circumference;
}

int main() {
  Circle circle(5);

  int area = circle.get_area();
  cout << "Arealet er lik " << area << endl;

  double circumference = circle.get_circumference();
  cout << "Omkretsen er lik " << circumference << endl;
}
