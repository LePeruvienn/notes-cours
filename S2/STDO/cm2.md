# Les piles

Une pile est une structure du données ou les insertion se font toujours du même côté !

- **LIFO** (Last-in, First out)

## Implémentation en java

```java
class Pile {

    List L;
    
    Pile() {
        L = new List();
    }

    boolean estVide() {
        return L.estVideo();
    }

    void empiler(int a) {
        this.L = new List(a, this.L)
    }

    void depiler() {
        // Faire attention si la pile est vide !!
        this.L = this.L.queue();
    }

    int sommet() {
        return this.L.tete();
    }

}
```

## Utilisation en informatique

- Pile d'appel de fonction
- Pile d'annulation d'action dans un éditeur de texte

