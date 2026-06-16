#include "tableau_dynamique.h"
#include<string.h>
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
void tri_insertion_nom_dyn(patient *tableau, int taille) {
    for (int i = 1; i < taille; i++) {
        patient cle = tableau[i];
        int j = i - 1;
        while (j >= 0 && strcmp(tableau[j].nom, cle.nom) > 0) {
            tableau[j + 1] = tableau[j];
            j--;
        }
        tableau[j + 1] = cle;
    }
    printf("Patients tries par nom.\n");
}

int partition_dyn(patient *tableau, int bas, int haut) {
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

void tri_rapide_age_dyn(patient *tableau, int bas, int haut) {
    if (bas < haut) {
        int pivot = partition_dyn(tableau, bas, haut);
        tri_rapide_age_dyn(tableau, bas, pivot - 1);
        tri_rapide_age_dyn(tableau, pivot + 1, haut);
    }
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
void recherche_par_intervalle_patient_dyn(patient *tableau, int taille, int age_min, int age_max) {
    int trouve = 0;
    printf("\nPatients dont l'age est entre %d et %d ans :\n", age_min, age_max);
    for (int i = 0; i < taille; i++) {
        if (tableau[i].age >= age_min && tableau[i].age <= age_max) {
            printf("  ID : %d\n", tableau[i].id);
            printf("  Prenom : %s\n", tableau[i].prenom);
            printf("  Nom : %s\n", tableau[i].nom);
            printf("  Age : %d\n", tableau[i].age);
            trouve = 1;
        }
    }
    if (!trouve)
        printf("Aucun patient trouve.\n");
}
void recherche_par_prefixe_patient_dyn(patient *tableau, int taille, const char* prefixe) {
    int trouve = 0;
    printf("\nPatients dont le nom commence par \"%s\" :\n", prefixe);
    for (int i = 0; i < taille; i++) {
        if (strncmp(tableau[i].nom, prefixe, strlen(prefixe)) == 0) {
            printf("  ID : %d\n", tableau[i].id);
            printf("  Prenom : %s\n", tableau[i].prenom);
            printf("  Nom : %s\n", tableau[i].nom);
            printf("  Age : %d\n", tableau[i].age);
            trouve = 1;
        }
    }
    if (!trouve)
        printf("Aucun patient trouve.\n");
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
void afficher_consultation_dyn(consultation *tableau, int taille) {
    printf("\nInformations des consultations :\n");
    for (int i = 0; i < taille; i++) {
        printf("Consultation %d :\n", i + 1);
        printf("  ID : %d\n", tableau[i].id);
        printf("  Date : %d/%d/%d\n", tableau[i].date_consultation.jour, 
               tableau[i].date_consultation.mois, tableau[i].date_consultation.annee);
        printf("  Medecin : %s\n", tableau[i].medecin);
        printf("  Diagnostic : %s\n", tableau[i].diagnostic);
        printf("  Traitement : %s\n", tableau[i].traitement);
        printf("  Duree : %d jours\n", tableau[i].duree);
        printf("  Cout : %.2f\n", tableau[i].cout);
    }
}

void recherche_par_intervalle_consultation_dyn(consultation *tableau, int taille, float cout_min, float cout_max) {
    int trouve = 0;
    printf("\nConsultations entre %.2f et %.2f :\n", cout_min, cout_max);
    for (int i = 0; i < taille; i++) {
        if (tableau[i].cout >= cout_min && tableau[i].cout <= cout_max) {
            printf("  ID : %d, Medecin : %s, Cout : %.2f\n", tableau[i].id, tableau[i].medecin, tableau[i].cout);
            trouve = 1;
        }
    }
    if (!trouve)
        printf("Aucune consultation trouvee.\n");
}

void recherche_par_prefixe_consultation_dyn(consultation *tableau, int taille, const char* prefixe) {
    int trouve = 0;
    printf("\nConsultations dont le medecin commence par \"%s\" :\n", prefixe);
    for (int i = 0; i < taille; i++) {
        if (strncmp(tableau[i].medecin, prefixe, strlen(prefixe)) == 0) {
            printf("  ID : %d, Medecin : %s, Cout : %.2f\n", tableau[i].id, tableau[i].medecin, tableau[i].cout);
            trouve = 1;
        }
    }
    if (!trouve)
        printf("Aucune consultation trouvee.\n");
}
int minimum_age_dyn(patient *tableau, int taille) {
    int min = tableau[0].age;
    for (int i = 1; i < taille; i++)
        if (tableau[i].age < min)
            min = tableau[i].age;
    return min;
}

int maximum_age_dyn(patient *tableau, int taille) {
    int max = tableau[0].age;
    for (int i = 1; i < taille; i++)
        if (tableau[i].age > max)
            max = tableau[i].age;
    return max;
}

float moyenne_age_dyn(patient *tableau, int taille) {
    float somme = 0;
    for (int i = 0; i < taille; i++)
        somme += tableau[i].age;
    return somme / taille;
}

float mediane_age_dyn(patient *tableau, int taille) {
    patient *copie = malloc(taille * sizeof(patient));
    for (int i = 0; i < taille; i++)
        copie[i] = tableau[i];
    tri_insertion_nom_dyn(copie, taille);
    float result;
    if (taille % 2 == 0)
        result = (copie[taille/2 - 1].age + copie[taille/2].age) / 2.0;
    else
        result = copie[taille/2].age;
    free(copie);
    return result;
}

float ecart_type_age_dyn(patient *tableau, int taille) {
    float moy = moyenne_age_dyn(tableau, taille);
    float somme = 0;
    for (int i = 0; i < taille; i++)
        somme += (tableau[i].age - moy) * (tableau[i].age - moy);
    return sqrt(somme / taille);
}
void afficher_agregations_dyn(patient *tableau, int taille) {
    printf("\n=== Agregations statistiques (age) ===\n");
    printf("Minimum    : %d\n",   minimum_age_dyn(tableau, taille));
    printf("Maximum    : %d\n",   maximum_age_dyn(tableau, taille));
    printf("Moyenne    : %.2f\n", moyenne_age_dyn(tableau, taille));
    printf("Mediane    : %.2f\n", mediane_age_dyn(tableau, taille));
    printf("Ecart-type : %.2f\n", ecart_type_age_dyn(tableau, taille));
}
void sauvegarder_patients_dyn(patient *tableau, int taille, const char* fichier) {
    FILE* f = fopen(fichier, "wb");
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }
    fwrite(&taille, sizeof(int), 1, f);
    fwrite(tableau, sizeof(patient), taille, f);
    fclose(f);
    printf("Patients sauvegardes dans %s.\n", fichier);
}

void charger_patients_dyn(patient **tableau, int* taille, const char* fichier) {
    FILE* f = fopen(fichier, "rb");
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }
    fread(taille, sizeof(int), 1, f);
    *tableau = realloc(*tableau, (*taille) * sizeof(patient));
    fread(*tableau, sizeof(patient), *taille, f);
    fclose(f);
    printf("Patients charges depuis %s.\n", fichier);
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
void tri_insertion_medecin_dyn(consultation *tableau, int taille) {
    for (int i = 1; i < taille; i++) {
        consultation cle = tableau[i];
        int j = i - 1;
        while (j >= 0 && strcmp(tableau[j].medecin, cle.medecin) > 0) {
            tableau[j + 1] = tableau[j];
            j--;
        }
        tableau[j + 1] = cle;
    }
    printf("Consultations triees par medecin.\n");
}

int partition_consultation_dyn(consultation *tableau, int bas, int haut) {
    float pivot = tableau[haut].cout;
    int i = bas - 1;
    for (int j = bas; j < haut; j++) {
        if (tableau[j].cout <= pivot) {
            i++;
            consultation temp = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = temp;
        }
    }
    consultation temp = tableau[i + 1];
    tableau[i + 1] = tableau[haut];
    tableau[haut] = temp;
    return i + 1;
}

void tri_rapide_cout_dyn(consultation *tableau, int bas, int haut) {
    if (bas < haut) {
        int pivot = partition_consultation_dyn(tableau, bas, haut);
        tri_rapide_cout_dyn(tableau, bas, pivot - 1);
        tri_rapide_cout_dyn(tableau, pivot + 1, haut);
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
float minimum_cout_dyn(consultation *tableau, int taille) {
    float min = tableau[0].cout;
    for (int i = 1; i < taille; i++)
        if (tableau[i].cout < min)
            min = tableau[i].cout;
    return min;
}

float maximum_cout_dyn(consultation *tableau, int taille) {
    float max = tableau[0].cout;
    for (int i = 1; i < taille; i++)
        if (tableau[i].cout > max)
            max = tableau[i].cout;
    return max;
}

float moyenne_cout_dyn(consultation *tableau, int taille) {
    float somme = 0;
    for (int i = 0; i < taille; i++)
        somme += tableau[i].cout;
    return somme / taille;
}

float mediane_cout_dyn(consultation *tableau, int taille) {
    consultation *copie = malloc(taille * sizeof(consultation));
    for (int i = 0; i < taille; i++)
        copie[i] = tableau[i];
    tri_insertion_medecin_dyn(copie, taille);
    float result;
    if (taille % 2 == 0)
        result = (copie[taille/2 - 1].cout + copie[taille/2].cout) / 2.0;
    else
        result = copie[taille/2].cout;
    free(copie);
    return result;
}

float ecart_type_cout_dyn(consultation *tableau, int taille) {
    float moy = moyenne_cout_dyn(tableau, taille);
    float somme = 0;
    for (int i = 0; i < taille; i++)
        somme += (tableau[i].cout - moy) * (tableau[i].cout - moy);
    return sqrt(somme / taille);
}

void afficher_agregations_consultation_dyn(consultation *tableau, int taille) {
    printf("\n=== Agregations statistiques (cout) ===\n");
    printf("Minimum    : %.2f\n", minimum_cout_dyn(tableau, taille));
    printf("Maximum    : %.2f\n", maximum_cout_dyn(tableau, taille));
    printf("Moyenne    : %.2f\n", moyenne_cout_dyn(tableau, taille));
    printf("Mediane    : %.2f\n", mediane_cout_dyn(tableau, taille));
    printf("Ecart-type : %.2f\n", ecart_type_cout_dyn(tableau, taille));
}
void sauvegarder_consultations_dyn(consultation *tableau, int taille, const char* fichier) {
    FILE* f = fopen(fichier, "wb");
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }
    fwrite(&taille, sizeof(int), 1, f);
    fwrite(tableau, sizeof(consultation), taille, f);
    fclose(f);
    printf("Consultations sauvegardees dans %s.\n", fichier);
}

void charger_consultations_dyn(consultation **tableau, int* taille, const char* fichier) {
    FILE* f = fopen(fichier, "rb");
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }
    fread(taille, sizeof(int), 1, f);
    *tableau = realloc(*tableau, (*taille) * sizeof(consultation));
    fread(*tableau, sizeof(consultation), *taille, f);
    fclose(f);
    printf("Consultations chargees depuis %s.\n", fichier);

}