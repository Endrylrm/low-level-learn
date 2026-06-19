#pragma once

typedef struct {
  char *name;
  int age;
} Person;

Person person_init(char *name, int age);
Person *person_new(const char *name, int age);
void person_destroy(Person *person_ptr);
void person_print(Person *person_ptr);
