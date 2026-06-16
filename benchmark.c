#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tableau_statique.h"
#include "tableau_dynamique.h"

#define REPETITIONS 10

void generer_patients(patient tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        tableau[i].id = i + 1;
        tableau[i].age = rand() % 80 + 1;
        sprintf(tableau[i].nom, "Patient%d", i);
        sprintf(tableau[i].prenom, "Prenom%d", i);
        tableau[i].sexe = 'M';
        sprintf(tableau[i].adresse, "Adresse%d", i);
        sprintf(tableau[i].numTel, "7700%05d", i);
        tableau[i].poids = (float)(rand() % 50 + 50);
        tableau[i].taille = (float)(rand() % 50 + 150) / 100.0;
        tableau[i].date_naissance.jour = 1;
        tableau[i].date_naissance.mois = 1;
        tableau[i].date_naissance.annee = 2000;
        tableau[i].nb_consultations = 0;
    }
}

void inserer_patient_auto(patient **tableau, int *taille, int *capacite, int id) {
    if (*taille >= *capacite) {
        *capacite *= 2;
        *tableau = realloc(*tableau, (*capacite) * sizeof(patient));
    }
    (*tableau)[*taille].id = id;
    (*tableau)[*taille].age = rand() % 80 + 1;
    sprintf((*tableau)[*taille].nom, "Patient%d", id);
    sprintf((*tableau)[*taille].prenom, "Prenom%d", id);
    (*tableau)[*taille].sexe = 'M';
    sprintf((*tableau)[*taille].adresse, "Adresse%d", id);
    sprintf((*tableau)[*taille].numTel, "7700%05d", id);
    (*tableau)[*taille].poids = 60.0;
    (*tableau)[*taille].taille = 1.70;
    (*tableau)[*taille].date_naissance.jour = 1;
    (*tableau)[*taille].date_naissance.mois = 1;
    (*tableau)[*taille].date_naissance.annee = 2000;
    (*tableau)[*taille].nb_consultations = 0;
    (*taille)++;
}

int main() {
    FILE* f = fopen("resultats.csv", "w");
    fprintf(f, "structure,operation,n,temps\n");

    // ===== TABLEAU STATIQUE (max 100) =====
    int tailles_stat[] = {10, 50, 100};
    for (int t = 0; t < 3; t++) {
        int n = tailles_stat[t];
        double total;

        // Insertion (génération)
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            patient tab[100];
            clock_t debut = clock();
            generer_patients(tab, n);
            clock_t fin = clock();
            total += (double)(fin - debut) / CLOCKS_PER_SEC;
        }
        fprintf(f, "statique,insertion,%d,%f\n", n, total / REPETITIONS);

        // Recherche
        patient tab[100];
        generer_patients(tab, n);
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            clock_t debut = clock();
            for (int i = 0; i < n; i++)
                if (tab[i].id == n/2) break;
            clock_t fin = clock();
            total += (double)(fin - debut) / CLOCKS_PER_SEC;
        }
        fprintf(f, "statique,recherche,%d,%f\n", n, total / REPETITIONS);

        // Tri par insertion
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            patient tab2[100];
            generer_patients(tab2, n);
            clock_t debut = clock();
            tri_insertion_nom(tab2, n);
            clock_t fin = clock();
            total += (double)(fin - debut) / CLOCKS_PER_SEC;
        }
        fprintf(f, "statique,tri_insertion,%d,%f\n", n, total / REPETITIONS);

        // Tri rapide
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            patient tab3[100];
            generer_patients(tab3, n);
            clock_t debut = clock();
            tri_rapide_age(tab3, 0, n - 1);
            clock_t fin = clock();
            total += (double)(fin - debut) / CLOCKS_PER_SEC;
        }
        fprintf(f, "statique,tri_rapide,%d,%f\n", n, total / REPETITIONS);
    }

    // ===== TABLEAU DYNAMIQUE =====
    int tailles_dyn[] = {100, 1000, 10000};
    for (int t = 0; t < 3; t++) {
        int n = tailles_dyn[t];
        double total;

        // Insertion
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            int capacite = 2, taille = 0;
            patient *tab = malloc(capacite * sizeof(patient));
            clock_t debut = clock();
            for (int i = 0; i < n; i++)
                inserer_patient_auto(&tab, &taille, &capacite, i);
            clock_t fin = clock();
            total += (double)(fin - debut) / CLOCKS_PER_SEC;
            free(tab);
        }
        fprintf(f, "dynamique,insertion,%d,%f\n", n, total / REPETITIONS);

        // Tri rapide dynamique
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            int capacite = n, taille = n;
            patient *tab = malloc(capacite * sizeof(patient));
            generer_patients(tab, n);
            clock_t debut = clock();
            tri_rapide_age_dyn(tab, 0, n - 1);
            clock_t fin = clock();
            total += (double)(fin - debut) / CLOCKS_PER_SEC;
            free(tab);
        }
        fprintf(f, "dynamique,tri_rapide,%d,%f\n", n, total / REPETITIONS);
    }

    fclose(f);
    printf("Benchmark termine ! Resultats dans resultats.csv\n");
    return 0;
}