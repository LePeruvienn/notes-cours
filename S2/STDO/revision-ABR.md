# Révision ABR

## Arbre ABR Normal

En gros c'est :

```
class ABR {

    private int cle;
    private String element;
    private ABR gauche;
    private ABR droit;

    public ABR(int a, String s, ABR g, ABR d) {
        cle = a;
        element = s;
        gauche= g;
        droit=d;
    }
}
```

### Recherche 

On cherche un nombre $n$ depuis le sommet $i$ qui as une clé $k$.

- Si $n == k$ on as trouver alors $n$.
- Si $n < $k$ on va dans le noeud gauche.
- Si $n > $k$ on va dans le noeud droite.

### Insertion

On fait une recherche jusqu'a arriver au noeud feuille.

Puis on le place à droite ou à gauche selon le besoin

### Suppression

Si supprimer le noeud ne pose pas de problème (fueille ou que 1 noeud enfant)

- Alors c'est OK soit on fait rien soit juste on shift l'arbre


Si par contre c'est la merde alors :

- On cherche la plus petite clé de l'arbre droit du sommet qu'on veut supprimer.

- et on remplace le sommet qu'on viens de supprimer par celuila.

### Complexité

- Complexité: O(h(a))$
- avec $log_2(n) \le h(a) \le n-1$
- complexité en moyenne: $O(log(n))$

**Problèmes**
- Quand les arbres ne sont pas équilibrer le temps de recherche explooose.

Le but du coup c'est de créer des ABR les plus équilibrer possible.


## Arbre H-équilibrer

**Déséquilibre**
- `déseq(a) = h(a.g)-h(a.d)`
- `déseq(a) = 0 si a = Ø`

**Notations des déséquilibres pour les noeuds**:

- `=` si `h(a.g) = h(a.d)`
- `-` si `h(a.g) = h(a.d)-1`
- `--` si `h(a.g) = h(a.d)-2`
- `+` si `h(a.g) = h(a.d)+1`
-  `++` si `h(a.g) = h(a.d)+2`


### Rotations

En gros le but c'est de trouver les endroit ou il ya le plus de déséquilibre proche de la racine, afin de faire des rotation si nécessaire pour le réquilibre.

On commence par réquilibrer les noeud les plus bas.


### Complexité

- même principe que dans un arbre binaire de
- recherche mais en rééquilibrant par rotations après l'opération si c'est nécessaire (si a n'est plus H équilibré)

Dans les arbres AVL
- recherche, adjonction, suppression =  en $O(log_2(n))$
