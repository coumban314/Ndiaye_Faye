# Projet LMI2 - Gestion de Dossiers Médicaux

Projet Algorithmique et Structures de Données - LMI2 UIDT 2025-2026

## Description

Ce projet a été réalisé dans le cadre du module **Algorithmique et 
Structures de Données (ASD)** de la Licence 2 Mathématiques-Informatique 
à l'Université Iba Der Thiam de Thiès.

L'objectif est d'étudier et de comparer les performances des 
**tableaux statiques**, **tableaux dynamiques** et **listes chaînées** 
pour la gestion d'un système de dossiers médicaux comprenant des 
patients et leurs consultations.

## Organisation du projet

| Fichier | Rôle |
|---|---|
| `main.c` | Programme principal avec menu interactif |
| `patient.c` / `patient.h` | Définition de la structure patient |
| `consultation.c` / `consultation.h` | Définition de la structure consultation |
| `tableau_statique.c` / `tableau_statique.h` | Tableau statique |
| `tableau_dynamique.c` / `tableau_dynamique.h` | Tableau dynamique |
| `liste_chainee.c` / `liste_chainee.h` | Liste chaînée |
| `benchmark.c` | Mesures de performances |
| `courbes.py` | Génération des courbes avec Python |
| `resultats.csv` | Résultats des benchmarks |
| `courbe_insertion_lineaire.png` | Courbe insertion échelle linéaire |
| `courbe_insertion_log.png` | Courbe insertion échelle logarithmique |
| `courbe_recherche.png` | Courbe des temps de recherche |
| `courbe_tri_insertion_lineaire.png` | Courbe tri par insertion |
| `courbe_tri_insertion_log.png` | Courbe tri par insertion log |
| `courbe_tri_rapide_lineaire.png` | Courbe tri rapide |
| `courbe_theorique_vs_empirique.png` | Courbe théorique vs empirique |
| `courbe_histogramme.png` | Histogramme comparatif |
| `Makefile` | Automatisation de la compilation |
| `lien_github.txt` | Lien vers le dépôt GitHub |

## Prérequis

- GCC (MinGW sous Windows)
- Python 3 avec matplotlib et pandas (pour les courbes)

## Compilation

Avec GCC :

```bash
gcc main.c tableau_statique.c tableau_dynamique.c liste_chainee.c -o test -lm
```

Ou avec le Makefile :

```bash
make
```

## Exécution

Sous Linux/Mac :

```bash
./test
```

Sous Windows :

```bash
./test
```

## Utilisation

Le programme affiche un **écran d'accueil** puis un **menu principal interactif** :
+==========================================+
|        UNIVERSITE IBA DER THIAM          |
|              DE THIES                    |
|    UFR Sciences et Technologies          |
+==========================================+
|   Algorithmique et Structures de         |
|            Donnees - LMI 2               |
+==========================================+
|  Projet : Gestion de Dossiers Medicaux   |
+------------------------------------------+
|  Realise par :                           |
|    - Coumba NDIAYE                       |
|    - Moussa FAYE                         |
+------------------------------------------+
|  Encadrant : Dr Abdoulaye DIALLO         |
+==========================================+
+==========================================+
|           MENU PRINCIPAL                 |
|    Gestion de Dossiers Medicaux          |
+==========================================+
|  1. Tableau statique  - Patients         |
|  2. Tableau statique  - Consultations    |
|  3. Tableau dynamique - Patients         |
|  4. Tableau dynamique - Consultations    |
|  5. Liste chainee     - Patients         |
|  6. Liste chainee     - Consultations    |
+------------------------------------------+
|  0. Quitter                              |
+==========================================+

Chaque option ouvre un sous-menu avec toutes les opérations disponibles :
insertion, affichage, recherche (clé, intervalle, préfixe), suppression, 
modification, tri, agrégations statistiques et persistance.

## Benchmark et courbes

Pour générer les mesures de performances :

```bash
gcc benchmark.c tableau_statique.c tableau_dynamique.c liste_chainee.c -o benchmark -lm
./benchmark
```

Pour générer les courbes :

```bash
pip install matplotlib pandas
python courbes.py
```

## Opérations implémentées

| Opération | Tableau statique | Tableau dynamique | Liste chaînée |
|---|---|---|---|
| Insertion | ✅ | ✅ | ✅ (tête et queue) |
| Recherche par clé | ✅ | ✅ | ✅ |
| Recherche par intervalle | ✅ | ✅ | ✅ |
| Recherche par préfixe | ✅ | ✅ | ✅ |
| Suppression | ✅ | ✅ | ✅ |
| Modification | ✅ | ✅ | ✅ |
| Tri par insertion | ✅ | ✅ | ✅ |
| Tri rapide | ✅ | ✅ | ❌ |
| Agrégations statistiques | ✅ | ✅ | ✅ |
| Persistance binaire | ✅ | ✅ | ✅ |

## Auteurs

- **Coumba Ndiaye**
- **Moussa Faye**

Licence 2 Mathématiques-Informatique (LMI2)  
Université Iba Der Thiam de Thiès  
Année universitaire 2025-2026  
Enseignant responsable : Dr Abdoulaye Diallo