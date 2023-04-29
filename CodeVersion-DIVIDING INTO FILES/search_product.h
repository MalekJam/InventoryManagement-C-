#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>


struct Product {
  char name[100];
  int quantity;
  float price;
};


struct Product search_product(char *name);