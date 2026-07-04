import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv("resultats.csv")
df.columns = df.columns.str.strip()
df['structure'] = df['structure'].str.strip().str.lower()
df['operation'] = df['operation'].str.strip().str.lower()

couleurs = {
    'statique': 'blue',
    'dynamique': 'orange',
    'liste_chainee': 'green'
}
marqueurs = {
    'statique': 'o',
    'dynamique': 's',
    'liste_chainee': '^'
}

# ===== COURBE 1 : INSERTION - echelle lineaire =====
plt.figure()
for s in ["statique", "dynamique", "liste_chainee"]:
    d = df[(df['structure']==s) & (df['operation']=="insertion")].sort_values("n")
    if not d.empty:
        plt.plot(d['n'], d['temps'], label=s, color=couleurs[s], marker=marqueurs[s])
plt.title("Temps d'insertion (echelle lineaire)")
plt.xlabel("Nombre elements (n)")
plt.ylabel("Temps (secondes)")
plt.legend()
plt.grid(True)
plt.savefig("courbe_insertion_lineaire.png")
plt.show()

# ===== COURBE 2 : INSERTION - echelle logarithmique =====
plt.figure()
for s in ["statique", "dynamique", "liste_chainee"]:
    d = df[(df['structure']==s) & (df['operation']=="insertion")].sort_values("n")
    if not d.empty:
        plt.plot(d['n'], d['temps'], label=s, color=couleurs[s], marker=marqueurs[s])
plt.xscale('log')
plt.yscale('log')
plt.title("Temps d'insertion (echelle logarithmique)")
plt.xlabel("Nombre elements (n)")
plt.ylabel("Temps (secondes)")
plt.legend()
plt.grid(True)
plt.savefig("courbe_insertion_log.png")
plt.show()

# ===== COURBE 3 : TRI INSERTION - echelle lineaire =====
plt.figure()
for s in ["statique", "dynamique", "liste_chainee"]:
    d = df[(df['structure']==s) & (df['operation']=="tri_insertion")].sort_values("n")
    if not d.empty:
        plt.plot(d['n'], d['temps'], label=s, color=couleurs[s], marker=marqueurs[s])
plt.title("Temps de tri par insertion (echelle lineaire)")
plt.xlabel("Nombre elements (n)")
plt.ylabel("Temps (secondes)")
plt.legend()
plt.grid(True)
plt.savefig("courbe_tri_insertion_lineaire.png")
plt.show()

# ===== COURBE 4 : TRI INSERTION - echelle logarithmique =====
plt.figure()
for s in ["statique", "dynamique", "liste_chainee"]:
    d = df[(df['structure']==s) & (df['operation']=="tri_insertion")].sort_values("n")
    if not d.empty:
        plt.plot(d['n'], d['temps'], label=s, color=couleurs[s], marker=marqueurs[s])
plt.xscale('log')
plt.yscale('log')
plt.title("Temps de tri par insertion (echelle logarithmique)")
plt.xlabel("Nombre elements (n)")
plt.ylabel("Temps (secondes)")
plt.legend()
plt.grid(True)
plt.savefig("courbe_tri_insertion_log.png")
plt.show()

# ===== COURBE 5 : TRI RAPIDE - echelle lineaire =====
plt.figure()
for s in ["statique", "dynamique"]:
    d = df[(df['structure']==s) & (df['operation']=="tri_rapide")].sort_values("n")
    if not d.empty:
        plt.plot(d['n'], d['temps'], label=s, color=couleurs[s], marker=marqueurs[s])
plt.title("Temps de tri rapide (echelle lineaire)")
plt.xlabel("Nombre elements (n)")
plt.ylabel("Temps (secondes)")
plt.legend()
plt.grid(True)
plt.savefig("courbe_tri_rapide_lineaire.png")
plt.show()

# ===== COURBE 6 : RECHERCHE =====
plt.figure()
for s in ["statique", "liste_chainee"]:
    d = df[(df['structure']==s) & (df['operation']=="recherche")].sort_values("n")
    if not d.empty:
        plt.plot(d['n'], d['temps'], label=s, color=couleurs[s], marker=marqueurs[s])
plt.title("Temps de recherche")
plt.xlabel("Nombre elements (n)")
plt.ylabel("Temps (secondes)")
plt.legend()
plt.grid(True)
plt.savefig("courbe_recherche.png")
plt.show()

# ===== COURBE 7 : COURBE THEORIQUE vs EMPIRIQUE =====
plt.figure()
d = df[(df['structure']=='dynamique') & (df['operation']=='tri_rapide')].sort_values("n")
if not d.empty:
    n_vals = d['n'].values
    temps_vals = d['temps'].values
    # Courbe empirique
    plt.plot(n_vals, temps_vals, 'o-', label='Empirique', color='blue')
    # Courbe theorique n log n
    if len(n_vals) > 0:
        facteur = temps_vals[-1] / (n_vals[-1] * np.log2(n_vals[-1]))
        theorique = [facteur * n * np.log2(n) for n in n_vals]
        plt.plot(n_vals, theorique, '--', label='Theorique O(n log n)', color='red')
plt.title("Empirique vs Theorique (tri rapide dynamique)")
plt.xlabel("Nombre elements (n)")
plt.ylabel("Temps (secondes)")
plt.legend()
plt.grid(True)
plt.savefig("courbe_theorique_vs_empirique.png")
plt.show()

# ===== COURBE 8 : HISTOGRAMME COMPARATIF =====
plt.figure()
operations = ['insertion', 'tri_insertion', 'recherche']
structures = ['statique', 'dynamique', 'liste_chainee']
x = np.arange(len(operations))
width = 0.25

for i, s in enumerate(structures):
    valeurs = []
    for op in operations:
        d = df[(df['structure']==s) & (df['operation']==op)]
        if not d.empty:
            valeurs.append(d['temps'].max())
        else:
            valeurs.append(0)
    plt.bar(x + i*width, valeurs, width, label=s, color=list(couleurs.values())[i])

plt.title("Comparaison des structures (pire cas)")
plt.xlabel("Operation")
plt.ylabel("Temps (secondes)")
plt.xticks(x + width, operations)
plt.legend()
plt.grid(True, axis='y')
plt.savefig("courbe_histogramme.png")
plt.show()

print("Toutes les courbes ont ete generees !")