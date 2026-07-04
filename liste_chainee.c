#include "liste_chainee.h"

// ===== INITIALISATION =====
void initialiser_liste(ListeChainee* liste) {
    liste->tete = NULL;
    liste->taille = 0;
}

// ===== INSERTION EN TETE =====
void inserer_tete(ListeChainee* liste, patient p) {
    Noeud* nouveau = malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        printf("Erreur allocation memoire\n");
        return;
    }
    nouveau->data = p;
    nouveau->suivant = liste->tete;
    liste->tete = nouveau;
    liste->taille++;
    printf("Patient insere en tete avec succes.\n");
}

// ===== INSERTION EN QUEUE =====
void inserer_queue(ListeChainee* liste, patient p) {
    Noeud* nouveau = malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        printf("Erreur allocation memoire\n");
        return;
    }
    nouveau->data = p;
    nouveau->suivant = NULL;

    if (liste->tete == NULL) {
        liste->tete = nouveau;
    } else {
        Noeud* courant = liste->tete;
        while (courant->suivant != NULL)
            courant = courant->suivant;
        courant->suivant = nouveau;
    }
    liste->taille++;
    printf("Patient insere en queue avec succes.\n");
}

// ===== AFFICHAGE =====
void afficher_liste(ListeChainee* liste) {
    if (liste->tete == NULL) {
        printf("Liste vide.\n");
        return;
    }
    Noeud* courant = liste->tete;
    int i = 1;
    while (courant != NULL) {
        printf("Patient %d :\n", i);
        printf("  ID : %d\n", courant->data.id);
        printf("  Prenom : %s\n", courant->data.prenom);
        printf("  Nom : %s\n", courant->data.nom);
        printf("  Sexe : %c\n", courant->data.sexe);
        printf("  Age : %d\n", courant->data.age);
        printf("  Adresse : %s\n", courant->data.adresse);
        printf("  Telephone : %s\n", courant->data.numTel);
        printf("  Poids : %.2f\n", courant->data.poids);
        printf("  Taille : %.2f\n", courant->data.taille);
        courant = courant->suivant;
        i++;
    }
}

// ===== RECHERCHE PAR CLE =====
void rechercher_liste(ListeChainee* liste, int id) {
    Noeud* courant = liste->tete;
    while (courant != NULL) {
        if (courant->data.id == id) {
            printf("Patient trouve :\n");
            printf("  ID : %d\n", courant->data.id);
            printf("  Prenom : %s\n", courant->data.prenom);
            printf("  Nom : %s\n", courant->data.nom);
            printf("  Age : %d\n", courant->data.age);
            return;
        }
        courant = courant->suivant;
    }
    printf("Patient non trouve.\n");
}

// ===== RECHERCHE PAR INTERVALLE =====
void recherche_intervalle_liste(ListeChainee* liste, int age_min, int age_max) {
    int trouve = 0;
    Noeud* courant = liste->tete;
    printf("\nPatients dont l'age est entre %d et %d :\n", age_min, age_max);
    while (courant != NULL) {
        if (courant->data.age >= age_min && courant->data.age <= age_max) {
            printf("  ID : %d, Nom : %s, Age : %d\n",
                courant->data.id, courant->data.nom, courant->data.age);
            trouve = 1;
        }
        courant = courant->suivant;
    }
    if (!trouve)
        printf("Aucun patient trouve.\n");
}

// ===== RECHERCHE PAR PREFIXE =====
void recherche_prefixe_liste(ListeChainee* liste, const char* prefixe) {
    int trouve = 0;
    Noeud* courant = liste->tete;
    printf("\nPatients dont le nom commence par \"%s\" :\n", prefixe);
    while (courant != NULL) {
        if (strncmp(courant->data.nom, prefixe, strlen(prefixe)) == 0) {
            printf("  ID : %d, Nom : %s, Age : %d\n",
                courant->data.id, courant->data.nom, courant->data.age);
            trouve = 1;
        }
        courant = courant->suivant;
    }
    if (!trouve)
        printf("Aucun patient trouve.\n");
}

