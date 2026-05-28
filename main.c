#include "../include/tableau_statique.h"
int main() {
    int taille;
    do {
        printf("Entrez le nombre de patients : ");
        scanf("%d", &taille);
    }while (taille <= 0 || taille > 100); // Limiter la taille du tableau à 100
    patient tableau[100];
    remplir_patient(tableau, taille);
    afficher_patient(tableau, taille);
    return 0;
}