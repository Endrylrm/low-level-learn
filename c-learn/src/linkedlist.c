#include "linkedlist.h"
#include "logging.h"
#include <stdlib.h>
#include <stdio.h>

static Node_T node_init(int value);
static Node_T *node_new(int value);
static Node_T node_copy(const Node_T* node);

static Node_T node_init(int value) {
    Node_T n;
    n.value = value;
    n.next = NULL;
    return n;
}

static Node_T *node_new(int value) {
    Node_T *n = (Node_T*) malloc(sizeof(Node_T));

    if (n == NULL)
        return NULL;

    n->value = value;
    n->next = NULL;

    return n;
}

static Node_T node_copy(const Node_T* node) {
    if (node == NULL) {
        log_error("trying to copy a null value.");

        // just return a "null node"
        Node_T invalid = {0};
        return invalid;
    }

    return *node;
}

LinkedList linkedlist_init(void) {
    LinkedList list = {
        .head = NULL,
        .size = 0,
    };
    return list;
}

LinkedList *linkedlist_new(void) {
    LinkedList *list = malloc(sizeof(LinkedList));

    if (list == NULL)
        return NULL;

    *list = linkedlist_init();

    return list;
}

void linkedlist_push_back(LinkedList *list, int value) {
    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return;
    }

    if (list->head == NULL) {
        linkedlist_push_front(list, value);
        return;
    }

    Node_T *new_node = node_new(value);

    if (new_node == NULL)
        return;

    Node_T *cur_node = list->head;

    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
    }

    cur_node->next = new_node;
    list->size++;
}

void linkedlist_push_front(LinkedList *list, int value) {
    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return;
    }

    Node_T *new_node = node_new(value);

    if (new_node == NULL)
        return;

    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void linkedlist_push_at(LinkedList *list, int value, size_t index) {
    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return;
    }

    if (index > list->size) {
        log_error("Out of bounds!");
        return;
    }

    if (index == 0 || list->head == NULL) {
        linkedlist_push_front(list, value);
        return;
    }

    Node_T *new_node = node_new(value);

    if (new_node == NULL)
        return;

    Node_T *cur_node = list->head;
    Node_T *prev_node = NULL;

    for (size_t i = 0; i < index; i++) {
        prev_node = cur_node;
        cur_node = cur_node->next;
    }

    new_node->next = cur_node;
    prev_node->next = new_node;
    list->size++;
}

int linkedlist_pop_back(LinkedList *list) {
    int node_value = -1;

    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return node_value;
    }

    Node_T *cur_node = list->head;

    if (cur_node == NULL) {
        log_error("trying to pop a empty list!");
        return node_value;
    }

    if (cur_node->next == NULL) {
        node_value = cur_node->value;
        free(cur_node);
        list->size = 0;
        list->head = NULL;
        return node_value;
    }

    while (cur_node->next->next != NULL) {
        cur_node = cur_node->next;
    }

    node_value = cur_node->next->value;
    free(cur_node->next);
    cur_node->next = NULL;
    list->size--;
    return node_value;
}

int linkedlist_pop_front(LinkedList *list) {
    int node_value = -1;

    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return node_value;
    }

    if (list->head == NULL) {
        log_error("trying to pop a empty list!");
        return node_value;
    }

    node_value = list->head->value;
    Node_T *next = list->head->next;
    free(list->head);
    list->head = next;
    list->size--;
    return node_value;
}

int linkedlist_pop_at(LinkedList *list, size_t index) {
    int node_value = -1;

    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return node_value;
    }

    if (index >= list->size) {
        log_error("Out of bounds!");
        return node_value;
    }

    if (list->head == NULL) {
        log_error("trying to pop a empty list!");
        return node_value;
    }

    if (index == 0) {
        return linkedlist_pop_front(list);
    }

    size_t count = 0;
    Node_T *cur_node = list->head;
    Node_T *prev_node = NULL;

    while (cur_node != NULL && count < index) {
        prev_node = cur_node;
        cur_node = cur_node->next;
        count++;
    }

    node_value = cur_node->value;
    prev_node->next = cur_node->next;
    free(cur_node);
    list->size--;
    return node_value;
}

