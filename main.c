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
    int min, max;
    printf("Âge minimum : "); 
    scanf("%d", &min);
    printf("Âge maximum : "); 
    scanf("%d", &max);
    recherche_par_intervalle(tableau, taille, min, max);
    char prefixe[50];
   printf("Entrez le début du nom : ");
   scanf("%s", prefixe);
    recherche_par_prefixe(tableau, taille, prefixe);
    supprimer_patient(tableau, &taille);
    afficher_patient(tableau, taille);
    modifier_patient(tableau, taille);
    afficher_patient(tableau, taille);
    tri_insertion_nom(tableau, taille);
    afficher_patient(tableau, taille);
    tri_rapide_age(tableau, 0, taille - 1);
    afficher_patient(tableau, taille);
    afficher_agregations(tableau, taille);
    sauvegarder_patients(tableau, taille, "patients.bin");
    charger_patients(tableau, &taille, "patients.bin");
    afficher_patient(tableau, taille);
    consultation tableau_consultation[100];
    remplir_consultation(tableau_consultation, taille);
    afficher_consultation(tableau_consultation, taille);
    inserer_consultation(tableau_consultation, &taille);
    afficher_consultation(tableau_consultation, taille);
    tri_insertion_medecin(tableau_consultation, taille);
    afficher_consultation(tableau_consultation, taille);
    tri_rapide_cout(tableau_consultation, 0, taille - 1);
    afficher_consultation(tableau_consultation, taille);
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
    afficher_patient_dyn(tab, T);
    modifier_patient_dyn(tab, T);
    afficher_patient_dyn(tab, T);
    int taille_consultation = 0;
    int capacite_consultation = 2;
    consultation *T = malloc(capacite_consultation * sizeof(consultation));
    inserer_consultation_dyn(&T, &taille_consultation, &capacite_consultation);
    afficher_consultation_dyn(T, taille_consultation);
    rechercher_consultation_dyn(T, taille_consultation);
    recherche_par_intervalle_consultation_dyn(T, taille_consultation, 100.0, 500.0);
    recherche_par_prefixe_consultation_dyn(T, taille_consultation, "Dr.");
    supprimer_consultation_dyn(&T, &taille_consultation);
    afficher_consultation_dyn(T, taille_consultation);
    modifier_consultation_dyn(T, taille_consultation);
    afficher_consultation_dyn(T, taille_consultation);
    afficher_agregations_consultation(tableau_consultation, taille);
sauvegarder_consultations(tableau_consultation, taille, "consultations.bin");
charger_consultations(tableau_consultation, &taille, "consultations.bin");
afficher_consultation(tableau_consultation, taille);
}