// ===== SUPPRESSION =====
void supprimer_liste(ListeChainee* liste, int id) {
    if (liste->tete == NULL) {
        printf("Liste vide.\n");
        return;
    }
    // Cas : suppression de la tete
    if (liste->tete->data.id == id) {
        Noeud* temp = liste->tete;
        liste->tete = liste->tete->suivant;
        free(temp);
        liste->taille--;
        printf("Patient supprime avec succes.\n");
        return;
    }
    // Cas : suppression ailleurs
    Noeud* courant = liste->tete;
    while (courant->suivant != NULL) {
        if (courant->suivant->data.id == id) {
            Noeud* temp = courant->suivant;
            courant->suivant = temp->suivant;
            free(temp);
            liste->taille--;
            printf("Patient supprime avec succes.\n");
            return;
        }
        courant = courant->suivant;
    }
    printf("Patient non trouve.\n");
}

// ===== MODIFICATION =====
void modifier_liste(ListeChainee* liste, int id) {
    Noeud* courant = liste->tete;
    while (courant != NULL) {
        if (courant->data.id == id) {
            printf("Nouvelles informations :\n");
            printf("Prenom : ");
            fgets(courant->data.prenom, 25, stdin);
            printf("Nom : ");
            fgets(courant->data.nom, 25, stdin);
            printf("Age : ");
            scanf("%d", &courant->data.age);
            getchar();
            printf("Patient modifie avec succes.\n");
            return;
        }
        courant = courant->suivant;
    }
    printf("Patient non trouve.\n");
}

// ===== TRI PAR INSERTION =====
void tri_insertion_liste(ListeChainee* liste) {
    if (liste->tete == NULL || liste->tete->suivant == NULL)
        return;

    Noeud* trie = NULL;
    Noeud* courant = liste->tete;

    while (courant != NULL) {
        Noeud* suivant = courant->suivant;
        if (trie == NULL || strcmp(courant->data.nom, trie->data.nom) <= 0) {
            courant->suivant = trie;
            trie = courant;
        } else {
            Noeud* temp = trie;
            while (temp->suivant != NULL &&
                   strcmp(courant->data.nom, temp->suivant->data.nom) > 0) {
                temp = temp->suivant;
            }
            courant->suivant = temp->suivant;
            temp->suivant = courant;
        }
        courant = suivant;
    }
    liste->tete = trie;
    printf("Liste triee par nom.\n");
}

// ===== AGREGATIONS =====
void agregations_liste(ListeChainee* liste) {
    if (liste->tete == NULL) {
        printf("Liste vide.\n");
        return;
    }
    int min = liste->tete->data.age;
    int max = liste->tete->data.age;
    float somme = 0;
    int n = 0;

    Noeud* courant = liste->tete;
    while (courant != NULL) {
        int age = courant->data.age;
        if (age < min) min = age;
        if (age > max) max = age;
        somme += age;
        n++;
        courant = courant->suivant;
    }
    float moyenne = somme / n;

    // Ecart-type
    float somme_ecart = 0;
    courant = liste->tete;
    while (courant != NULL) {
        somme_ecart += (courant->data.age - moyenne) * (courant->data.age - moyenne);
        courant = courant->suivant;
    }
    float ecart_type = sqrt(somme_ecart / n);

    printf("\n=== Agregations statistiques (age) ===\n");
    printf("Minimum    : %d\n", min);
    printf("Maximum    : %d\n", max);
    printf("Moyenne    : %.2f\n", moyenne);
    printf("Ecart-type : %.2f\n", ecart_type);
}

// ===== PERSISTANCE =====
void sauvegarder_liste(ListeChainee* liste, const char* fichier) {
    FILE* f = fopen(fichier, "wb");
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }
    fwrite(&liste->taille, sizeof(int), 1, f);
    Noeud* courant = liste->tete;
    while (courant != NULL) {
        fwrite(&courant->data, sizeof(patient), 1, f);
        courant = courant->suivant;
    }
    fclose(f);
    printf("Liste sauvegardee dans %s.\n", fichier);
}

void charger_liste(ListeChainee* liste, const char* fichier) {
    FILE* f = fopen(fichier, "rb");
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }
    int taille;
    fread(&taille, sizeof(int), 1, f);
    for (int i = 0; i < taille; i++) {
        patient p;
        fread(&p, sizeof(patient), 1, f);
        inserer_queue(liste, p);
    }
    fclose(f);
    printf("Liste chargee depuis %s.\n", fichier);
}

