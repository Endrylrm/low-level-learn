#include <iostream>
#include <string>
#include "Person.h"
#include "LinkedList.h"
#include "SmartLinkedList.h"

int main()
{
  Person p = Person("Endryl", 28);
  p.print();

  LinkedList<int> int_list;
  int_list.push(4);
  int_list.push(5);
  int_list.push(6);
  int_list.print();
  int popped_int = int_list.pop();
  std::cout << "Popped Value: " << popped_int << std::endl;
  int_list.clear();
  int_list.print();

  LinkedList<std::string> str_list;
  str_list.push("teste");
  str_list.push("teste 2");
  str_list.push("teste 3");
  str_list.push("teste 4");
  str_list.print();
  std::string popped_str = str_list.pop();
  std::cout << "Popped Value: " << popped_str << std::endl;

  SmartLinkedList<int> smart_int_list;
  smart_int_list.push(4);
  smart_int_list.push(5);
  smart_int_list.push(6);
  smart_int_list.push_front(3);
  smart_int_list.print();
  int smart_popped_int = smart_int_list.pop_back();
  std::cout << "Popped Value: " << smart_popped_int << std::endl;
  smart_int_list.clear();
  smart_int_list.print();

  int num = 15;
  std::cout << num << std::endl;

  std::string myText = "teste";
  std::cout << myText << std::endl;
  return 0;
}