# 4. Les classes génériques et anonymes

## Classes génériques

On veut pouvoir faire des classes génériques par rapport à un type.

Par exmple faire une classe `ArrayList` qui permet de créer des listes de n'importe quelle type?

On utilise alors les **classes génériques** !

- Voci l'exemple pour la classe générique `Bag` :

```java
// Classe générique
class Bag<E> { // Ici on remplace `E` par le type donnée
    private E[] elements;
    public Bag() { elements = new E[42]; }
    public E get get(int i) return { element[i]; }
}

// Exemple d'utilisation
Bag<Potion> b;
b = new Bag<>(); // Ici pas besoin de redéfinir le type on l'as déjà fait au dessus
```

- On peut aussi contraindre les type de classe générique par exemple :

```java
// Ici on dit que E, est seulements un type qui hérite de Items !
class Bag<E extends Item> {

    private E[] elements;

    public int getWeight(int i) {
        return elements[i].weight; // ça nous permet alors d'utiliser les fonctions de Item !!
    }
}
```


- Définition de tableau de classes générique :

```java
Truc<String>[] = t = new Truc[10];

// Et pas :
// Truc<String>[] = t = new Truc<>[10]; // < Interdit !
```

## Classes interne

En gros c'est quand on définis **des classes dans des classes** !

- Exemple :

```java
/*public*/ class Englobante { // Acessible selon (public, private, ect)

    /*private*/ class Englobee { // Acessible seulement au mieux à l'accecisibilité e de la classe englobante, et sinon dépend de ce qu'on as mit devant (private public ect ... )
        int a;
        void f() { a = 42; b = 666; }
        // This on avais deux nom d'attribut identitique il faut le préciser avec :
        // void f() { Englobante.this.a = 42 ... }
    }

    private int b;
    private Englobee englobee;
}
```

### Classe interne de méthode 

```java
class Englobante {
    int x;
    void f() {
        int y = 42;
        class Englobee { void g() { x = y; }
        };
        Englobee e = new Englobee();
        e.get();
    }
}
```

## Classes anonyme

Permet de créer des classes **sans nom**.
Utile quand on veut faire ce qu'on as fait avant mais sans donner de nom qui servent à rien en soit.

- Sans class anonyme

```java
void f() {
    class AvecNom extends Bird {
        void fly() { System.out.printn("Fly!") }
    };
    Bird bird = new AvecNom();
}
```
- Avec classe anonyme

```java
void f() {
    Bird bird = new Bird() {
        void fly() { System.out.println("Fly!") }
    }
}
```

- On peut aussi acceder au valeurs de la classe dans laquelle on est utilisé (modifié, get, ect ...) :

```java
class Test {
    int x;
    void f() {
        int a = 42;
        Bird = new Bird { void fly() { x = a; } }
        bird.fly();
    }
}
```

## Fonctions/Expressions lambdas

Le but des fonctions lambda c'est d'écrire des codes encores plus concis !

On peut parler de **fonctions anonyme**. Elle permet de définir une méthode directement à l'endroit ou elle est utilisé.

### Syntaxes

**3 partie** :
- Ensembe de paramètre
- Opérateur `->`
- Le corps de la fonction

**Deux formes possibles** : 
- `(params) -> expression`
- `(params) -> { traitemens }`

### Exemples

```java
() -> 123
() -> { return 123 };

(x, y) -> x + y
(int x, int y) -> x + y

c -> { int s = c.size(); c.clear(); return s; }

() -> { System.out.println("Hello Wolrd") }


// Ou des trucs comme ça c'est stylé 😎
class Carre {

    int width;
    int height;
    int air = () -> width * height;
}
```

