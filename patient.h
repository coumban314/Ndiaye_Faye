#include<stdio.h>
#include<stdlib.h>
struct consultation ;
typedef struct Date {
    int jour ;
    int mois ;
    int annee;
} Date ;
typedef struct {
    int id ;
    char prenom[25] ;
    char nom[25] ;
    char sexe ;
    char adresse[50] ;
    char numTel[15] ;
    int age;
    Date date_naissance;
    float poids ;
    float taille ;
    struct consultation* consultations ;
    int nb_consultations ;
} patient ;
