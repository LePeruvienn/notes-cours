# Test fonctionnel ou Test en boîte noire

## Caractéristiques

Le test fonctionnel

- **Ne nécessite pas** de connaitre la struture interne du système à traitier. 
- **Nécessite**  de connaitre l'interface utilisateur du système et de disposer d'une spécification (formelle ou informelle)

Permet d'assurer la conformité du code par rapport aux conformité du code.

**Avantages**
- Applicable de manière équalvente à plusieurs niveau de tests (unitaire, intégration ..)
- Facile à appliquer sans automatisation

### Paramètre d'entrée


## Test combinatoires

Quand on as plein de paramêtre différents, quand on as plein de combinatoire.

Par exemple L'OS, le navigateur ...

En gros le but est de tester au moins une fois chaque caractéristique.

## Anayse partitionelle

Il ya deux façon de faire l'analyse partitionelle
- Par rapport aux **caractéristiques** (par rapport aux entrées)
- Par rapport aux **comportements** (par rapport aux sorties)


### Base choice

En fait on chosis un cas, puis on fait varier à chaque fois un de ses paramêtre.

Par exemple on as : `a1, a2, b1, b2, b3, c1, c2, c3, c4`

- Base : `a1, b1 ,c1`
- `a1` changed : `a2, b1 ,c1`

- `b1` changed : `a1, b2 ,c1`
- `b1` changed : `a1, b3 ,c1`

- `c1` changed : `a1, b1 ,c2`
- `c1` changed : `a1, b1 ,c3`
- `c1` changed : `a1, b1 ,c4`

En fait on choisis un cas, puis il faut que chaque paramêtre soit au moins représenter une fois.


