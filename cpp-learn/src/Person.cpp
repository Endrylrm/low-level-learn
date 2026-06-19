#include "Person.h"
#include <iostream>
#include <string>

Person::Person(std::string n, int a) {
    name = n;
    age = a;
}

void Person::print()
{
  std::cout << "my name is: " << name << std::endl;
  std::cout << "my age is: " << age << std::endl;
}