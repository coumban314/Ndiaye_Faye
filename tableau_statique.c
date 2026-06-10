#include "../projet_LMI2/patient.h"
#include "../projet_LMI2/consultation.h"
void remplir_patient(patient tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        tableau[i].id=i+1;
        printf("Entrez les informations du patient %d :\n", i + 1);
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
        tableau[i].nb_consultations = 0; // Initialiser le nombre de consultations à 0
    }
}
       void afficher_patient(patient tableau[], int taille) {
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
void inserer_Patient(patient tableau[], int *taille)
{  
    if(*taille >= 100) {
        printf("Tableau plein!\n");
        return;
    }
     while(getchar() != '\n'); // vider le buffer
      printf("Entrez les informations du patient a ajouter :\n");
    tableau[*taille].id = *taille + 1; // Assigner un ID unique basé sur la taille actuelle du tableau
    printf("Prenom : ");
    fgets(tableau[*taille].prenom, 25, stdin);
    printf("Nom : ");
    fgets(tableau[*taille].nom, 25, stdin);
    printf("Sexe (M/F) : ");
    scanf(" %c", &tableau[*taille].sexe);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie du sexe
    printf("Adresse : ");
    fgets(tableau[*taille].adresse, 50, stdin);
    printf("Numero de telephone : ");
    fgets(tableau[*taille].numTel,15, stdin);
    printf("age : ");
    scanf("%d", &tableau[*taille].age);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie de l'âge
    printf("Date de naissance (jour mois annee) : ");
    scanf("%d %d %d", &tableau[*taille].date_naissance.jour, &tableau[*taille].date_naissance.mois, &tableau[*taille].date_naissance.annee);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie de la date de naissance
    printf("Poids : ");
    scanf("%f", &tableau[*taille].poids);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie du poids
    printf("Taille : ");
    scanf("%f", &tableau[*taille].taille);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie de la taille
    tableau[*taille].nb_consultations = 0; // Initialiser le nombre de consultations à 0
    (*taille)++;
}
void rechercher_patient(patient tableau[], int taille) {
    int n;
printf("Entrez l id du patient a rechercher : ");
scanf("%d", &n);
int trouver = 0;

for(int i = 0; i < taille; i++) {
    if(n == tableau[i].id) {
        trouver = 1;
        printf("Patient trouver :\n");
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

if(trouver == 0) {
    printf("Patient non trouver\n");
}
}

void recherche_par_intervalle(patient tableau[], int taille, int age_min, int age_max) {
    int trouve = 0;
    for (int i = 0; i < taille; i++) {
        if (tableau[i].age >= age_min && tableau[i].age <= age_max) {
            afficher_un_patient(tableau[i]);
            trouve = 1;
        }
    }
    if (!trouve)
        printf("Aucun patient trouvé.\n");
}
void recherche_par_prefixe(patient tableau[], int taille, const char* prefixe) {
    int trouve = 0;
    printf("\nPatients dont le nom commence par \"%s\" :\n", prefixe);

    for (int i = 0; i < taille; i++) {
        // strncmp compare les N premiers caractères
        if (strncmp(tableau[i].nom, prefixe, strlen(prefixe)) == 0) {
            afficher_un_patient(tableau[i]);
            trouve = 1;
        }
    }

    if (!trouve)
        printf("Aucun patient trouvé.\n");
}
void supprimer_patient(patient tableau[], int *taille) {
    int n;
    int trouver = 0;
    printf("Entrez l id du patient a supprimer : ");
    scanf("%d", &n);

    for(int i = 0; i < *taille; i++) {
        if(n == tableau[i].id) {
            trouver = 1;
            tableau[i] = tableau[*taille - 1]; // Remplacer le patient à supprimer par le dernier patient du tableau
            (*taille)--;
            printf("Patient supprimer avec succes\n");
        }
    }

    if(trouver == 0) {
        printf("Patient non trouver\n");
    }
}
void modifier_patient(patient tableau[], int taille) {
    int n;
    int trouver = 0;
    printf("Entrez l id du patient a modifier : ");
    scanf("%d", &n);

    for(int i = 0; i < taille; i++) {
        if(n == tableau[i].id) {
            trouver = 1;
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
            printf("Patient modifier avec succes\n");
        }
    }
    int partition(patient tableau[], int bas, int haut) {
    int pivot = tableau[haut].age;
    int i = bas - 1;
    for (int j = bas; j < haut; j++) {
        if (tableau[j].age <= pivot) {
            i++;
            patient temp = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = temp;
        }
    }
    patient temp = tableau[i + 1];
    tableau[i + 1] = tableau[haut];
    tableau[haut] = temp;
    return i + 1;
}

void tri_rapide_age(patient tableau[], int bas, int haut) {
    if (bas < haut) {
        int pivot = partition(tableau, bas, haut);
        tri_rapide_age(tableau, bas, pivot - 1);
        tri_rapide_age(tableau, pivot + 1, haut);
    }
}

    if(trouver == 0) {
        printf("Patient non trouver\n");
    }
}
void remplir_consultation(consultation tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        tableau[i].id = i + 1; // Assigner un ID unique basé sur l'index du tableau
        printf("Entrez les informations de la consultation %d :\n", i + 1);
        getchar(); // Consommer le caractère de nouvelle ligne après la saisie de l'ID
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
    }
}
void afficher_consultation(consultation tableau[], int taille) {
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
void inserer_consultation(consultation tableau[], int *taille) {
    if(*taille >= 100) {
        printf("Tableau plein!\n");
        return;
    }
    printf("Entrez les informations de la consultation a ajouter :\n");
    tableau[*taille].id = *taille + 1; // Assigner un ID unique basé sur la taille actuelle du tableau
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie de l'ID
    printf("Date de consultation (jour mois annee) : ");
    scanf("%d %d %d", &tableau[*taille].date_consultation.jour, &tableau[*taille].date_consultation.mois, &tableau[*taille].date_consultation.annee);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie de la date de consultation
    printf("Medecin : ");
    fgets(tableau[*taille].medecin, 25, stdin);
    printf("Diagnostic : ");
    fgets(tableau[*taille].diagnostic, 100, stdin);
    printf("Traitement : ");
    fgets(tableau[*taille].traitement, 100, stdin);
    printf("Duree (en jours) : ");
    scanf("%d", &tableau[*taille].duree);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie de la durée
    printf("Cout : ");
    scanf("%f", &tableau[*taille].cout);
    getchar(); // Consommer le caractère de nouvelle ligne après la saisie du coût
    printf("Consultation ajouter avec succes\n");
    (*taille)++; // Incrémenter la taille du tableau
}
void rechercher_consultation(consultation tableau[], int taille) {
    int n;
    printf("Entrez l id de la consultation a rechercher : ");
    scanf("%d", &n);
    int trouver = 0;

    for(int i = 0; i < taille; i++) {
        if(n == tableau[i].id) {
            trouver = 1;
            printf("Consultation trouver :\n");
            printf("  ID : %d\n", tableau[i].id);
            printf("  Date de consultation : %d/%d/%d\n", tableau[i].date_consultation.jour, tableau[i].date_consultation.mois, tableau[i].date_consultation.annee);
            printf("  Medecin : %s\n", tableau[i].medecin);
            printf("  Diagnostic : %s\n", tableau[i].diagnostic);
            printf("  Traitement : %s\n", tableau[i].traitement);
            printf("  Duree : %d jours\n", tableau[i].duree);
            printf("  Cout : %.2f\n", tableau[i].cout);
        }
    }

    if(trouver == 0) {
        printf("Consultation non trouver\n");
    }
}
void supprimer_consultation(consultation tableau[], int *taille) {
    int n;
    int trouver = 0;
    printf("Entrez l id de la consultation a supprimer : ");
    scanf("%d", &n);

    for(int i = 0; i < *taille; i++) {
        if(n == tableau[i].id) {
            trouver = 1;
            tableau[i] = tableau[*taille - 1]; // Remplacer la consultation à supprimer par la dernière consultation du tableau
            (*taille)--;
            printf("Consultation supprimer avec succes\n");
        }
    }

    if(trouver == 0) {
        printf("Consultation non trouver\n");
    }
}
void modifier_consultation(consultation tableau[], int taille) {
    int n;
    printf("Entrez l id de la consultation a modifier : ");
    scanf("%d", &n);
    int trouver = 0;

    for(int i = 0; i < taille; i++) {
        if(n == tableau[i].id) {
            trouver = 1;
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
            printf("Consultation modifier avec succes\n");
        }
    }

    if(trouver == 0) {
        printf("Consultation non trouver\n");
    }
}