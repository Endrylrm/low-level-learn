#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <stdexcept>

template <typename T = int>
class LinkedList
{
public:
  void push(T value) {
    push_back(value);
  }

  void push_back(T value) {
    Node *new_node = new Node(value);

    if (head == nullptr) {
      head = new_node;
      size++;
      return;
    }

    Node *cur_node = head;

    while (cur_node->next != nullptr) {
      cur_node = cur_node->next;
    }

    cur_node->next = new_node;
    size++;
  }

  void push_front(T value) {
    Node *new_node = new Node(value);
    new_node->next = head;
    head = new_node;
    size++;
  }

  T pop() {
    return pop_back();
  }

  T pop_back() {
    Node *cur_node = head;

    if (cur_node == nullptr) {
        throw std::out_of_range("Linked List is Empty!");
    }

    if (cur_node->next == nullptr) {
      T node_value = std::move(cur_node->value);
      delete cur_node;
      head = nullptr;
      size = 0;
      return node_value;
    }

    while (cur_node->next->next != nullptr) {
      cur_node = cur_node->next;
    }

    T node_value = std::move(cur_node->next->value);
    delete cur_node->next;
    cur_node->next = nullptr;
    size--;
    return node_value;    
  }

  T pop_front() {
    if (head == nullptr) {
      throw std::out_of_range("Linked List is Empty!");
    }

    T node_value = std::move(head->value);
    Node *next = head->next;
    delete head;
    head = next;
    size--;
    return node_value;
  }

  void remove() {
    return remove_back();
  }

  void remove_back() {
    Node *cur_node = head;

    if (cur_node == nullptr) {
      throw std::out_of_range("Linked List is Empty!");
    }

    if (cur_node->next == nullptr) {
      delete cur_node;
      head = nullptr;
      size = 0;
      return;
    }

    while (cur_node->next->next != nullptr) {
      cur_node = cur_node->next;
    }

    delete cur_node->next;
    cur_node->next = nullptr;
    size--; 
  }

  void remove_front() {
    if (head == nullptr) {
      throw std::out_of_range("Linked List is Empty!");
    }

    Node *next = head->next;
    delete head;
    head = next;
    size--;
  }


  void print() {
    Node *cur_node = head;

    if(cur_node == nullptr) {
      std::cout << "Linked List is empty!" << std::endl;
      std::cout << "current size: " << size << std::endl;
      return;
    }

    while (cur_node->next != nullptr) {
      std::cout << "[" << cur_node->value << "]" << " -> ";
      cur_node = cur_node->next;
    }
    std::cout << "[" << cur_node->value << "]" << std::endl;
    std::cout << "current size: " << size << std::endl;
  }

  size_t length() {
    return size;
  }

  void clear() {
    Node *cur_node = head;

    while (cur_node != nullptr) {
      Node *next = cur_node->next;
      delete cur_node;
      cur_node = next;
    }

    head = nullptr;
    size = 0;
  }

  ~LinkedList() {
    clear();
  }
private:
  struct Node {
    T value;
    Node *next;

    Node() {
      value = T{};
      next = nullptr;
    }

    Node(T v) {
      value = v;
      next = nullptr;
    }
  };

  Node *head = nullptr;
  size_t size = 0;
};

#endif // LINKEDLIST_H