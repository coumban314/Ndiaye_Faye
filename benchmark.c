#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tableau_statique.h"
#include "tableau_dynamique.h"
#include "liste_chainee.h"

#define REPETITIONS 10

// =====================
// GENERATION PATIENTS
// =====================
void generer_patients(patient tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        tableau[i].id = i;
        tableau[i].age = rand() % 80 + 1;
        tableau[i].poids = 60.0;
        tableau[i].taille = 1.70;
    }
}

// =====================
// PATIENT SIMPLE
// =====================
patient creer_patient(int id) {
    patient p;
    p.id = id;
    p.age = rand() % 80 + 1;
    p.poids = 60.0;
    p.taille = 1.70;
    return p;
}
void inserer_patient_auto(patient **tableau, int *taille, int *capacite, int id) {
    if (*taille >= *capacite) {
        *capacite *= 2;
        *tableau = realloc(*tableau, (*capacite) * sizeof(patient));
    }
    (*tableau)[*taille].id = id;
    (*tableau)[*taille].age = rand() % 80 + 1;
    (*tableau)[*taille].poids = 60.0;
    (*tableau)[*taille].taille = 1.70;
    (*taille)++;
}
// =====================
// MAIN
// =====================
int main() {
    FILE* f = fopen("resultats.csv", "w");
    fprintf(f, "structure,operation,n,temps\n");

    srand(time(NULL));

    // ==================================================
    // TABLEAU STATIQUE
    // ==================================================
    int tailles_stat[] = {10, 50, 100};

    for (int t = 0; t < 3; t++) {
        int n = tailles_stat[t];
        double total;

        // -------- insertion --------
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            patient tab[100];
            clock_t debut = clock();
            generer_patients(tab, n);
            clock_t fin = clock();
            total += (double)(fin - debut) / CLOCKS_PER_SEC;
        }
        fprintf(f, "statique,insertion,%d,%f\n", n, total / REPETITIONS);

        // -------- recherche --------
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            patient tab[100];
            generer_patients(tab, n);

            clock_t debut = clock();
            for (int i = 0; i < n; i++)
                if (tab[i].id == n/2) break;
            clock_t fin = clock();

            total += (double)(fin - debut) / CLOCKS_PER_SEC;
        }
        fprintf(f, "statique,recherche,%d,%f\n", n, total / REPETITIONS);

        // -------- tri insertion --------
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            patient tab[100];
            generer_patients(tab, n);

            clock_t debut = clock();
            tri_insertion_nom(tab, n);
            clock_t fin = clock();

            total += (double)(fin - debut) / CLOCKS_PER_SEC;
        }
        fprintf(f, "statique,tri_insertion,%d,%f\n", n, total / REPETITIONS);

        // -------- tri rapide --------
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            patient tab[100];
            generer_patients(tab, n);

            clock_t debut = clock();
            tri_rapide_age(tab, 0, n - 1);
            clock_t fin = clock();

            total += (double)(fin - debut) / CLOCKS_PER_SEC;
        }
        fprintf(f, "statique,tri_rapide,%d,%f\n", n, total / REPETITIONS);
    }

    // ==================================================
    // TABLEAU DYNAMIQUE
    // ==================================================
    int tailles_dyn[] = {100, 1000, 10000};

    for (int t = 0; t < 3; t++) {
        int n = tailles_dyn[t];
        double total;

        // -------- insertion --------
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            int cap = 2, taille = 0;
            patient *tab = malloc(cap * sizeof(patient));

            clock_t debut = clock();
            for (int i = 0; i < n; i++)
                inserer_patient_auto(&tab, &taille, &cap, i);
            clock_t fin = clock();

            total += (double)(fin - debut) / CLOCKS_PER_SEC;
            free(tab);
        }
        fprintf(f, "dynamique,insertion,%d,%f\n", n, total / REPETITIONS);

        // -------- recherche --------
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            int cap = n;
            patient *tab = malloc(cap * sizeof(patient));
            generer_patients(tab, n);

            clock_t debut = clock();
            for (int i = 0; i < n; i++)
                if (tab[i].id == n/2) break;
            clock_t fin = clock();

            total += (double)(fin - debut) / CLOCKS_PER_SEC;
            free(tab);
        }
        fprintf(f, "dynamique,recherche,%d,%f\n", n, total / REPETITIONS);

        // -------- tri rapide --------
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            int cap = n;
            patient *tab = malloc(cap * sizeof(patient));
            generer_patients(tab, n);

            clock_t debut = clock();
            tri_rapide_age_dyn(tab, 0, n - 1);
            clock_t fin = clock();

            total += (double)(fin - debut) / CLOCKS_PER_SEC;
            free(tab);
        }
        fprintf(f, "dynamique,tri_rapide,%d,%f\n", n, total / REPETITIONS);
    }

    // ==================================================
    // LISTE CHAÎNÉE
    // ==================================================
    int tailles_lc[] = {100, 1000, 10000};

    for (int t = 0; t < 3; t++) {
        int n = tailles_lc[t];
        double total;

        // -------- insertion --------
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            ListeChainee liste;
            initialiser_liste(&liste);

            clock_t debut = clock();
            for (int i = 0; i < n; i++) {
                inserer_queue(&liste, creer_patient(i));
            }
            clock_t fin = clock();

            total += (double)(fin - debut) / CLOCKS_PER_SEC;
            liberer_liste(&liste);
        }
        fprintf(f, "liste_chainee,insertion,%d,%f\n", n, total / REPETITIONS);

        // -------- recherche --------
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            ListeChainee liste;
            initialiser_liste(&liste);

            for (int i = 0; i < n; i++)
                inserer_queue(&liste, creer_patient(i));

            clock_t debut = clock();
            rechercher_liste(&liste, n/2);
            clock_t fin = clock();

            total += (double)(fin - debut) / CLOCKS_PER_SEC;
            liberer_liste(&liste);
        }
        fprintf(f, "liste_chainee,recherche,%d,%f\n", n, total / REPETITIONS);

        // -------- tri insertion --------
        total = 0;
        for (int r = 0; r < REPETITIONS; r++) {
            ListeChainee liste;
            initialiser_liste(&liste);

            for (int i = 0; i < n; i++)
                inserer_queue(&liste, creer_patient(i));

            clock_t debut = clock();
            tri_insertion_liste(&liste);
            clock_t fin = clock();

            total += (double)(fin - debut) / CLOCKS_PER_SEC;
            liberer_liste(&liste);
        }
        fprintf(f, "liste_chainee,tri_insertion,%d,%f\n", n, total / REPETITIONS);
    }

    fclose(f);

    printf("Benchmark termine !\n");
    return 0;
}