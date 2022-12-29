#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>


/*struct Product {
  char name[100];
  int quantity;
  float price;
};*/


void update_product(char *name, int new_quantity, float new_price) {
  // Ouvrez le fichier en mode "lecture"
  FILE *fp = fopen("products.txt", "r");
  if (fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  // Créez un fichier temporaire pour stocker les lignes mises à jour
  FILE *temp_fp ;
  temp_fp = fopen("temp.txt", "w");
  if (temp_fp == NULL) {
    printf("Error creating temporary file!\n");
    exit(1);
  }

  // Créez une variable pour stocker chaque ligne lue dans le fichier
  char line[100];

  // Utilisez fgets() pour lire chaque ligne du fichier
  while (fgets(line, 100, fp) != NULL) {
    // Séparez les informations sur le produit en utilisant strtok()
    char *product_name = strtok(line, ",");
    char *quantity_str = strtok(NULL, ",");
    char *price_str = strtok(NULL, ",");

    // Si le nom du produit correspond à celui à mettre à jour, utilisez les nouvelles informations
    if (strcmp(product_name, name) == 0) {
      fprintf(temp_fp, "%s,%d,%.2f\n", name, new_quantity, new_price);
    }
    else {
      // Sinon, écrivez la ligne dans le fichier temporaire sans modification
      fprintf(temp_fp, "%s", line);
    }
  }

  // Fermez les fichiers
  fclose(fp);
  fclose(temp_fp);

  // Supprimez le fichier original
  remove("products.txt");

  // Renommez le fichier temporaire en "products.txt"
  rename("temp.txt", "products.txt");
}