void linkedlist_remove_back(LinkedList *list) {
    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return;
    }

    Node_T *cur_node = list->head;

    if (cur_node == NULL) {
        log_error("trying to pop a empty list!");
        return;
    }

    if (cur_node->next == NULL) {
        free(cur_node);
        list->size = 0;
        list->head = NULL;
        return;
    }

    while (cur_node->next->next != NULL) {
        cur_node = cur_node->next;
    }

    free(cur_node->next);
    cur_node->next = NULL;
    list->size--;
}

void linkedlist_remove_front(LinkedList *list) {
    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return;
    }

    if (list->head == NULL) {
        log_error("trying to remove from a empty list!");
        return;
    }

    Node_T *next = list->head->next;
    free(list->head);
    list->head = next;
    list->size--;
}

void linkedlist_remove_at(LinkedList *list, size_t index) {
    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return;
    }

    if (index >= list->size) {
        log_error("Out of bounds!");
        return;
    }

    if (list->head == NULL) {
        log_error("trying to remove from a empty list!");
        return;
    }

    if (index == 0) {
        linkedlist_remove_front(list);
        return;
    }

    size_t count = 0;
    Node_T *cur_node = list->head;
    Node_T *prev_node = NULL;

    while (cur_node != NULL && count < index) {
        prev_node = cur_node;
        cur_node = cur_node->next;
        count++;
    }

    prev_node->next = cur_node->next;
    free(cur_node);
    list->size--;
}

Node_T *linkedlist_find(LinkedList *list, int value) {
    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return NULL;
    }

    if (list->head == NULL) {
        log_error("trying to find from a empty list!");
        return NULL;
    }

    Node_T *cur_node = list->head;

    while (cur_node != NULL) {
        if (cur_node->value == value) {
            break;
        }
        cur_node = cur_node->next;
    }

    return cur_node;
}

Node_T *linkedlist_find_at(LinkedList *list, size_t index) {
    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return NULL;
    }

    if (index >= list->size) {
        log_error("Out of bounds!");
        return NULL;
    }

    if (list->head == NULL) {
        log_error("trying to find from a empty list!");
        return NULL;
    }

    if (index == 0) {
        return list->head;
    }

    Node_T *cur_node = list->head;

    size_t count = 0;
    while (cur_node != NULL && count < index) {
        cur_node = cur_node->next;
        count++;
    }

    return cur_node;
}

LinkedList *linkedlist_find_all(LinkedList *list, int value) {
    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return NULL;        
    }

    LinkedList *new_list = linkedlist_new();

    if (new_list == NULL) {
        log_error("Failed to allocate memory!");
        return NULL;
    }

    if (list->head == NULL) {
        return new_list;
    }

    Node_T *cur_node = list->head;

    while (cur_node != NULL) {
        if (cur_node->value == value) {
            linkedlist_push_back(new_list, cur_node->value);
        }
        cur_node = cur_node->next;
    }

    return new_list;
}

size_t linkedlist_length(LinkedList *list) {
    if (list == NULL) {
        return 0;
    }

    return list->size;
}

void linkedlist_clear(LinkedList *list) {
    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return;
    }

    if (list->head == NULL) {
        log_error("trying to clear a empty list!");
        return;
    }

    Node_T *cur_node = list->head;

    while (cur_node != NULL) {
        Node_T *next = cur_node->next;
        free(cur_node);
        cur_node = next;
    }

    list->head = NULL;
    list->size = 0;
}

void linkedlist_print(LinkedList *list)
{
    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return;
    }

    Node_T *cur_node = list->head;

    if(cur_node == NULL) {
        printf("Linked List is empty!\n");
        printf("current size: %u\n", list->size);
        return;
    }

    while (cur_node->next != NULL) {
        printf("%d -> ", cur_node->value);
        cur_node = cur_node->next;
    }
    printf("%d", cur_node->value);
    printf("\n");
    printf("current size: %u\n", list->size);
}

void linkedlist_destroy(LinkedList *list) {
    if (list == NULL) {
        log_error("Linked List is NULL, please put a valid linked list!");
        return;
    }

    linkedlist_clear(list);
    free(list);
}