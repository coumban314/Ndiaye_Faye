#include "tableau_dynamique.h"
void inserer_patient_dyn(patient **tableau, int *taille, int *capacite) {
    if(*taille >= *capacite) {
        *capacite *= 2; // Doubler la capacité du tableau
        *tableau = realloc(*tableau, (*capacite) * sizeof(patient));
        if(*tableau == NULL) {
            printf("Erreur de reallocation de memoire\n");
            exit(1);
        }
    }
    printf("Entrez les informations du patient a ajouter :\n");
    (*tableau)[*taille].id = *taille + 1; // Assigner un ID unique basé sur la taille actuelle du tableau
    printf("Prenom : ");
    fgets((*tableau)[*taille].prenom, 25, stdin);
    printf("Nom : ");
    fgets((*tableau)[*taille].nom, 25, stdin);
    printf("Sexe (M/F) : ");
    scanf(" %c", &(*tableau)[*taille].sexe);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie du sexe
    printf("Adresse : ");
    fgets((*tableau)[*taille].adresse, 50, stdin);
    printf("Numero de telephone : ");
    fgets((*tableau)[*taille].numTel,15, stdin);
    printf("age : ");
    scanf("%d", &(*tableau)[*taille].age);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie de l'âge
    printf("Date de naissance (jour mois annee) : ");
    scanf("%d %d %d", &(*tableau)[*taille].date_naissance.jour, &(*tableau)[*taille].date_naissance.mois, &(*tableau)[*taille].date_naissance.annee);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie de la date de naissance
    printf("Poids : ");
    scanf("%f", &(*tableau)[*taille].poids);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie du poids
    printf("Taille : ");
    scanf("%f", &(*tableau)[*taille].taille);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie de la taille
    (*tableau)[*taille].nb_consultations = 0;
    (*taille)++;
}
void afficher_patient_dyn(patient *tableau, int taille) {
    printf("\nInformations des patients :\n");
    for (int i = 0; i < taille; i++) {
        printf("Patient %d :\n", i + 1);
        printf("  ID : %d\n", tableau[i].id);
        printf("  Prenom : %s\n", tableau[i].prenom);
        printf("  Nom : %s\n", tableau[i].nom);
        printf("  Sexe : %c\n", tableau[i].sexe);
        printf("  Adresse : %s\n", tableau[i].adresse);
        printf("  Numero de telephone : %s\n", tableau[i].numTel);
        printf("  age : %d\n", tableau[i].age);
        printf("  Date de naissance : %d/%d/%d\n", tableau[i].date_naissance.jour, tableau[i].date_naissance.mois, tableau[i].date_naissance.annee);
        printf("  Poids : %.2f\n", tableau[i].poids);
        printf("  Taille : %.2f\n", tableau[i].taille);
    }
}
     void rechercher_patient_dyn(patient *tableau, int taille) {
    int n;
    printf("Entrez l'ID du patient a rechercher : ");
    scanf("%d", &n);
    getchar(); // Consommer le caractère de nouvelle ligne
    for (int i = 0; i < taille; i++) {
        if (tableau[i].id == n) {
            printf("Patient trouve :\n");
            printf("  ID : %d\n", tableau[i].id);
            printf("  Prenom : %s\n", tableau[i].prenom);
            printf("  Nom : %s\n", tableau[i].nom);
            printf("  Sexe : %c\n", tableau[i].sexe);
            printf("  Adresse : %s\n", tableau[i].adresse);
            printf("  Numero de telephone : %s\n", tableau[i].numTel);
            printf("  age : %d\n", tableau[i].age);
            printf("  Date de naissance : %d/%d/%d\n", tableau[i].date_naissance.jour, tableau[i].date_naissance.mois, tableau[i].date_naissance.annee);
            printf("  Poids : %.2f\n", tableau[i].poids);
            printf("  Taille : %.2f\n", tableau[i].taille);
            return;
        }
    }
    printf("Patient non trouve.\n");
}
void supprimer_patient_dyn(patient **tableau, int *taille) {
    int n;
    printf("Entrez l'ID du patient a supprimer : ");
    scanf("%d", &n);
    getchar(); // Consommer le caractère de nouvelle ligne
    for (int i = 0; i < *taille; i++) {
        if ((*tableau)[i].id == n) {
            // Remplacer le patient à supprimer par le dernier patient du tableau
            (*tableau)[i] = (*tableau)[*taille - 1];
            (*taille)--;
            printf("Patient supprime avec succes.\n");
            return;
        }
    }
    printf("Patient non trouve.\n");
}
void modifier_patient_dyn(patient *tableau, int taille) {
    int n;
    printf("Entrez l'ID du patient a modifier : ");
    scanf("%d", &n);
    getchar(); // Consommer le caractère de nouvelle ligne
    for (int i = 0; i < taille; i++) {
        if (tableau[i].id == n) {
            printf("Entrez les nouvelles informations du patient :\n");
            printf("Prenom : ");
            fgets(tableau[i].prenom, 25, stdin);
            printf("Nom : ");
            fgets(tableau[i].nom, 25, stdin);
            printf("Sexe (M/F) : ");
            scanf(" %c", &tableau[i].sexe);
            getchar(); // Consommer le caractère de nouvelle ligne après la saisie du sexe
            printf("Adresse : ");
            fgets(tableau[i].adresse, 50, stdin);
            printf("Numero de telephone : ");
            fgets(tableau[i].numTel,15, stdin);
            printf("age : ");
            scanf("%d", &tableau[i].age);
            getchar(); // Consommer le caractère de nouvelle ligne après la saisie de l'âge
            printf("Date de naissance (jour mois annee) : ");
            scanf("%d %d %d", &tableau[i].date_naissance.jour, &tableau[i].date_naissance.mois, &tableau[i].date_naissance.annee);
            getchar(); // Consommer le caractère de nouvelle ligne après la saisie de la date de naissance
            printf("Poids : ");
            scanf("%f", &tableau[i].poids);
            getchar(); // Consommer le caractère de nouvelle ligne après la saisie du poids
            printf("Taille : ");
            scanf("%f", &tableau[i].taille);
            getchar(); // Consommer le caractère de nouvelle ligne après la saisie de la taille
            printf("Patient modifie avec succes.\n");
            return;
        }
    }
    printf("Patient non trouve.\n");
}
 void inserer_consultation_dyn(consultation **tableau, int *taille, int *capacite) {
    if(*taille >= *capacite) {
        *capacite *= 2; // Doubler la capacité du tableau
        *tableau = realloc(*tableau, (*capacite) * sizeof(consultation));
        if(*tableau == NULL) {
            printf("Erreur de reallocation de memoire\n");
            exit(1);
        }
    }
    printf("Entrez les informations de la consultation a ajouter :\n");
    (*tableau)[*taille].id = *taille + 1; // Assigner un ID unique basé sur la taille actuelle du tableau
    printf("Date de consultation (jour mois annee) : ");
    scanf("%d %d %d", &(*tableau)[*taille].date_consultation.jour, &(*tableau)[*taille].date_consultation.mois, &(*tableau)[*taille].date_consultation.annee);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie de la date de consultation
    printf("Medecin : ");
    fgets((*tableau)[*taille].medecin, 25, stdin);
    printf("Diagnostic : ");
    fgets((*tableau)[*taille].diagnostic, 100, stdin);
    printf("Traitement : ");
    fgets((*tableau)[*taille].traitement, 100, stdin);
    printf("Duree (en jours) : ");
    scanf("%d", &(*tableau)[*taille].duree);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie de la durée
    printf("Cout : ");
    scanf("%f", &(*tableau)[*taille].cout);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie du coût
    (*taille)++;
}
void afficher_consultation_dyn(consultation *tableau, int taille) {
    printf("\nInformations des consultations :\n");
    for (int i = 0; i < taille; i++) {
        printf("Consultation %d :\n", i + 1);
        printf("  ID : %d\n", tableau[i].id);
        printf("  Date de consultation : %d/%d/%d\n", tableau[i].date_consultation.jour, tableau[i].date_consultation.mois, tableau[i].date_consultation.annee);
        printf("  Medecin : %s\n", tableau[i].medecin);
        printf("  Diagnostic : %s\n", tableau[i].diagnostic);
        printf("  Traitement : %s\n", tableau[i].traitement);
        printf("  Duree : %d jours\n", tableau[i].duree);
        printf("  Cout : %.2f\n", tableau[i].cout);
    }
}
void rechercher_consultation_dyn(consultation *tableau, int taille) {
    int n;
    printf("Entrez l'ID de la consultation a rechercher : ");
    scanf("%d", &n);
    getchar(); // Consommer le caractère de nouvelle ligne
    for (int i = 0; i < taille; i++) {
        if (tableau[i].id == n) {
            printf("Consultation trouve :\n");
            printf("  ID : %d\n", tableau[i].id);
            printf("  Date de consultation : %d/%d/%d\n", tableau[i].date_consultation.jour, tableau[i].date_consultation.mois, tableau[i].date_consultation.annee);
            printf("  Medecin : %s\n", tableau[i].medecin);
            printf("  Diagnostic : %s\n", tableau[i].diagnostic);
            printf("  Traitement : %s\n", tableau[i].traitement);
            printf("  Duree : %d jours\n", tableau[i].duree);
            printf("  Cout : %.2f\n", tableau[i].cout);
            return;
        }
    }
    printf("Consultation non trouve.\n");
}
void supprimer_consultation_dyn(consultation **tableau, int *taille) {
    int n;
    printf("Entrez l'ID de la consultation a supprimer : ");
    scanf("%d", &n);
    getchar(); // Consommer le caractère de nouvelle ligne
    for (int i = 0; i < *taille; i++) {
        if ((*tableau)[i].id == n) {
            // Remplacer la consultation à supprimer par la dernière consultation du tableau
            (*tableau)[i] = (*tableau)[*taille - 1];
            (*taille)--;
            printf("Consultation supprime avec succes.\n");
            return;
        }
    }
    printf("Consultation non trouve.\n");
}
void modifier_consultation_dyn(consultation *tableau, int taille) {
    int n;
    printf("Entrez l'ID de la consultation a modifier : ");
    scanf("%d", &n);
    getchar(); // Consommer le caractère de nouvelle ligne
    for (int i = 0; i < taille; i++) {
        if (tableau[i].id == n) {
            printf("Entrez les nouvelles informations de la consultation :\n");
            printf("Date de consultation (jour mois annee) : ");
            scanf("%d %d %d", &tableau[i].date_consultation.jour, &tableau[i].date_consultation.mois, &tableau[i].date_consultation.annee);
            getchar(); // Consommer le caractère de nouvelle ligne après la saisie de la date de consultation
            printf("Medecin : ");
            fgets(tableau[i].medecin, 25, stdin);
            printf("Diagnostic : ");
            fgets(tableau[i].diagnostic, 100, stdin);
            printf("Traitement : ");
            fgets(tableau[i].traitement, 100, stdin);
            printf("Duree (en jours) : ");
            scanf("%d", &tableau[i].duree);
            getchar(); // Consommer le caractère de nouvelle ligne après la saisie de la durée
            printf("Cout : ");
            scanf("%f", &tableau[i].cout);
            getchar(); // Consommer le caractère de nouvelle ligne après la saisie du coût
            printf("Consultation modifie avec succes.\n");
            return;
        }
    }
    printf("Consultation non trouve.\n");
}