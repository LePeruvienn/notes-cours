---
title: CM1
---

Lien vers les cours (le lien marche pas sur le réseau de l'école):

```
tinyurl.com/sdd2526
```

ou 

```
https://cnam-my.sharepoint.com/personal/eric_soutil_lecnam_net/_layouts/15/Doc.aspx?sourcedoc={a94bdec3-fad0-430f-aa7e-a3af6fb86d19}&action=view&wd=target%28Nouvelle%20section%201.one%7C44889ca2-52de-47dc-8548-7808d0511bd0%2FLiens%20utiles%7C5afbeebd-bfe3-479e-8815-db37046f6952%2F%29&wdorigin=NavigationUrl
```

Après tu clique sur `sharepoint_2526` pour avoir accès au cours

Mail du prof :

```
eric.soutil@lecnam.net
```

# Structure de données élémetaire

On va faire

- Complexité
- structures complexes
- Algo
- tables de hachage
- Organisation de données volumineuses

Tout ça en JAVA 🤓

## Introduction

### Structure de données

Permet de stocker des données pour en facilier l'accès et la modif

Elle regroupe :
- Un certain nombre de onnées
- Un ensemble d'opération pouvant être appliquer à ces données

On distingue génralement l'**interface** de l'**implémentation**.

### Type de données abstrait

Un **TDA** (Type de Donnée abstrait) représente l'interface d'une structure de données.
- C'est en fait ce qu'on à vu avec les "templates"

## Le tableaux

### C'est quoi ?

C'est une structure de données qui réunit les des données/valeurs du même type. La taille du tableau doit etre donnue au moment de sa création et ne peut pas être modifier.

**Avantages** :
- On as un accès directe en consultation et modification à chaque case du tableau grâce à son indice.

**Désavantage** :
- Pour agrandir le tableau, il faut en créer un plus grand puis ensuite recopier toutes les valeurs (cout mémoire + complexité)

### en JAVA

```c
int[] t; // déclare un tableau d'entier t et l'initialse à null
int[] tBis = {1, 2, 3, 4}; // déclarer un tableau d'entier tBis et initlise la référence à un espace de 4 valeurs
```

Un tableau en java c'est un type objet et ses valeurs sont des références

## Les listes

Une liste est une suite finie de données de même type.

Elle peut être :
- Soit une liste vide
- Soit un élément suivie d'une liste

### Type abstrait de liste

**Opérations possibles** :

- tester si elle est vide
- La construire par l'ajout d'un élément à une liste existante (éventuellement vide)
- acceder au premier élément
- acceder à la queue de la liste

*Mais aussi* :

- Avoir la taille de la liste
- Tester si un élément est dans la liste

### Implémentation

Il ya deux façon de faire :

- **Listes chainées**, ou on lit les élément avec des noeuds
- **Liste contigüe**, ou la liste est un tableau qu'on agrandi/réduit

#### Liste chainées

```java
public interface Noeud {

    int valeur;
    private Noeud suivant;

    int getValeur() -> return valeur;
    int getSuivant() -> return suivant;
    int setSuivant(Noeud suivant) -> this.suivant = suivant;
}

public class List implements Noeud {

    Noeud tete;

    List(Noeud n) -> this.tete = noeud;

    boolean estVide() -> this.tete == null;
    int tete() -> return this.suivant.getValeur();
    Liste queue() -> return new List(tete.getSuivant());
```

### Liste contigüe

```java
class TabList {
    int[] tab;
    int indiceFin;

    TabList() {
        tab  new int[100];
        indiceFin = -1;
    }

    int tete() -> return this.tab[this.indiceFin];
    TabList queue() -> { /*  retourne une liste de tout les élément sauf la tete */};
}
```

### Conclusion

Plusieurs problèmes :

- Intilialisation d'un tableau de taille 100
- ...


L'implémentation d'une **liste chainée** est :

- La plus dynamique
- Efficace
- La plus facile à implémenter

### Rappel sur les listes chainées

**Exemple avec plusieurs pointeurs** :

```java
Noeud p, q;
p.valeur = 6;
q = p // désormais q et p pointe vers la même valeur
q.valeur = 8 // donc modifie pour p et q

p = null; // p existe plus mais q continue continue de pointé sur la liste !
```

**Autres méthode qu'on ajoute pour les listes chainées** :

```java
// Insère en tee de la liste un nouveau noeud de valeur x
void insererEnTete(int x) {
    Noeud p = new Noeud(x);
    p.SetSuivant(tete)
    tete = p;
}

// tests si un élément est présent dans la liste
boolean contient(int x) {
    Noeud p = this.tete;

    while(p != null){
        if (p.valeur = x)
            return true;

        p = p.suivant;
    }

    return false;
}

// ajoute y après x uniquement si x est présent
void ajouteApres(int x, int y) {
    Noeud p = this.tete;

    while(p != null){

        if (p.valeur = x) {
            Noeud q = new Noeud(y);
            q.SetSuivant(p.getSuivant())
            p.setSuivant(q);
            break;
        }

        p = p.suivant;
    }
}

// inserer x en queue de liste
void insererEnQueue(int x) {

    if (!this.contient(x))
        return;

    if (tete.getValeur() == x) {
        this.tete = new Noeud(x);
        return;
    }

    Noeud p = this.tete;

    while(p != null)
        p = p.suivant;

    Noeud q = new Noeud(x);
    p.suivant = q;
}

void supprimer(int x) {

    if (!this.contient(x))
        return;

    if (tete.getValeur() == x) {
        this.tete = tete.getSuivant();
        return;
    }

    Noeud q = null
    Noeud p = this.tete;

    while(p != null) {
        q = p;
        p = p.suivant;
    }

    q.SetSuivant(null);
}
```

## Les piles


## Les files
