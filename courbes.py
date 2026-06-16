import matplotlib.pyplot as plt
import pandas as pd

# Lire le fichier CSV
df = pd.read_csv('resultats.csv')

# Courbe 1 : Tri insertion vs Tri rapide
fig, ax = plt.subplots()
statique = df[df['structure'] == 'statique']
tri_ins = statique[statique['operation'] == 'tri_insertion']
tri_rap = statique[statique['operation'] == 'tri_rapide']

ax.plot(tri_ins['n'], tri_ins['temps'], marker='o', label='Tri insertion')
ax.plot(tri_rap['n'], tri_rap['temps'], marker='s', label='Tri rapide')
ax.set_xlabel('Nombre elements (n)')
ax.set_ylabel('Temps (secondes)')
ax.set_title('Tri insertion vs Tri rapide')
ax.legend()
plt.savefig('courbe_tri.png')
plt.show()

# Courbe 2 : Insertion statique vs dynamique
fig, ax = plt.subplots()
ins_stat = df[(df['structure'] == 'statique') & (df['operation'] == 'insertion')]
ins_dyn  = df[(df['structure'] == 'dynamique') & (df['operation'] == 'insertion')]

ax.plot(ins_stat['n'], ins_stat['temps'], marker='o', label='Statique')
ax.plot(ins_dyn['n'],  ins_dyn['temps'],  marker='s', label='Dynamique')
ax.set_xlabel('Nombre elements (n)')
ax.set_ylabel('Temps (secondes)')
ax.set_title('Insertion statique vs dynamique')
ax.legend()
plt.savefig('courbe_insertion.png')
plt.show()

print("Courbes generees avec succes !")