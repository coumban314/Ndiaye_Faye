#include "../include/patient.h"
void remplir_patient(patient tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        tableau[i].id=i+1;
        printf("Entrez les informations du patient %d :\n", i + 1);
        printf("Prénom : ");
        scanf("%s", tableau[i].prenom);
        printf("Nom : ");
        scanf("%s", tableau[i].nom);
        printf("Sexe (M/F) : ");
        scanf(" %c", &tableau[i].sexe);
        printf("Adresse : ");
        scanf("%s", tableau[i].adresse);
        printf("Numéro de téléphone : ");
        scanf("%s", tableau[i].numTel);
        printf("Âge : ");
        scanf("%d", &tableau[i].age);
        printf("Date de naissance (jour mois année) : ");
        scanf("%d %d %d", &tableau[i].date_naissance.jour, &tableau[i].date_naissance.mois, &tableau[i].date_naissance.annee);
        printf("Poids : ");
        scanf("%f", &tableau[i].poids);
        printf("Taille : ");
        scanf("%f", &tableau[i].taille);
        tableau[i].nb_consultations = 0; // Initialiser le nombre de consultations à 0
    }
}
       void afficher_patients(patient tableau[], int taille) {
    printf("\nInformations des patients :\n");
    for (int i = 0; i < taille; i++) {
        printf("Patient %d :\n", i + 1);
        printf("  ID : %d\n", tableau[i].id);
        printf("  Prénom : %s\n", tableau[i].prenom);
        printf("  Nom : %s\n", tableau[i].nom);
        printf("  Sexe : %c\n", tableau[i].sexe);
        printf("  Adresse : %s\n", tableau[i].adresse);
        printf("  Numéro de téléphone : %s\n", tableau[i].numTel);
        printf("  Âge : %d\n", tableau[i].age);
        printf("  Date de naissance : %d/%d/%d\n", tableau[i].date_naissance.jour, tableau[i].date_naissance.mois, tableau[i].date_naissance.année);
        printf("  Poids : %.2f\n", tableau[i].poids);
        printf("  Taille : %.2f\n", tableau[i].taille);
    }
}