# Révisions Arbres

## Arbres

### Vocabulaire

- **Feuille** : noeud qui n'as pas de noeud suivant.
- **Branche** : chemin de la racine à une feuille (r-d-e)
- **Hauteur** (ou profondeur) : longueur de la plus longue branche

**Arbre binaire parfait**
- Tous les niveaux sont entièrement remplis sauf éventuellement le dernier
- Toutes les feuilles sont situées sur 2 niveaux au plus...
- ... et les feuilles du dernier niveau sont groupées sur la gauche.


### Représentations

#### Tableau

Buffer ayant pour ordre chaque sommet de gauche à droite de haut en bas.

```
        A
      /   \
     /     \
   B  C   D  E
         /    \
        F      G
```

Sous la formme d'un tableau : `A, B, C, D, E, NULL, NULL, F, G`.

Vous remarquer qu'on fait tout les éléments possible donc il y a des `NULL` dans le tableau !

**Avantage** : Parcours de l'arbre facile.
**Incovénient** : Place perdu.

**Formules**

On as donc, Sommet $i$ :
- fils en $2i + 1$ et $2i + 2$.
- père en $(i - 1)/2$

### Chainage

En gros :

```java
public class Arbre {

    private int valeur;
    private Arbre G;
    private Arbre D;

    public Arbre(int a, Arbre g, Arbre d) {
        valeur = a;
        G = g;
        D = d;
    }
}
```


## Tas

- C'est un **arbre binaire parfait**
- **valeur d'un noeud ≤ valeur de tous ses descendants**

En fait le but c'est de toujours avoir les valeurs les plus petite au dessus.

### Complexité

- $n$ itérations pour chaque boucle
- insérer et supprimer en $O(\log(n))$
- Complexité du tri par tas : $O(n\log(n))$
- tri par tas : très bon tri
