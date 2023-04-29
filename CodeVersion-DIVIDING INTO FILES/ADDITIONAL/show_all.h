#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <sys/stat.h>
#include "date.h"

struct Product {
    char name[100];
    int quantity;
    float price;
    };


void show_all(void) ;