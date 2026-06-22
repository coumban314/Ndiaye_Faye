# Ndiaye_Faye

Projet Algorithmique et Structures de Données - LMI2 UIDT 2025-2026

# Projet LMI2 - Gestion de Patients et Consultations

## Description

Ce projet a été réalisé dans le cadre du module **Algorithmique et Structures de Données (ASD)** de la Licence 2 Mathématiques-Informatique à l'Université Iba Der Thiam de Thiès.

L'objectif est d'étudier et de comparer les performances des **tableaux statiques** et **tableaux dynamiques** pour la gestion d'un système de dossiers médicaux comprenant des patients et leurs consultations.

Le projet implémente plusieurs opérations sur les données :

* Insertion d'un patient
* Recherche d'un patient
* Modification des informations
* Suppression d'un patient
* Tri des enregistrements
* Calcul d'agrégations statistiques
* Sauvegarde et chargement depuis un fichier
* Mesures expérimentales de performances (benchmark)

## Organisation du projet

* `main.c` : programme principal
* `patient.c` / `patient.h` : gestion des patients
* `consultation.c` / `consultation.h` : gestion des consultations
* `tableau_statique.c` / `tableau_statique.h` : implémentation du tableau statique
* `tableau_dynamique.c` / `tableau_dynamique.h` : implémentation du tableau dynamique
* `benchmark.c` : mesures de performances
* `courbes.py` : génération des courbes
* `resultats.csv` : résultats des benchmarks
* `courbe_insertion.png` : courbe des temps d'insertion
* `courbe_tri.png` : courbe des temps de tri
* `Makefile` : automatisation de la compilation

## Compilation

Avec GCC :

```bash
gcc *.c -o test
```

Ou à l'aide du Makefile :

```bash
make
```

## Exécution

Sous Linux :

```bash
./test
```

Sous Windows :

```bash
test.exe
```

## Analyse réalisée

Le projet compare les performances des tableaux statiques et dynamiques à travers :

* Les temps d'insertion
* Les temps de recherche
* Les temps de tri
* L'utilisation de la mémoire

Les résultats sont présentés sous forme de tableaux et de courbes.

## Auteurs

* Coumba Ndiaye
* Moussa Faye

Licence 2 Mathématiques-Informatique (LMI2)

Université Iba Der Thiam de Thiès

Année universitaire 2025-2026
