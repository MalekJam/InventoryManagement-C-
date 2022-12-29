#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "./ADDITIONAL/date.c"
#include "add_history.c"

struct Product {
    char name[100];
    int quantity;
    float price;
};



void add_product(struct Product p1) {
    struct Product p;
    p = (struct Product) p1;


    // Ouvrez le fichier en mode "append" pour ajouter des données à la fin du fichier
    FILE *fp;
    fp = fopen("products.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Écrivez les informations sur le produit dans le fichier
    fprintf(fp, "%s,%d,%f\n", p.name, p.quantity, p.price);

    // Fermez le fichier
    fclose(fp);

    //Enregistrer l'operation dans historique
    struct date dt = get_date();

    addH(p.name,"Added to the stock",p.quantity,dt.d,dt.m,dt.y);
}




