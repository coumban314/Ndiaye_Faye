
#ifndef TABLEAU_DYNAMIQUE_H
#define TABLEAU_DYNAMIQUE_H

#include "patient.h"
#include "consultation.h"
#include <stdlib.h>
void inserer_patient_dyn(patient **tableau, int *taille, int *capacite);
void tri_insertion_nom_dyn(patient *tableau, int taille);
int partition_dyn(patient *tableau, int bas, int haut);
void tri_rapide_age_dyn(patient *tableau, int bas, int haut);
void afficher_patient_dyn(patient *tableau, int taille);
void rechercher_patient_dyn(patient *tableau, int taille);
void recherche_par_intervalle_patient_dyn(patient *tableau, int taille, int age_min, int age_max);
void recherche_par_prefixe_patient_dyn(patient *tableau, int taille, const char* prefixe);
void supprimer_patient_dyn(patient **tableau, int *taille);
void modifier_patient_dyn(patient *tableau, int taille);
int minimum_age_dyn(patient *tableau, int taille);
int maximum_age_dyn(patient *tableau, int taille);
float moyenne_age_dyn(patient *tableau, int taille);
float mediane_age_dyn(patient *tableau, int taille);
float ecart_type_age_dyn(patient *tableau, int taille);
void tri_rapide_age_dyn(patient *tableau, int bas, int haut);
void afficher_agregations_dyn(patient *tableau, int taille);
void sauvegarder_patients_dyn(patient *tableau, int taille, const char* fichier);
void charger_patients_dyn(patient **tableau, int* taille, const char* fichier);
void inserer_consultation_dyn(consultation **tableau, int *taille , int *capacite);
void tri_insertion_medecin_dyn(consultation *tableau, int taille);
int partition_consultation_dyn(consultation *tableau, int bas, int haut);
void tri_rapide_cout_dyn(consultation *tableau, int bas, int haut);
void rechercher_consultation_dyn(consultation *tableau, int taille);
void supprimer_consultation_dyn(consultation **tableau, int *taille);
void modifier_consultation_dyn(consultation *tableau, int taille);
float minimum_cout_dyn(consultation *tableau, int taille);
float maximum_cout_dyn(consultation *tableau, int taille);
float moyenne_cout_dyn(consultation *tableau, int taille);
float mediane_cout_dyn(consultation *tableau, int taille);
float ecart_type_cout_dyn(consultation *tableau, int taille);
void afficher_agregations_consultation_dyn(consultation *tableau, int taille);
void sauvegarder_consultations_dyn(consultation *tableau, int taille, const char* fichier);
void charger_consultations_dyn(consultation **tableau, int* taille, const char* fichier);
// prototypes des fonctions

#endif