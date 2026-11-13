# TD1

## Exercice 1

```java
public class Conteneur
{
    public Conteneur(int n);
    public void ajouter(Object C, Object O);
    public void retirer(Object C);
    public boolean estVide();
    public int taille();
    public int capacite();
}
```

Pour l'opération ajouter:

1. Déterminez les cas de test en suivant les étapes suivants :

> a) Utlisez la technique **analyse partitionelle basée sur la syntaxe**

**Etape 1** Déterminez les fonctionnalité qui sont testable :
- Ajouter un élément dans le conteneur

**Etape 2** Identifié les paramètre les domaines d'entrée et leurs caractéristiques :
- Conteneur, clef, valeur

**Etape 3** Concevoir les partition / classes d'équivalences :
- Paramètres (caractéristiques) :
  - Clef
  - Valeur
  - Conteneur dans lequel ajouté
- Domaine : n'importe quelle objet JAVA.
- Caractéristiques (entrée possibles) :
  - Clef
    - B1 = Clef null
    - B2 = Clef non null et unique
    - B3 = Clef non null et non unique
  - Valeur
    - B1 = Valeur null
    - B2 = Valeur non null
  - Conteneur
    - B1 = Conteneur plein
    - B2 = Conteneur vide
    - B3 = Conteneur ni vide, ni plein

**Etape 4** Critère de couverture
- A = [ A1, A2, A3 ]
- B = [ B1, B2 ]
- C = [ C1, C2, C3, C4, C5 ]

**Tests aux limites**
- b4 = conteneur avec une place (taille > 2)
- b5 = conteneur avec 1 élemnt (taille > 2)

**All-singles** On cherche la caractéristiques qui est la plus grande
- A1 B1 C1
- A2 B2 C2
- A2 B2 C3
- A3 B1 C4
- A2 B1 C5



