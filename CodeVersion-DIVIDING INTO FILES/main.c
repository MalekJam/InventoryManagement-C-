#include "add_product.c"
#include "display_product.c"
#include "see_history.c"
#include "search_product.c"
#include "update_product.c"
#include "delete_product.c"
#include "./ADDITIONAL/show_all.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



struct Product {
    char name[100];
    int quantity;
    float price;
};

struct date {
  char d[256];
  char m[256];
  int y;
};


int main() {
    printf("\n");
	printf("\t\t\t  ================================\n");
	printf("\t\t\t     STOCK-MANAGER PROGRAM\n");
	printf("\t\t\t  ================================\n\n");

    while (1) {
        // Affichez le menu
        printf("\n\n\t\t\t   \t     ***MENU***          \n");
        printf("\t\t\t   ------------------------------\n");
        printf("\t\t\t  |\t 1. Add product          |\n");
        printf("\t\t\t   ------------------------------\n");
        printf("\t\t\t  |\t 2. Display product      |\n");
        printf("\t\t\t   ------------------------------\n");
        printf("\t\t\t  |\t 3. Delete product       |\n");
        printf("\t\t\t   ------------------------------\n");
        printf("\t\t\t  |\t 4. Update product       |\n");
        printf("\t\t\t   ------------------------------\n");
        printf("\t\t\t  |\t 5. Search product       |\n");
        printf("\t\t\t   ------------------------------\n");
        printf("\t\t\t  |\t 6. Check history       |\n");
        printf("\t\t\t   ------------------------------\n");
        printf("\t\t\t  |\t 7. Exit                 |\n");
        printf("\t\t\t   ------------------------------");
        printf("\nEnter your choice: ");

        // Lit le choix de l'utilisateur
        int choice;
        scanf("%d", &choice);

        // Selon le choix de l'utilisateur, appelez la fonction correspondante
        switch (choice) {
        case 1:;
            // Ajouter un produit
            struct Product p ;
            char name[100];
            int quantity;
            float price;
            printf("\n\t\t                ***ADD PRODUCT***\n");
            printf("\t\t  ================================================\n");
            printf("\t\t          NAME         ||     ");
            scanf("%s",	&name);
            printf("\t\t  ================================================\n");
            printf("\t\t          QUANTITY     ||     ");
            scanf("%d", &quantity);
            printf("\t\t  ================================================\n");
            printf("\t\t          PRICE        ||     ");
            scanf("%f", &price);
            printf("\t\t  ================================================\n");
            strcpy(p.name,name);
            p.quantity=quantity;
            p.price=price;
            add_product(p);
            break;
        case 2:;
            // Afficher la description d'un produit
            show_all();
            char nom[100];
            printf("Enter product name: ");
            scanf("%s",&nom);
            display_product(nom);
            break;
        case 3:
            // Supprimer un produit
            show_all();
            printf("Enter product name: ");
            scanf("%s", name);
            delete_product(name);
            break;
        case 4:
            // Modifier un produit
            show_all();
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter new quantity: ");
            int quantit;
            scanf("%d", &quantit);
            printf("Enter new price: ");
            float pric;
            scanf("%f", &pric);
            update_product(name, quantit, pric);
            break;
        case 5:
            // Rechercher un produit
            printf("Enter product name: ");
            scanf("%s", name);
            struct Product p1 ;
            p1=  search_product(name) ;
            if(p.quantity != 0){
            printf("Product: %s\n", p.name);
            printf("Quantity: %d\n", p.quantity);
            printf("Price: %.2f\n", p.price);}
            else printf("\n\t\t            the product doesn't exist\n");
            break;
        case 6:
            //Voir le historie d'entres et de sorties
            seeH();
        case 7:
            // Quitter l'application
            return 0;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}
