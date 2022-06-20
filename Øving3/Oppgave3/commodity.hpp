#pragma once

#include <iostream>
#include <string>

using namespace std;
const double tax = 0.25;
class Commodity {
public:
  Commodity(const string &name_, int id_, double price_);
  const string &get_name() const;
  int get_id() const;
  double get_price() const;
  double get_price(double quantity_) const;
  void set_price(double price_);
  double get_price_with_sales_tax();
  double get_price_with_sales_tax(double quantity);

private:
  string name;
  int id;
  double price;
};

Commodity::Commodity(const string &name_, int id_, double price_) : name(name_), id(id_), price(price_) {}

const string &Commodity::get_name() const {
  return name;
}
int Commodity::get_id() const {
  return id;
}
double Commodity::get_price() const {
  return price;
}

double Commodity::get_price(double quantity_) const {
  return price * quantity_;
}
void Commodity::set_price(double price_) {
  price = price_;
}
double Commodity::get_price_with_sales_tax() {
  return price * (1 + tax);
}
double Commodity::get_price_with_sales_tax(double quantity_) {
  return price * (1 + tax) * quantity_;
}
