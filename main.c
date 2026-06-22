#include "../projet_LMI2/tableau_statique.h"
#include "tableau_dynamique.h"
#include <stdlib.h>

// ===== MENU TABLEAU STATIQUE PATIENTS =====
void menu_statique_patient(patient tableau[], int *taille) {
    int choix;
    do {
        printf("\n=== MENU TABLEAU STATIQUE - PATIENTS ===\n");
        printf("1.  Remplir\n");
        printf("2.  Afficher\n");
        printf("3.  Inserer\n");
        printf("4.  Rechercher par cle\n");
        printf("5.  Rechercher par intervalle (age)\n");
        printf("6.  Rechercher par prefixe (nom)\n");
        printf("7.  Supprimer\n");
        printf("8.  Modifier\n");
        printf("9.  Trier par nom (insertion)\n");
        printf("10. Trier par age (rapide)\n");
        printf("11. Agregations statistiques\n");
        printf("12. Sauvegarder\n");
        printf("13. Charger\n");
        printf("0.  Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar();

        switch(choix) {
            case 1:
                remplir_patient(tableau, *taille);
                break;
            case 2:
                afficher_patient(tableau, *taille);
                break;
            case 3:
                inserer_Patient(tableau, taille);
                break;
            case 4:
                rechercher_patient(tableau, *taille);
                break;
            case 5: {
                int min, max;
                printf("Age minimum : "); scanf("%d", &min);
                printf("Age maximum : "); scanf("%d", &max);
                recherche_par_intervalle(tableau, *taille, min, max);
                break;
            }
            case 6: {
                char prefixe[50];
                printf("Debut du nom : "); scanf("%s", prefixe);
                recherche_par_prefixe(tableau, *taille, prefixe);
                break;
            }
            case 7:
                supprimer_patient(tableau, taille);
                break;
            case 8:
                modifier_patient(tableau, *taille);
                break;
            case 9:
                tri_insertion_nom(tableau, *taille);
                afficher_patient(tableau, *taille);
                break;
            case 10:
                tri_rapide_age(tableau, 0, *taille - 1);
                afficher_patient(tableau, *taille);
                break;
            case 11:
                afficher_agregations(tableau, *taille);
                break;
            case 12:
                sauvegarder_patients(tableau, *taille, "patients.bin");
                break;
            case 13:
                charger_patients(tableau, taille, "patients.bin");
                afficher_patient(tableau, *taille);
                break;
            case 0:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while(choix != 0);
}

// ===== MENU TABLEAU STATIQUE CONSULTATIONS =====
void menu_statique_consultation(consultation tableau[], int *taille) {
    int choix;
    do {
        printf("\n=== MENU TABLEAU STATIQUE - CONSULTATIONS ===\n");
        printf("1.  Remplir\n");
        printf("2.  Afficher\n");
        printf("3.  Inserer\n");
        printf("4.  Rechercher par cle\n");
        printf("5.  Rechercher par intervalle (cout)\n");
        printf("6.  Rechercher par prefixe (medecin)\n");
        printf("7.  Supprimer\n");
        printf("8.  Modifier\n");
        printf("9.  Trier par medecin (insertion)\n");
        printf("10. Trier par cout (rapide)\n");
        printf("11. Agregations statistiques\n");
        printf("12. Sauvegarder\n");
        printf("13. Charger\n");
        printf("0.  Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar();

        switch(choix) {
            case 1:
                remplir_consultation(tableau, *taille);
                break;
            case 2:
                afficher_consultation(tableau, *taille);
                break;
            case 3:
                inserer_consultation(tableau, taille);
                break;
            case 4:
                rechercher_consultation(tableau, *taille);
                break;
            case 5: {
                float cmin, cmax;
                printf("Cout minimum : "); scanf("%f", &cmin);
                printf("Cout maximum : "); scanf("%f", &cmax);
                recherche_par_intervalle_consultation(tableau, *taille, cmin, cmax);
                break;
            }
            case 6: {
                char prefixe[25];
                printf("Debut du nom du medecin : "); scanf("%s", prefixe);
                recherche_par_prefixe_consultation(tableau, *taille, prefixe);
                break;
            }
            case 7:
                supprimer_consultation(tableau, taille);
                break;
            case 8:
                modifier_consultation(tableau, *taille);
                break;
            case 9:
                tri_insertion_medecin(tableau, *taille);
                afficher_consultation(tableau, *taille);
                break;
            case 10:
                tri_rapide_cout(tableau, 0, *taille - 1);
                afficher_consultation(tableau, *taille);
                break;
            case 11:
                afficher_agregations_consultation(tableau, *taille);
                break;
            case 12:
                sauvegarder_consultations(tableau, *taille, "consultations.bin");
                break;
            case 13:
                charger_consultations(tableau, taille, "consultations.bin");
                afficher_consultation(tableau, *taille);
                break;
            case 0:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while(choix != 0);
}

// ===== MENU TABLEAU DYNAMIQUE PATIENTS =====
void menu_dynamique_patient(patient **tab, int *T, int *capacite) {
    int choix;
    do {
        printf("\n=== MENU TABLEAU DYNAMIQUE - PATIENTS ===\n");
        printf("1.  Inserer\n");
        printf("2.  Afficher\n");
        printf("3.  Rechercher par cle\n");
        printf("4.  Rechercher par intervalle (age)\n");
        printf("5.  Rechercher par prefixe (nom)\n");
        printf("6.  Supprimer\n");
        printf("7.  Modifier\n");
        printf("8.  Trier par nom (insertion)\n");
        printf("9.  Trier par age (rapide)\n");
        printf("10. Agregations statistiques\n");
        printf("11. Sauvegarder\n");
        printf("12. Charger\n");
        printf("0.  Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar();

        switch(choix) {
            case 1:
                inserer_patient_dyn(tab, T, capacite);
                break;
            case 2:
                afficher_patient_dyn(*tab, *T);
                break;
            case 3:
                rechercher_patient_dyn(*tab, *T);
                break;
            case 4: {
                int min, max;
                printf("Age minimum : "); scanf("%d", &min);
                printf("Age maximum : "); scanf("%d", &max);
                recherche_par_intervalle_patient_dyn(*tab, *T, min, max);
                break;
            }
            case 5: {
                char prefixe[25];
                printf("Debut du nom : "); scanf("%s", prefixe);
                recherche_par_prefixe_patient_dyn(*tab, *T, prefixe);
                break;
            }
            case 6:
                supprimer_patient_dyn(tab, T);
                break;
            case 7:
                modifier_patient_dyn(*tab, *T);
                break;
            case 8:
                tri_insertion_nom_dyn(*tab, *T);
                afficher_patient_dyn(*tab, *T);
                break;
            case 9:
                tri_rapide_age_dyn(*tab, 0, *T - 1);
                afficher_patient_dyn(*tab, *T);
                break;
            case 10:
                afficher_agregations_dyn(*tab, *T);
                break;
            case 11:
                sauvegarder_patients_dyn(*tab, *T, "patients_dyn.bin");
                break;
            case 12:
                charger_patients_dyn(tab, T, "patients_dyn.bin");
                afficher_patient_dyn(*tab, *T);
                break;
            case 0:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while(choix != 0);
}

// ===== MENU TABLEAU DYNAMIQUE CONSULTATIONS =====
void menu_dynamique_consultation(consultation **tab_consul, int *taille_consultation, int *capacite_consultation) {
    int choix;
    do {
        printf("\n=== MENU TABLEAU DYNAMIQUE - CONSULTATIONS ===\n");
        printf("1.  Inserer\n");
        printf("2.  Afficher\n");
        printf("3.  Rechercher par cle\n");
        printf("4.  Rechercher par intervalle (cout)\n");
        printf("5.  Rechercher par prefixe (medecin)\n");
        printf("6.  Supprimer\n");
        printf("7.  Modifier\n");
        printf("8.  Trier par medecin (insertion)\n");
        printf("9.  Trier par cout (rapide)\n");
        printf("10. Agregations statistiques\n");
        printf("11. Sauvegarder\n");
        printf("12. Charger\n");
        printf("0.  Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar();

        switch(choix) {
            case 1:
                inserer_consultation_dyn(tab_consul, taille_consultation, capacite_consultation);
                break;
            case 2:
                afficher_consultation_dyn(*tab_consul, *taille_consultation);
                break;
            case 3:
                rechercher_consultation_dyn(*tab_consul, *taille_consultation);
                break;
            case 4: {
                float cmin, cmax;
                printf("Cout minimum : "); scanf("%f", &cmin);
                printf("Cout maximum : "); scanf("%f", &cmax);
                recherche_par_intervalle_consultation_dyn(*tab_consul, *taille_consultation, cmin, cmax);
                break;
            }
            case 5: {
                char prefixe[25];
                printf("Debut du nom du medecin : "); scanf("%s", prefixe);
                recherche_par_prefixe_consultation_dyn(*tab_consul, *taille_consultation, prefixe);
                break;
            }
            case 6:
                supprimer_consultation_dyn(tab_consul, taille_consultation);
                break;
            case 7:
                modifier_consultation_dyn(*tab_consul, *taille_consultation);
                break;
            case 8:
                tri_insertion_medecin_dyn(*tab_consul, *taille_consultation);
                afficher_consultation_dyn(*tab_consul, *taille_consultation);
                break;
            case 9:
                tri_rapide_cout_dyn(*tab_consul, 0, *taille_consultation - 1);
                afficher_consultation_dyn(*tab_consul, *taille_consultation);
                break;
            case 10:
                afficher_agregations_consultation_dyn(*tab_consul, *taille_consultation);
                break;
            case 11:
                sauvegarder_consultations_dyn(*tab_consul, *taille_consultation, "consultations_dyn.bin");
                break;
            case 12:
                charger_consultations_dyn(tab_consul, taille_consultation, "consultations_dyn.bin");
                afficher_consultation_dyn(*tab_consul, *taille_consultation);
                break;
            case 0:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while(choix != 0);
}

// ===== MAIN =====
int main() {
    // Déclarations tableau statique
    int taille;
    do {
        printf("Entrez le nombre de patients : ");
        scanf("%d", &taille);
        getchar();
    } while (taille <= 0 || taille > 100);

    patient tableau[100];
    consultation tableau_consultation[100];
    int taille_consul = taille;

    // Déclarations tableau dynamique
    patient *tab = malloc(2 * sizeof(patient));
    int T = 0, capacite = 2;

    consultation *tab_consul = malloc(2 * sizeof(consultation));
    int taille_consultation = 0, capacite_consultation = 2;

    // Menu principal
    int choix;
    do {
        printf("\n=============================\n");
        printf("=== MENU PRINCIPAL ===\n");
        printf("=============================\n");
        printf("1. Tableau statique  - Patients\n");
        printf("2. Tableau statique  - Consultations\n");
        printf("3. Tableau dynamique - Patients\n");
        printf("4. Tableau dynamique - Consultations\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar();

        switch(choix) {
            case 1:
                menu_statique_patient(tableau, &taille);
                break;
            case 2:
                menu_statique_consultation(tableau_consultation, &taille_consul);
                break;
            case 3:
                menu_dynamique_patient(&tab, &T, &capacite);
                break;
            case 4:
                menu_dynamique_consultation(&tab_consul, &taille_consultation, &capacite_consultation);
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while(choix != 0);

    free(tab);
    free(tab_consul);
    return 0;
}