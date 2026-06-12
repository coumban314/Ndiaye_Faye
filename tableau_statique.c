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
    patient temp = tableau[i + 1];
    tableau[i + 1] = tableau[haut];
    tableau[haut] = temp;
    return i + 1;
}
    }

void tri_rapide_age(patient tableau[], int bas, int haut) {
    int trouver = 0;
    if (bas < haut) {
        int pivot = partition(tableau, bas, haut);
        tri_rapide_age(tableau, bas, pivot - 1);
        tri_rapide_age(tableau, pivot + 1, haut);
    }


    if(trouver == 0) {
        printf("Patient non trouver\n");
    }
}
// 1. Minimum
int minimum_age(patient tableau[], int taille) {
    int min = tableau[0].age;
    for (int i = 1; i < taille; i++)
        if (tableau[i].age < min)
            min = tableau[i].age;
    return min;
}

// 2. Maximum
int maximum_age(patient tableau[], int taille) {
    int max = tableau[0].age;
    for (int i = 1; i < taille; i++)
        if (tableau[i].age > max)
            max = tableau[i].age;
    return max;
}

// 3. Moyenne
float moyenne_age(patient tableau[], int taille) {
    float somme = 0;
    for (int i = 0; i < taille; i++)
        somme += tableau[i].age;
    return somme / taille;
}

// 4. Médiane
float mediane_age(patient tableau[], int taille) {
    patient copie[100];
    for (int i = 0; i < taille; i++)
        copie[i] = tableau[i];
    tri_insertion_nom(copie, taille);
    if (taille % 2 == 0)
        return (copie[taille/2 - 1].age + copie[taille/2].age) / 2.0;
    else
        return copie[taille/2].age;
}

// 5. Écart-type
float ecart_type_age(patient tableau[], int taille) {
    float moy = moyenne_age(tableau, taille);
    float somme = 0;
    for (int i = 0; i < taille; i++)
        somme += (tableau[i].age - moy) * (tableau[i].age - moy);
    return sqrt(somme / taille);
}

// 6. Affichage de tout
void afficher_agregations(patient tableau[], int taille) {
    printf("\n Agrégations statistiques (age)\n");
    printf("Minimum    : %d\n",   minimum_age(tableau, taille));
    printf("Maximum    : %d\n",   maximum_age(tableau, taille));
    printf("Moyenne    : %.2f\n", moyenne_age(tableau, taille));
    printf("Mediane    : %.2f\n", mediane_age(tableau, taille));
    printf("Ecart-type : %.2f\n", ecart_type_age(tableau, taille));
}
// Sauvegarde patients
void sauvegarder_patients(patient tableau[], int taille, const char* fichier) {
    FILE* f = fopen(fichier, "wb"); // wb = write binary
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }
    fwrite(&taille, sizeof(int), 1, f);          // on sauvegarde la taille
    fwrite(tableau, sizeof(patient), taille, f); // on sauvegarde les données
    fclose(f);
    printf("Patients sauvegardés dans %s.\n", fichier);
}

