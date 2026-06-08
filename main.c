#include "../projet_LMI2/tableau_statique.h"
#include "tableau_dynamique.h"
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
    supprimer_patient(tableau, &taille);
    afficher_patient(tableau, taille);
    modifier_patient(tableau, taille);
    afficher_patient(tableau, taille);
    consultation tableau_consultation[100];
    remplir_consultation(tableau_consultation, taille);
    afficher_consultation(tableau_consultation, taille);
    inserer_consultation(tableau_consultation, &taille);
    rechercher_consultation(tableau_consultation, taille);
    supprimer_consultation(tableau_consultation, &taille);
    afficher_consultation(tableau_consultation, taille);
    modifier_consultation(tableau_consultation, taille);
    afficher_consultation(tableau_consultation, taille);
    patient *tab;
    int T = 0;
    int capacite = 2;
    tab = malloc(capacite * sizeof(patient));
    inserer_patient_dyn(&tab, &T, &capacite);
    afficher_patient_dyn(tab, T);
    rechercher_patient_dyn(tab, T);
    supprimer_patient_dyn(&tab, &T);
    modifier_patient_dyn(tab, T);
    return 0;
}