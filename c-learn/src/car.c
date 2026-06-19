#include "car.h"
#include <stdio.h>

Car car_init(char *brand, char *model, int year) {
  Car car = {
    .brand = brand, 
    .model = model, 
    .year = year,
  };
  return car;
}

void car_print(Car *car_ptr)
{
  printf("%s - %s - %d\n", car_ptr->brand, car_ptr->model, car_ptr->year);
}