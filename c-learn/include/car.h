#pragma once

typedef struct {
  char *brand;
  char *model;
  int year;
} Car;

Car car_init(char *brand, char *model, int year);
void car_print(Car *car_ptr);