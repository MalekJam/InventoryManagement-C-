#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "./ADDITIONAL/date.c"


void delete_product(char name[100]) {

    // Ouvrez le fichier en mode "lecture"
    FILE *fp ;
    fp= fopen("products.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Créez un fichier temporaire pour stocker les lignes à conserver
    FILE *temp_fp ;
    temp_fp= fopen("temp.txt", "a");
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

        // Si le nom du produit ne correspond pas à celui à supprimer, écrivez la ligne dans le fichier temporaire
        if (strcmp(product_name, name) != 0) {
            
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

    //Enregistrer l'operation dans historique
    struct date dt = get_date();

    addH(name,"Deleted from the stock",0,dt.d,dt.m,dt.y);
}