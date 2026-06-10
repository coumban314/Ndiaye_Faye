#include "../projet_LMI2/patient.h"
#include"../projet_LMI2/consultation.h"

void remplir_patient(patient tableau[], int taille);
void afficher_patient(patient tableau[],int taille);
void inserer_Patient(patient tableau[], int *n);
void rechercher_patient(patient tableau[], int taille );
void recherche_par_intervalle(patient tableau[], int taille, int age_min, int age_max);
void recherche_par_prefixe(patient tableau[], int taille, const char* prefixe);
void supprimer_patient(patient tableau[], int *taille);
void modifier_patient(patient tableau[], int taille);
void tri_rapide_age(patient tableau[], int bas, int haut);

void remplir_consultation(consultation tableau[], int taille);
void afficher_consultation(consultation tableau[], int taille);
void inserer_consultation(consultation tableau[], int *n);
void rechercher_consultation(consultation tableau[], int taille);
void supprimer_consultation(consultation tableau[], int *taille);
void afficher_consultation(consultation tableau[], int taille);
void modifier_consultation(consultation tableau[], int taille);