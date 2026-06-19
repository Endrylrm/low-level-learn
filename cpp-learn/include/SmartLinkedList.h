#ifndef SMARTLINKEDLIST_H
#define SMARTLINKEDLIST_H
#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T = int>
class SmartLinkedList
{
public:
  void push(T value) {
    push_back(value);
  }

  void push_back(T value) {
    std::unique_ptr<Node> new_node = std::make_unique<Node>(value);

    if (!head) {
      head = std::move(new_node);
      size++;
      return;
    }

    Node *cur_node = head.get();

    while (cur_node->next) {
      cur_node = cur_node->next.get();
    }

    cur_node->next = std::move(new_node);
    size++;
  }

  void push_front(T value) {
    std::unique_ptr<Node> new_node = std::make_unique<Node>(value);
    new_node->next = std::move(head);
    head = std::move(new_node);
    size++;
  }

  void push_at(T value, size_t index) {
    if (index > size) {
      throw std::out_of_range("Out of Bounds!");
    }

    if (index == 0 || !head) {
      push_front(value);
      return;
    }

    std::unique_ptr<Node> new_node = std::make_unique<Node>(value);

    Node *cur_node = head.get();

    size_t count = 0;
    while (cur_node && count < index - 1) {
      cur_node = cur_node->next.get();
      count++;
    }

    new_node->next = std::move(cur_node->next);
    cur_node->next = std::move(new_node);
    size++;
  }

  T pop() {
    return pop_back();
  }

  T pop_back() {
    if (!head) throw std::out_of_range("The Linked List is Empty!");

    if (!head->next) {
      T node_value = std::move(head->value);
      head.reset();
      size = 0;
      return node_value;
    }

    Node *cur_node = head.get();

    while (cur_node->next->next) {
      cur_node = cur_node->next.get();
    }

    T node_value = std::move(cur_node->next->value);
    cur_node->next.reset();
    size--;
    return node_value;    
  }

  T pop_front() {
    if (!head) {
      throw std::out_of_range("The Linked List is Empty!");
    }

    T node_value = std::move(head->value);
    head = std::move(head->next);
    size--;
    return node_value;
  }

  T pop_at(size_t index) {
    if (index >= size) {
      throw std::out_of_range("Out of bounds!");
    }

    if (!head) {
      throw std::out_of_range("The Linked List is Empty!");
    }

    if (index == 0) {
      return pop_front();
    }

    size_t count = 0;
    Node *cur_node = head.get();
    while (count < index - 1) {
      cur_node = cur_node->next.get();
      count++;
    }

    T old_node_value = std::move(cur_node->next->value);
    cur_node->next = std::move(cur_node->next->next);
    size--;
    return old_node_value;
  }

  void remove() {
    remove_back();
  }

  void remove_back() {
    if (!head) throw std::out_of_range("The Linked List is Empty!");

    if (!head->next) {
      head.reset();
      size = 0;
    }

    Node *cur_node = head.get();

    while (cur_node->next->next) {
      cur_node = cur_node->next.get();
    }

    cur_node->next.reset();
    size--;   
  }

  void remove_front() {
    if (!head) throw std::out_of_range("The Linked List is Empty!");

    head = std::move(head->next);
    size--;
  }

  void remove_at(size_t index) {
    if (index >= size) {
      throw std::out_of_range("Out of bounds!");
    }

    if (!head) {
      throw std::out_of_range("The Linked List is Empty!");
    }

    if (index == 0) {
      remove_front();
      return;
    }

    size_t count = 0;
    Node *cur_node = head.get();
    while (count < index - 1) {
      cur_node = cur_node->next.get();
      count++;
    }

    cur_node->next = std::move(cur_node->next->next);
    size--;
  }

  void print() {
    Node *cur_node = head.get();

    if(!cur_node) {
      std::cout << "Linked List is empty!" << std::endl;
      std::cout << "current size: " << size << std::endl;
      return;
    }

    while (cur_node->next) {
      std::cout << "[" << cur_node->value << "]" << " -> ";
      cur_node = cur_node->next.get();
    }
    std::cout << "[" << cur_node->value << "]" << std::endl;
    std::cout << "current size: " << size << std::endl;
  }

  size_t length() {
    return size;
  }

  void clear() {
    head.reset();
    size = 0;
  }
private:
  struct Node {
    T value;
    std::unique_ptr<Node> next;

    Node() {
      value = T{};
      next = nullptr;
    }

    Node(T v) {
      value = v;
      next = nullptr;
    }
  };

  std::unique_ptr<Node> head = nullptr;
  size_t size = 0;
};

#endif // SMARTLINKEDLIST_H