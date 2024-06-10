#include "laptop.h"

Laptop::Laptop() {}

void Laptop::setYear(int yearConstruction) {
  this->yearConstruction = yearConstruction;
}

void Laptop::setStatusWork(bool statusWork) {
  this->statusWork = statusWork;
}

void Laptop::setPrice(double price) {
  this->price = price;
}
void Laptop::setGrade(char grade) {
  this->grade = grade;
}
int Laptop::getYearConstruction() {
  return yearConstruction;
}

bool Laptop::getStatusWork() {
  return statusWork;
}

double Laptop::getPrice() {
  return price;
}

char Laptop::getGrade() {
  return grade;
}

QString Laptop::toString() {
  return "\n" + QString::number(getPrice()) + delimiter + getGrade() +
         delimiter + QString::number(getYearConstruction()) + delimiter +
         QString::number(getStatusWork() + '\n');
}
