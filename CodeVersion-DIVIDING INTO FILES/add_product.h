#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "./ADDITIONAL/date.c"
#include "add_history.h"

struct Product {
    char name[100];
    int quantity;
    float price;
};



void add_product(struct Product p1);

