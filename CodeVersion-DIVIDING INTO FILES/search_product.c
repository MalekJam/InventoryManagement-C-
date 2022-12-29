#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>


/*struct Product {
  char name[100];
  int quantity;
  float price;
};*/


struct Product search_product(char *name) {
  // Ouvrez le fichier en mode "lecture"
  FILE *fp = fopen("products.txt", "r");
  if (fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  // Créez une variable de type Product pour stocker les informations sur le produit
  struct Product p;
  p.name[0] = '\0';
  p.quantity = 0;
  p.price = 0.0;

  // Créez une variable pour stocker chaque ligne lue dans le fichier
  char line[100];

  // Utilisez fgets() pour lire chaque ligne du fichier
  while (fgets(line, 100, fp) != NULL) {
    // Séparez les informations sur le produit en utilisant strtok()
    char *product_name = strtok(line, ",");
    char *quantity_str = strtok(NULL, ",");
    char *price_str = strtok(NULL, ",");

    // Si le nom du produit correspond à celui recherché, mettez à jour la variable de type Product
    if (strcmp(product_name, name) == 0) {
      strcpy(p.name, product_name);
      p.quantity = atoi(quantity_str);
      p.price = atof(price_str);
      break;
    }
    

  // Fermez le fichier
  fclose(fp);

  return p;
}}