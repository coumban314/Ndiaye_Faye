#include<stdio.h>
#include<stdlib.h>
#include"patient.h"
#ifndef TABLEAU_STATIQUE_H
#define TABLEAU_STATIQUE_H
struct patient ;
typedef struct {
    int id ;
    Date date_consultation ;
    char medecin[25] ;
    char diagnostic[100] ;
    char traitement[100] ;
    int duree;
    float cout ;
    struct patient* patient ;
} consultation ;
#endif