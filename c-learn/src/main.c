#include <stdio.h>
#include "logging.h"
#include "person.h"
#include "car.h"
#include "linkedlist.h"
#include "logging.h"

#include <stdio.h>

int main()
{
  printf("Hello World!\n");

  Person endryl_person = {.name = "Endryl", .age = 28};
  person_print(&endryl_person);

  Person *audren_person = person_new("Audren", 18);
  person_print(audren_person);
  person_destroy(audren_person);
  audren_person = NULL;

  Car ferrari_car = car_init("Ferrari", "458", 2009);
  car_print(&ferrari_car);

  LinkedList list_stack = linkedlist_init();
  linkedlist_push_front(&list_stack, 0);
  linkedlist_push_back(&list_stack, 5);
  linkedlist_push_back(&list_stack, 10);
  linkedlist_push_back(&list_stack, 15);
  linkedlist_print(&list_stack);
  linkedlist_push_front(&list_stack, 20);
  linkedlist_push_at(&list_stack, 25, 5);
  linkedlist_print(&list_stack);
  int popped_node_value = linkedlist_pop_at(&list_stack, 6);
  printf("Popped Node value: %d\n", popped_node_value);
  linkedlist_remove_back(&list_stack);
  linkedlist_print(&list_stack);
  linkedlist_clear(&list_stack);
  linkedlist_print(&list_stack);
  linkedlist_clear(&list_stack);

  LinkedList *list_heap = linkedlist_new();
  linkedlist_push_back(list_heap, 5);
  linkedlist_push_back(list_heap, 10);
  linkedlist_push_front(list_heap, 0);
  linkedlist_push_at(list_heap, 25, 3);
  linkedlist_remove_at(list_heap, 3);
  linkedlist_print(list_heap);
  // destroy clears and frees list
  linkedlist_destroy(list_heap);
  list_heap = NULL;

  int num = 0;

  for (int i = 0; i < 10; i++) {
    num += i;
  }

  printf("Final value: %d\n", num);

  int even = 0;

  while (even < 10) {
    even++;

    if (even % 2 == 1) {
        continue;
    }

    printf("The number %d is even.\n", even);
  }

  char *myText = "teste";
  printf("%s\n", myText);
  return 0;
}
