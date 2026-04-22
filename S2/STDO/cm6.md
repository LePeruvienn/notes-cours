
- Tri par dénombrement
- Tri rapide
- Tri par selection

# Codage Huffman

**Compression de données**
- Gain de palce de 20 à 90%
- $C =$ caractère 
- à $c_i \in C$ associe une chaine binaire unique de plus ou moins 8 bits


**Exemple** :

- $C =$ aplhabet
- d: 01, f: 101, m:0110 ..

Codade de **dfd = 1110101**

- Problème ici ! Car **mf = 0110101 = 0110101 = dfd** !!

## Codage préfixe

- Aucun code ne doit être le prefixe d'un autre code,
- Cette règle rend le décodage facile

Exemple

| a | b | c | d |
| -- | -- | -- | -- |
| 01 | 10 | 11 | 00 |

Ici c'est facile à décoder car toute les lettres font la même taille !

Objectif :
- Concevoir le codage et savoir décoder éfficacement

## Exemple (suite) : arbre associé

Le but c'est de faire un arbre binaire afin de trouver éfficacement quelle code correspond à quelle lettre !

- En gros on lit chaque nombre binaire et en fonction de la valeur du bit on déscend dans l'arbre.

```
Arbre équilibrer : 

               .
            0    1
         .         .
       0   1     0   1
     .      .   .      .
    d       a   b       c
```

Mais on peut encore optimisé cela !

- Le but ça sera d'optimiser l'abre en mettant les lettre les plus utilisé le plus proche de la racine
- De cette façon trouver une lettre sera généralement plus rapide !

Donc on va créer un arbre  désiquilibrer qui sera alors plus efficace dans certain cas, et plus lent dans d'autres !

 ```
Arbre désiquilibrer

               .
            0    1
         .         .
        a        0   1
                .      .
               b       c
```

Ici la lettre a est dès que le préfix est 0, donc va on va trouver rapidement les a et plus lent b et c, et si on veut rajouter une lettre uil nous faut un bit en plus.


- On peut alors adapter cette arbre en fonction de ce qu'on veut faire pour rendre


