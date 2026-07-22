#include "patient.c"
#include <stdio.h>
#include <string.h>

// ===== CREER UN PATIENT =====
patient creer_patient() {
    patient p;
    
    printf("=== Saisie d'un nouveau patient ===\n");
    printf("ID : ");
    scanf("%d", &p.id);
    getchar(); 

    printf("Prenom : ");
    fgets(p.prenom, 25, stdin);
    p.prenom[strcspn(p.prenom, "\n")] = 0; 

    printf("Nom : ");
    fgets(p.nom, 25, stdin);
    p.nom[strcspn(p.nom, "\n")] = 0;

    printf("Sexe (H/F) : ");
    scanf("%c", &p.sexe);
    getchar();

    printf("Adresse : ");
    fgets(p.adresse, 50, stdin);
    p.adresse[strcspn(p.adresse, "\n")] = 0;

    printf("Telephone : ");
    fgets(p.numTel, 15, stdin);
    p.numTel[strcspn(p.numTel, "\n")] = 0;

    printf("Age : ");
    scanf("%d", &p.age);
    
    printf("Date de naissance jj mm aaaa : ");
    scanf("%d %d %d", &p.date_naissance.jour, &p.date_naissance.mois, &p.date_naissance.annee);

    printf("Poids en kg : ");
    scanf("%f", &p.poids);

    printf("Taille en m : ");
    scanf("%f", &p.taille);

    p.consultations = NULL;  
    p.nb_consultations = 0;

    printf("Patient cree avec succes !\n");
    return p;
}

// ===== AFFICHER UN PATIENT =====
void afficher_patient(patient p) {
    printf("\n--- Fiche Patient ---\n");
    printf("ID : %d\n", p.id);
    printf("Nom Complet : %s %s\n", p.prenom, p.nom);
    printf("Sexe : %c\n", p.se
