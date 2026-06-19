#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
public:
  std::string name;
  int age;

  Person(std::string n, int a);
  void print();
};

#endif // PERSON_H