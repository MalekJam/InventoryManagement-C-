#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>


struct Product {
  char name[100];
  int quantity;
  double price;
};

void display_product(char name[100]);