// Chargement patients
void charger_patients(patient tableau[], int* taille, const char* fichier) {
    FILE* f = fopen(fichier, "rb"); // rb = read binary
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }
    fread(taille, sizeof(int), 1, f);           // on relit la taille
    fread(tableau, sizeof(patient), *taille, f); // on relit les données
    fclose(f);
    printf("Patients chargés depuis %s.\n", fichier);
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
void afficher_une_consultation(consultation c) {
    printf("  ID : %d\n", c.id);
    printf("  Date : %d/%d/%d\n", c.date_consultation.jour, c.date_consultation.mois, c.date_consultation.annee);
    printf("  Medecin : %s\n", c.medecin);
    printf("  Diagnostic : %s\n", c.diagnostic);
    printf("  Traitement : %s\n", c.traitement);
    printf("  Duree : %d jours\n", c.duree);
    printf("  Cout : %.2f\n", c.cout);
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
void tri_insertion_medecin(consultation tableau[], int taille) {
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
int partition_consultation(consultation tableau[], int bas, int haut) {
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

void tri_rapide_cout(consultation tableau[], int bas, int haut) {
    if (bas < haut) {
        int pivot = partition_consultation(tableau, bas, haut);
        tri_rapide_cout(tableau, bas, pivot - 1);
        tri_rapide_cout(tableau, pivot + 1, haut);
    }
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
void recherche_par_intervalle_consultation(consultation tableau[], int taille, float cout_min, float cout_max) {
    int trouve = 0;
    printf("\nConsultations entre %.2f et %.2f :\n", cout_min, cout_max);
    for (int i = 0; i < taille; i++) {
        if (tableau[i].cout >= cout_min && tableau[i].cout <= cout_max) {
            afficher_une_consultation(tableau[i]);
            trouve = 1;
        }
    }
    if (!trouve)
        printf("Aucune consultation trouvee.\n");
}
void recherche_par_prefixe_consultation(consultation tableau[], int taille, const char* prefixe) {
    int trouve = 0;
    printf("\nConsultations dont le medecin commence par \"%s\" :\n", prefixe);
    for (int i = 0; i < taille; i++) {
        if (strncmp(tableau[i].medecin, prefixe, strlen(prefixe)) == 0) {
            afficher_une_consultation(tableau[i]);
            trouve = 1;
        }
    }
    if (!trouve)
        printf("Aucune consultation trouvee.\n");
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
            printf("Consultation modifier avec succes\n");
            break; // Sortir de la boucle après avoir trouvé et modifié la consultation
        }
    }

    if(trouver == 0) {
        printf("Consultation non trouver\n");
    }
}
float minimum_cout(consultation tableau[], int taille) {
    float min = tableau[0].cout;
    for (int i = 1; i < taille; i++)
        if (tableau[i].cout < min)
            min = tableau[i].cout;
    return min;
}

float maximum_cout(consultation tableau[], int taille) {
    float max = tableau[0].cout;
    for (int i = 1; i < taille; i++)
        if (tableau[i].cout > max)
            max = tableau[i].cout;
    return max;
}

float moyenne_cout(consultation tableau[], int taille) {
    float somme = 0;
    for (int i = 0; i < taille; i++)
        somme += tableau[i].cout;
    return somme / taille;
}

float mediane_cout(consultation tableau[], int taille) {
    consultation copie[100];
    for (int i = 0; i < taille; i++)
        copie[i] = tableau[i];
    tri_insertion_medecin(copie, taille);
    if (taille % 2 == 0)
        return (copie[taille/2 - 1].cout + copie[taille/2].cout) / 2.0;
    else
        return copie[taille/2].cout;
}

float ecart_type_cout(consultation tableau[], int taille) {
    float moy = moyenne_cout(tableau, taille);
    float somme = 0;
    for (int i = 0; i < taille; i++)
        somme += (tableau[i].cout - moy) * (tableau[i].cout - moy);
    return sqrt(somme / taille);
}

void afficher_agregations_consultation(consultation tableau[], int taille) {
    printf("\n=== Agregations statistiques (cout) ===\n");
    printf("Minimum    : %.2f\n", minimum_cout(tableau, taille));
    printf("Maximum    : %.2f\n", maximum_cout(tableau, taille));
    printf("Moyenne    : %.2f\n", moyenne_cout(tableau, taille));
    printf("Mediane    : %.2f\n", mediane_cout(tableau, taille));
    printf("Ecart-type : %.2f\n", ecart_type_cout(tableau, taille));
}
void sauvegarder_consultations(consultation tableau[], int taille, const char* fichier) {
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

void charger_consultations(consultation tableau[], int* taille, const char* fichier) {
    FILE* f = fopen(fichier, "rb");
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }
    fread(taille, sizeof(int), 1, f);
    fread(tableau, sizeof(consultation), *taille, f);
    fclose(f);
    printf("Consultations chargees depuis %s.\n", fichier);
}