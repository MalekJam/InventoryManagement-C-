#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>


struct Product {
  char name[100];
  int quantity;
  float price;
};


void update_product(char *name, int new_quantity, float new_price);