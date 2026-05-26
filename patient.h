#include<stdio.h>
#include<stdlib.h>
struct consultation ;
typedef struct {
    int id ;
    char prenom[25] ;
    char nom[25] ;
    char sexe ;
    char* adresse ;
    char* numTel ;
    int age;
    long date_naissance;
    float poids ;
    float taille ;
    struct consultation* consultations ;
    int nb_consultations ;
} patient ;
