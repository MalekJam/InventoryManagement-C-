#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "display_product.h"




void display_product(char name[100]) {
    /*#define bool unsigned int;
    #define true 1;
    #define false 0;*/
  // Ouvrez le fichier en mode "lecture"
  FILE *fp = fopen("products.txt", "r");
  if (fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  // Créez une variable pour stocker chaque ligne lue dans le fichier
  char line[100];

  // Utilisez fgets() pour lire chaque ligne du fichier
  while (fgets(line, 100, fp) != NULL) {
    // Séparez les informations sur le produit en utilisant strtok()
    int s;
    char *product_name = strtok(line, ",");
    char *quantity_str = strtok(NULL, ",");
    char *price_str = strtok(NULL, ",");
    // Si le nom du produit correspond à celui recherché, affichez les informations
    if (strcmp(product_name, name) == 0) {
        printf("\n\t\t            ***PRODUCT'S DESCRIPTION***\n");
        printf("\t\t  ================================================\n");
        printf("\t\t          NAME         ||     %-10s\n",product_name);
        printf("\t\t  ================================================\n");
        printf("\t\t          QUANTITY     ||     %s\n",quantity_str);
        printf("\t\t  ================================================\n");
        printf("\t\t          PRICE        ||     %s\n",price_str);
        printf("\t\t  ================================================");


	  /*printf("Product: %s\n",product_name);
      printf("Quantity: %s\n",quantity_str);
      printf("Price: %s\n",price_str);*/
      
    }
    else {
    
    printf("\n\t\t            the product doesn't exist\n");
    system("pause");

    }

  }

  // Fermez le fichier
  fclose(fp);
}