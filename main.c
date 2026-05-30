#include "../projet_LMI2/tableau_statique.h"
int main() {
    int taille;
    do {
        printf("Entrez le nombre de patients : ");
        scanf("%d", &taille);
        getchar(); // Consommer le caractère de nouvelle ligne laissé par scanf
    }while (taille <= 0 || taille > 100); // Limiter la taille du tableau à 100
    patient tableau[100];
    remplir_patient(tableau, taille);
    afficher_patient(tableau, taille);
    inserer_Patient(tableau, &taille);
    while(getchar() != '\n'); // vider le buffer
    rechercher_patient(tableau, taille);
    return 0;
}