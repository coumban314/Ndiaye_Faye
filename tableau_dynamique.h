
#ifndef TABLEAU_DYNAMIQUE_H
#define TABLEAU_DYNAMIQUE_H

#include "patient.h"
#include <stdlib.h>
void inserer_patient_dyn(patient **tableau, int *taille, int *capacite);
void afficher_patient_dyn(patient *tableau, int taille);
void rechercher_patient_dyn(patient *tableau, int taille);
void supprimer_patient_dyn(patient **tableau, int *taille);
void modifier_patient_dyn(patient *tableau, int taille);
// prototypes des fonctions

#endif