// ===== LIBERATION MEMOIRE =====
void liberer_liste(ListeChainee* liste) {
    Noeud* courant = liste->tete;
    while (courant != NULL) {
        Noeud* temp = courant;
        courant = courant->suivant;
        free(temp);
    }
    liste->tete = NULL;
    liste->taille = 0;
}

// ===== CONSULTATIONS =====
void initialiser_liste_consul(ListeConsultation* liste) {
    liste->tete = NULL;
    liste->taille = 0;
}

void inserer_tete_consul(ListeConsultation* liste, consultation c) {
    NoeudConsult* nouveau = malloc(sizeof(NoeudConsult));
    if (nouveau == NULL) {
        printf("Erreur allocation memoire\n");
        return;
    }
    nouveau->data = c;
    nouveau->suivant = liste->tete;
    liste->tete = nouveau;
    liste->taille++;
    printf("Consultation inseree en tete avec succes.\n");
}

void inserer_queue_consul(ListeConsultation* liste, consultation c) {
    NoeudConsult* nouveau = malloc(sizeof(NoeudConsult));
    if (nouveau == NULL) {
        printf("Erreur allocation memoire\n");
        return;
    }
    nouveau->data = c;
    nouveau->suivant = NULL;

    if (liste->tete == NULL) {
        liste->tete = nouveau;
    } else {
        NoeudConsult* courant = liste->tete;
        while (courant->suivant != NULL)
            courant = courant->suivant;
        courant->suivant = nouveau;
    }
    liste->taille++;
    printf("Consultation inseree en queue avec succes.\n");
}

void afficher_liste_consul(ListeConsultation* liste) {
    if (liste->tete == NULL) {
        printf("Liste vide.\n");
        return;
    }
    NoeudConsult* courant = liste->tete;
    int i = 1;
    while (courant != NULL) {
        printf("Consultation %d :\n", i);
        printf("  ID : %d\n", courant->data.id);
        printf("  Medecin : %s\n", courant->data.medecin);
        printf("  Diagnostic : %s\n", courant->data.diagnostic);
        printf("  Cout : %.2f\n", courant->data.cout);
        courant = courant->suivant;
        i++;
    }
}

void rechercher_liste_consul(ListeConsultation* liste, int id) {
    NoeudConsult* courant = liste->tete;
    while (courant != NULL) {
        if (courant->data.id == id) {
            printf("Consultation trouvee :\n");
            printf("  ID : %d\n", courant->data.id);
            printf("  Medecin : %s\n", courant->data.medecin);
            printf("  Cout : %.2f\n", courant->data.cout);
            return;
        }
        courant = courant->suivant;
    }
    printf("Consultation non trouvee.\n");
}

void supprimer_liste_consul(ListeConsultation* liste, int id) {
    if (liste->tete == NULL) {
        printf("Liste vide.\n");
        return;
    }
    if (liste->tete->data.id == id) {
        NoeudConsult* temp = liste->tete;
        liste->tete = liste->tete->suivant;
        free(temp);
        liste->taille--;
        printf("Consultation supprimee avec succes.\n");
        return;
    }
    NoeudConsult* courant = liste->tete;
    while (courant->suivant != NULL) {
        if (courant->suivant->data.id == id) {
            NoeudConsult* temp = courant->suivant;
            courant->suivant = temp->suivant;
            free(temp);
            liste->taille--;
            printf("Consultation supprimee avec succes.\n");
            return;
        }
        courant = courant->suivant;
    }
    printf("Consultation non trouvee.\n");
}

void modifier_liste_consul(ListeConsultation* liste, int id) {
    NoeudConsult* courant = liste->tete;
    while (courant != NULL) {
        if (courant->data.id == id) {
            printf("Nouvelles informations :\n");
            printf("Medecin : ");
            fgets(courant->data.medecin, 25, stdin);
            printf("Diagnostic : ");
            fgets(courant->data.diagnostic, 100, stdin);
            printf("Cout : ");
            scanf("%f", &courant->data.cout);
            getchar();
            printf("Consultation modifiee avec succes.\n");
            return;
        }
        courant = courant->suivant;
    }
    printf("Consultation non trouvee.\n");
}

void liberer_liste_consul(ListeConsultation* liste) {
    NoeudConsult* courant = liste->tete;
    while (courant != NULL) {
        NoeudConsult* temp = courant;
        courant = courant->suivant;
        free(temp);
    }
    liste->tete = NULL;
    liste->taille = 0;
}