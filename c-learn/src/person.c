#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Person person_init(char *name, int age) {
  Person person;
  person.name = name;
  person.age = age;
  return person;
}

Person *person_new(const char *name, int age) {
  Person *person_ptr = (Person*) malloc(sizeof(Person));

  if (person_ptr == NULL)
    return NULL;

  person_ptr->name = strdup(name);
  person_ptr->age = age;

  return person_ptr;
}

void person_destroy(Person *person_ptr) {
  if (person_ptr == NULL) {
    return;
  }

  free(person_ptr->name);
  free(person_ptr);
}

void person_print(Person *person_ptr)
{
  printf("my name is: %s\n", person_ptr->name);
  printf("my age is: %d\n", person_ptr->age);
}
