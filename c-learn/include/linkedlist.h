#pragma once
#include <stdio.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node_T;

typedef struct {
  size_t size;
  Node_T *head;
} LinkedList;

typedef enum {
  LIST_OK,
  LIST_EMPTY,
  LIST_IS_NULL,
  LIST_OUT_OF_BOUNDS,
} LinkedListError;

LinkedList linkedlist_init(void);
LinkedList *linkedlist_new(void);
void linkedlist_push_back(LinkedList *list, int value);
void linkedlist_push_front(LinkedList *list, int value);
void linkedlist_push_at(LinkedList *list, int value, size_t index);
int linkedlist_pop_back(LinkedList *list);
int linkedlist_pop_front(LinkedList *list);
int linkedlist_pop_at(LinkedList *list, size_t index);
void linkedlist_remove_back(LinkedList *list);
void linkedlist_remove_front(LinkedList *list);
void linkedlist_remove_at(LinkedList *list, size_t index);
Node_T *linkedlist_find(LinkedList *list, int value);
Node_T *linkedlist_find_at(LinkedList *list, size_t index);
LinkedList *linkedlist_find_all(LinkedList *list, int value);
size_t linkedlist_length(LinkedList *list);
void linkedlist_clear(LinkedList *list);
void linkedlist_print(LinkedList *list);
void linkedlist_destroy(LinkedList *list);
