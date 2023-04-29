#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <sys/stat.h>
#include "date.h"
#include "show_all.h"


void show_all(void) {
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

  struct stat st;
  stat("products.txt", &st); 
  if (st.st_size == 0){
    printf("Your Stock is Empty!");
    exit(1);}
  // Utilisez fgets() pour lire chaque ligne du fichier
  while (fgets(line, 100, fp) != NULL) {
    // Séparez les informations sur le produit en utilisant strtok()
    int s;
    char *product_name = strtok(line, ",");
    // Si le nom du produit correspond à celui recherché, affichez les informations
    
        printf("\n\t\t            ***ALL EXISTING PRODUCTS***\n");
        printf("\t\t  ================================================\n");
        printf("\t\t          NAME         ||                         \n");
        printf("\t\t  ================================================\n");
        printf("\t\t           %-10s\n",product_name);
        printf("\t\t  ================================================\n");
        


	  /*printf("Product: %s\n",product_name);
      printf("Quantity: %s\n",quantity_str);
      printf("Price: %s\n",price_str);*/
      
    

  }

  // Fermez le fichier
  fclose(fp);
}