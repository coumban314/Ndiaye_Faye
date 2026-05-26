#include<stdio.h>
#include<stdlib.h>
struct patient ;
typedef struct {
    int id ;
    long date_consultation ;
    char medecin[25] ;
    char* diagnostic ;
    char* traitement ;
    int duree;
    float cout ;
    struct patient* patient ;
} consultation ;