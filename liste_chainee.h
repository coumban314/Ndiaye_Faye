#ifndef LISTE_CHAINEE_H
#define LISTE_CHAINEE_H

#include "patient.h"
#include "consultation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Noeud {
    patient data;
    struct Noeud* suivant;
} Noeud;

typedef struct {
    Noeud* tete;
    int taille;
} ListeChainee;

typedef struct NoeudConsult {
    consultation data;
    struct NoeudConsult* suivant;
} NoeudConsult;

typedef struct {
    NoeudConsult* tete;
    int taille;
} ListeConsultation;

// Fonctions patients
void initialiser_liste(ListeChainee* liste);
void inserer_tete(ListeChainee* liste, patient p);
void inserer_queue(ListeChainee* liste, patient p);
void afficher_liste(ListeChainee* liste);
void rechercher_liste(ListeChainee* liste, int id);
void recherche_intervalle_liste(ListeChainee* liste, int age_min, int age_max);
void recherche_prefixe_liste(ListeChainee* liste, const char* prefixe);
void supprimer_liste(ListeChainee* liste, int id);
void modifier_liste(ListeChainee* liste, int id);
void tri_insertion_liste(ListeChainee* liste);
void agregations_liste(ListeChainee* liste);
void sauvegarder_liste(ListeChainee* liste, const char* fichier);
void charger_liste(ListeChainee* liste, const char* fichier);
void liberer_liste(ListeChainee* liste);

// Fonctions consultations
void initialiser_liste_consul(ListeConsultation* liste);
void inserer_tete_consul(ListeConsultation* liste, consultation c);
void inserer_queue_consul(ListeConsultation* liste, consultation c);
void afficher_liste_consul(ListeConsultation* liste);
void rechercher_liste_consul(ListeConsultation* liste, int id);
void supprimer_liste_consul(ListeConsultation* liste, int id);
void modifier_liste_consul(ListeConsultation* liste, int id);
void liberer_liste_consul(ListeConsultation* liste);

#endif